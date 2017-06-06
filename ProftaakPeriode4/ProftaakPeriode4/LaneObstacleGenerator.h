#pragma once
#include <vector>
#include "GameObject.h"
#include "Component.h"
#include "MeshDrawComponent.h"


class LaneObstacleGenerator : public Component
{
	


public:
	
	/**
	 * \brief 
	 * \param meshes 
	 */
	LaneObstacleGenerator(std::vector<GameObject*> obstacleModels);


	/**
	 * \brief 
	 * \param laneIndex 
	 * \param mesh 
	 * \param speed 
	 */
	void addObstacle(int laneIndex, GameObject* game_object, float speed = 0.0f);

	GameObject * getRandomGameObject();

	static float* gameObjectSize(GameObject* game_object);
	/**
	 * \brief Keep score of distance already moved since last placement
	 */
	std::vector<float> _lengthMovedSince;
	/**
	 * \brief The minimal distance between two placements (used for slow start)
	 */
	float _minimalDistanceBetween = 5.0f;
	float _maximalDistanceBetween = 5.0f;
	/**
	 * \brief the speed of the lanes (todo replace with speed of LaneGenerator when changed by @gijs
	 */
    float * _speed;//&component->_speed;
	/**
	 * The lastLane that is placed
	 */
	int lastLane = 0;
	/**
	 * The list of lanes from the LaneGenerator (used for placing new obstacles) 
	 * The pointer of the vector from LaneGenerator
	 */
	std::vector<GameObject*> * _lanes;
	/**
	 * The list of obstacles already placed
	 * The pointer of the obstacles from LaneGenerator
	 */
	std::vector<GameObject*> * _obstacles;
	std::vector<GameObject*> _obstacleModels;
	/**
	 * List of skipped amount 
	 * The size is equal to the amount of lanes in _lanes
	 * Is altered when a new obstacle is placed
	 * Is to make sure that there are no empty lanes
	 */
	std::vector<int> laneAmountSkipped;
	/**
	 * The max amount of empty places on a lane
	 */
	int maxSkip = 3;

	/**
	 * Updating the obstacles (looking for placing obstacle)
	 */
	void Update(float nanotime) override;

	int getNewLane();
};
