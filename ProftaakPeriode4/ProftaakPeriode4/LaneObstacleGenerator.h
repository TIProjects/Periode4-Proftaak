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
	LaneObstacleGenerator(std::vector<Mesh*> obstacleModelsAsteroid, std::vector<Mesh*> obstacleModelsNormal, std::vector<Mesh*> obstacleModelsPowerUp);
	/*
	 * Add a obstacle to the lane on the given lane with the given mesh and a speed
	 * When speed = -1 then the lane speed is used!
	 */
	void addObstacle(int laneIndex, Mesh* mesh_object, float speed = -1.0f);
	

	/**
	 * Get a new random mesh object from all meshes
	 */
	Mesh * getRandomMeshObject();

	/**
	 * \brief Keep score of distance already moved since last placement
	 */
	std::vector<float> _lengthMovedSince;
	/**
	 * \brief The minimal distance between two placements (used for slow start)
	 */
	float _minimalDistanceBetween = 7.5f;
	float _maximalDistanceBetween = 7.5f;
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

	std::vector<Mesh*> _obstacleModelsNormal;
	std::vector<Mesh*> _obstacleModelsAsteroid;
	std::vector<Mesh*> _obstacleModelsPowerUp;
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
