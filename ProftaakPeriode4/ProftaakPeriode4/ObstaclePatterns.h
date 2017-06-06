#pragma once
#include "LaneObstacleGenerator.h"
#include "LaneComponent.h"


class ObstaclePattern
{
public:
	ObstaclePattern()
	{
		_speed = 0.0f;
		_newLane = 0;
	}

	virtual ~ObstaclePattern()
	{
		// todo implement destructor
	}

	float change = 0.0f;

	virtual void Init(LaneObstacleGenerator* lane_obstacle_generator);


	virtual void Execute(LaneObstacleGenerator* lane_obstacle_generator, Mesh* mesh);

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
	void Execute(LaneObstacleGenerator* lane_obstacle_generator, Mesh* mesh) override;;


	TwoPattern()
	{
		change = 0.25f;
	}
};

class MovingPattern : public ObstaclePattern
{
public:


	void Init(LaneObstacleGenerator* lane_obstacle_generator) override;;

	float getLengthAfter(float speedAfter, float lengthLane) override;;

	MovingPattern()
	{
		change = 0.25f;
	}
};
