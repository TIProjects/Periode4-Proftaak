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
	if(_laneSpeed != nullptr)
		_parent->_position.z += _speed**_laneSpeed * deltaTime;
}

