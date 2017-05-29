#pragma once
#include <vector>
#include "GameObject.h"
#include "Component.h"
#include "LaneObstacleComponent.h"
#include "LaneGeneratorComponent.h"
#include "LaneComponent.h"


class LaneObstacleGenerator : public Component
{
	


public:
	LaneObstacleGenerator() : Component(LANE_OBSTACLE_GENERATOR)
	{
	}


	float _lengthMovedSince = 0.0f;
	float _minimalDistanceBetween = 1.0f;
	float _maximalDistanceBetween = 5.0f;

	int _lanes = 3;
	std::vector<GameObject*> _obstacles;
	

	void PlaceRandomAt(float target)
	{
		
	}


	void Update(float nanotime) override
	{
//		_lengthMovedSince += nanotime;
//
//		float randomAdd = float(rand() % int(_maximalDistanceBetween - _lengthMovedSince));
//		if (_lengthMovedSince >= _maximalDistanceBetween)
//		{
//			PlaceRandomAt(_lengthMovedSince);
//		}
//		else if(_lengthMovedSince + randomAdd >= _minimalDistanceBetween){
//			PlaceRandomAt(_lengthMovedSince + randomAdd);
//		}
	}
};
