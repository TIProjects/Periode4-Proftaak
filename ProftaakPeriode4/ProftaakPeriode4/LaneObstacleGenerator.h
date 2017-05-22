#pragma once
#include <vector>
#include "LaneGeneratorComponent.h"
#include "GameObject.h"
#include "Component.h"


class LaneObstacleGenerator
{
	LaneObstacleGenerator()
	{
	}

private:
	float _minimalDistanceBetween = 1.0f;
	float _maximalDistanceBetween = 5.0f;

public:

	std::vector<GameObject*> _gameObjects;
	float _lengthMovedSince = 0.0f;



	std::vector<GameObject*> getObstacles(int laneIndex)
	{
		std::vector<GameObject*> objects;
		for (GameObject * game_object : _gameObjects)
		{
//			LaneDrawComponent * component = game_object->GetComponent(LANE_COMPONENT);
//			if (component != nullptr && component->_laneIndex == laneIndex) {
//				objects.push_back(game_object);
//			}
		}
		return objects;
	}

	void PlaceRandomAt(float target)
	{
		
	}

	void Update(float lengthMoved)
	{
		_lengthMovedSince += lengthMoved;

		float randomAdd = float(rand() % int(_maximalDistanceBetween - _lengthMovedSince));
		if (_lengthMovedSince >= _maximalDistanceBetween)
		{
			PlaceRandomAt(_lengthMovedSince);
		}
		else if(_lengthMovedSince + randomAdd >= _minimalDistanceBetween){
			PlaceRandomAt(_lengthMovedSince + randomAdd);
		}
	}
};
