#include "LaneObstacleComponent.h"
#include "GameObject.h"

LaneObstacleComponent::LaneObstacleComponent(int laneIndex) : Component(LANE_OBSTACLE_COMPONENT)
{
	_laneIndex = laneIndex;
}

void LaneObstacleComponent::Update(float deltaTime)
{
	_parent->_position.z += _speed * deltaTime;
}

