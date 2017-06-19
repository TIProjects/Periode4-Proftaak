#include "ObstaclePatterns.h"
#include <iostream>

void ObstaclePattern::Init(LaneObstacleGenerator* lane_obstacle_generator)
{
//	_speed = lane_obstacle_generator->_speed;
}

void ObstaclePattern::Execute(LaneObstacleGenerator* lane_obstacle_generator, Mesh* mesh)
{
	
	lane_obstacle_generator->addObstacle(_newLane, mesh, _speed);
}

void TwoPattern::Execute(LaneObstacleGenerator* lane_obstacle_generator, Mesh* mesh)
{
	int otherLane = _newLane + 1;
	if (otherLane >= lane_obstacle_generator->_lanes->size())
		otherLane = 0;
	for (int i = 0; i < lane_obstacle_generator->_lanes->size(); i++)
	{
		if (_newLane != i && otherLane != i)
			lane_obstacle_generator->laneAmountSkipped[i] += lane_obstacle_generator->maxSkip;
		else
			lane_obstacle_generator->addObstacle(i, mesh);
	}
}

void MovingPattern::Init(LaneObstacleGenerator* lane_obstacle_generator)
{
	_speed = ((rand() % 50) + 50) / 100.0f;
}

float MovingPattern::getLengthAfter(float speedAfter, float lengthLane, LaneObstacleGenerator* obstacle_generator)
{
	float dist1 = lengthLane / (_speed**obstacle_generator->_speed);
	float dist2 = lengthLane / speedAfter;
	float dist3 = dist1 - dist2;
	float dist4 = dist3 * speedAfter;
	float distance = dist4;
	if (distance > 0.0f)
		return distance;
	return 0.0f;
}
