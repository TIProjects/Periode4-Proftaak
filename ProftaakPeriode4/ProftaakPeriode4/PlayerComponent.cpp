#include "PlayerComponent.h"
#include "CollisionComponent.h"
#include "Input.h"
#include "GameObject.h"
#include "VisionComponent.h"
#include "CameraComponent.h"
#include "LaneObstacleComponent.h"
#include "PowerUpComponent.h"

PlayerComponent::PlayerComponent(int laneIndex, int laneCount, LifeBar * lifeBar, Image * gameOverScreen, Text * powerUp ,Model * model, Sound * collisionSound, Sound * deathSound ,bool useOpenCV)
: Component(PLAYER_COMPONENT)
{
	_collided = false;
	_powerUp = powerUp;
    _isInvinsible = false;
	_deathSound = deathSound;
	_collisionSound = collisionSound;
	_laneCount = laneCount;
	_isCrouching = false;
	_laneIndex = laneIndex;
	_useOpenCV = useOpenCV;
	_keyReleased = true;
	_lastLane = _laneIndex;
	_lifeBar = lifeBar;
	_hitTime = 0.0f;
	_model = model;
	_gameOverScreen = gameOverScreen;
	_isJumping = false;
}

void PlayerComponent::Update(float deltaTime)
{
	if(_targetPosition.x != _parent->_position.x)
	{
		float diff = _targetPosition.x - _parent->_position.x;
		if(diff <= 0.01f && diff >= -0.01f)
		{
			_parent->_position.x = _targetPosition.x;
		} else
		{
			float speed = diff * deltaTime * 2.0f;
			_parent->_rotation.z += speed * 10.0f;
			_parent->_position.x += speed;

			// Use the Camera GameObject to create a view
			for (GameObject * gameObject : _model->_gameObjects)
			{
				CameraComponent * camera = dynamic_cast<CameraComponent *>(gameObject->GetComponent(CAMERA_COMPONENT));
				if (camera != nullptr)
				{
					// Found camera, apply it's view and stop looping the list
					gameObject->_position.x += speed * 0.50f;
					break;
				}
			}
		}
	}

	

	CollisionComponent * collider = static_cast<CollisionComponent*>(_parent->GetComponent(COLLISION_COMPONENT));

	if (!_isInvinsible && collider != nullptr && collider->_collided.size() > 0)
	{
		if (!_collided)
		{
			GameObject * otherObj = collider->_collided.at(0);
			if (otherObj != nullptr)
			{
				if(otherObj->GetComponent(ROTATE_COMPONENT) != nullptr)
				{
					PowerUpComponent * powerUp = dynamic_cast<PowerUpComponent*>
						(_parent->GetComponent(POWER_UP_COMPONENT));
					if(powerUp != nullptr)
					{
						int number = rand() % 5;
						PowerUp * actualPowerUp = powerUp->GetPowerUp(PowerUpId(number));
						actualPowerUp->Activate();
						_powerUp->Update(actualPowerUp->_name);
					}
					_collided = true;

				} else
				{
					_collided = true;
					int hp = _lifeBar->Decrement();
					_collisionSound->Restart();
					if (hp <= 0)
					{
						_deathSound->Play();
						_model->_backgroundMusic->Pause();
						_gameOverScreen->Show();
						_model->_gameOver = true;
						VisionComponent *vision = dynamic_cast<VisionComponent *>(_parent->GetComponent(VISION_COMPONENT));
						if (vision != nullptr)
						{
							vision->stopVisionThread();
						}
					}
				}
			}
		}
	}
	else
	{
		_collided = false;
	}

	if(_useOpenCV)
		OpenCVUpdate(deltaTime);
	else
		KeyBoardUpdate(deltaTime);
}

void PlayerComponent::MovePlayer(float xCoord)
{
	_targetPosition.x = xCoord;
}

void PlayerComponent::OpenCVUpdate(float deltaTime)
{
	VisionComponent *vision = dynamic_cast<VisionComponent *>(_parent->GetComponent(VISION_COMPONENT));
	if (vision != nullptr)
	{
		vision->GetControls(&_laneIndex, &_isCrouching, &_isJumping);
	}
	// TODO Update laneIndex using openCV
}

void PlayerComponent::KeyBoardUpdate(float deltaTime)
{
	const bool * keys = Keyboard::GetKeyboard();

	if (_keyReleased && keys['a'] && _laneIndex - 1 >= 0) {
		_lastLane = _laneIndex;
		_laneIndex -= 1;
		_keyReleased = false;
	}
	if (_keyReleased && keys['d'] && _laneIndex + 1 < _laneCount) {
		_lastLane = _laneIndex;
		_laneIndex += 1;
		_keyReleased = false;
	}
	if (!keys['d'] && !keys['a']) _keyReleased = true;

	_isCrouching = keys['s'];
}