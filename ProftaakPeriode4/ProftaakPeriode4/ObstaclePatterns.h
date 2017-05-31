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

	virtual void Init(LaneObstacleGenerator * lane_obstacle_generator, int newLane){};

	virtual void Execute(LaneObstacleGenerator * lane_obstacle_generator, int newLane) = NULL;

	virtual float getLength() {
		return 0.0f;
	};
};


class TwoPattern : public ObstaclePattern
{

public:
	void Execute(LaneObstacleGenerator* lane_obstacle_generator, int newLane) override{
		int otherLane = newLane + 1;
		if (otherLane >= lane_obstacle_generator->_lanes->size())
			otherLane = 0;
		Mesh * mesh = lane_obstacle_generator->_meshes[0];
		for (int i = 0; i < lane_obstacle_generator->_lanes->size(); i++) {
			if (newLane != i && otherLane != i)
				lane_obstacle_generator->laneAmountSkipped[i] += lane_obstacle_generator->maxSkip;
			else 
				lane_obstacle_generator->addObstacle(i, mesh);
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


	void Init(LaneObstacleGenerator* lane_obstacle_generator, int newLane) override
	{
		_newLane = newLane;
		_speed = (rand() % (int)(lane_obstacle_generator->_speed - 2.0f)) + 2.0f;

		GameObject * lane_object = (*lane_obstacle_generator->_lanes)[newLane];
		LaneComponent * lane_component = dynamic_cast<LaneComponent*>(lane_object->GetComponent(LANE_COMPONENT));
		float total_lane_length = lane_component->getLength();
		float time_till_end = total_lane_length / lane_obstacle_generator->_speed;
		_distance = time_till_end*_speed;
		std::cout << _distance << " DISTANCE!" << std::endl;
		
	};

	float getLength() override{
		return _distance;
	};

	void Execute(LaneObstacleGenerator* lane_obstacle_generator, int newLane) override
	{
		Mesh * mesh = lane_obstacle_generator->_meshes[0];
		

		for (int i = 0; i < lane_obstacle_generator->_lanes->size(); i++) {
			lane_obstacle_generator->addObstacle(i, mesh, _speed);
		}
	};

	MovingPattern()
	{
		change = 0.25f;
	}

private:
	int _newLane;
	float _speed;
	float _distance;
};
