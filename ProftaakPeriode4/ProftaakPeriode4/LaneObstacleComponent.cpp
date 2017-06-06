#include "LaneObstacleComponent.h"
#include "GameObject.h"

LaneObstacleComponent::LaneObstacleComponent(int laneIndex) : Component(LANE_OBSTACLE_COMPONENT)
{
	_speed = -1.0f;
	_laneSpeed = nullptr;
	_laneIndex = laneIndex;
}

void LaneObstacleComponent::Update(float deltaTime)
{
	float speed = _speed;

	if (_speed != -1.0f)
		speed = _speed;
	else if(_laneSpeed != nullptr)
		speed = *_laneSpeed;

	if(speed != -1.0f)
		_parent->_position.z += speed * deltaTime;
}

