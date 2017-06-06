#pragma once
#include "LaneObstacleGenerator.h"
#include "LaneComponent.h"


class ObstaclePattern
{
public:
	ObstaclePattern()
	{
		
	}

	float change = 0.0f;

	virtual void Init(LaneObstacleGenerator * lane_obstacle_generator)
	{
		_speed = *lane_obstacle_generator->_speed;
	};


	virtual void Execute(LaneObstacleGenerator * lane_obstacle_generator)
	{
		lane_obstacle_generator->addObstacle(_newLane, lane_obstacle_generator->getRandomGameObject(), _speed);
	};

	virtual float getLengthBefore(float speedBefore, float lengthLane) {
		return 0.0f;
	};
	virtual float getLengthAfter(float speedAfter, float lengthLane) {
		return 0.0f;
	};
	float _speed;
	int _newLane;
};


class TwoPattern : public ObstaclePattern
{

public:
	void Execute(LaneObstacleGenerator* lane_obstacle_generator) override{
		int otherLane = _newLane + 1;
		if (otherLane >= lane_obstacle_generator->_lanes->size())
			otherLane = 0;
		for (int i = 0; i < lane_obstacle_generator->_lanes->size(); i++) {
			if (_newLane != i && otherLane != i)
				lane_obstacle_generator->laneAmountSkipped[i] += lane_obstacle_generator->maxSkip;
			else 
				lane_obstacle_generator->addObstacle(i, lane_obstacle_generator->getRandomGameObject());
		}
	};


	TwoPattern()
	{
		change = 0.25f;
	}
};

class MovingPattern : public ObstaclePattern
{
public:


	void Init(LaneObstacleGenerator* lane_obstacle_generator) override
	{
		_speed = (rand() % (int)(*lane_obstacle_generator->_speed - 5.0f)) + 5.0f;
//
//		GameObject * lane_object = (*lane_obstacle_generator->_lanes)[newLane];
//		LaneComponent * lane_component = dynamic_cast<LaneComponent*>(lane_object->GetComponent(LANE_COMPONENT));
//		float total_lane_length = lane_component->getLength();
////		float time_till_end = total_lane_length / lane_obstacle_generator->_speed;
//		_distance = ((total_lane_length/_speed)- (total_lane_length/lane_obstacle_generator->_speed))*lane_obstacle_generator->_speed;
//		std::cout << _distance << " DISTANCE!" << std::endl;
//		_distance /= 3.0;
	};


	float getLengthBefore(float speedBefore, float lengthLane) override{
//		float distance = ((lengthLane / _speed) - (lengthLane / speedBefore))*speedBefore / 3.0f;
//		std::cout << "BEFORE: " << distance << std::endl;
//		if (distance > 0.0f)
//			return distance;
		return 0.0f;
	};

	float getLengthAfter(float speedAfter, float lengthLane) override{

		float dist1 = lengthLane / _speed;
		float dist2 = lengthLane / speedAfter;
		float dist3 = dist1 - dist2;
		float dist4 = dist3*speedAfter;
		float distance = dist4;
		std::cout << "AFTER: " << distance << std::endl;
		if(distance > 0.0f)
			return distance;
		return 2.0f;
	};

	MovingPattern()
	{
		change = 0.10f;
	}
};
