#include "PlayerComponent.h"
#include "CollisionComponent.h"
#include "Input.h"
#include "GameObject.h"

PlayerComponent::PlayerComponent(int laneIndex, int laneCount, LifeBar * lifeBar, Image * gameOverScreen, Model * model, bool useOpenCV)
: Component(PLAYER_COMPONENT)
{
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
}

void PlayerComponent::Update(float deltaTime)
{
	if(_targetPosition.x != _parent->_position.x)
	{
		float diff = _targetPosition.x - _parent->_position.x;
		if(diff <= 0.5 && diff >= -0.5f)
		{
			_parent->_position.x = _targetPosition.x;
		} else
		{
			_parent->_position.x += diff * 0.025f;
		}
	}

	CollisionComponent * collider = static_cast<CollisionComponent*>(_parent->GetComponent(COLLISION_COMPONENT));
	if(collider != nullptr)
	{
		if(collider->_collided.size() > 0)
		{
			if (!_collided)
			{
				_collided = true;
				int hp = _lifeBar->Decrement();
				if (hp <= 0)
				{
					_gameOverScreen->Show();
					_model->_gameOver = true;
				}
			}
		} else
		{
			_collided = false;
		}
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