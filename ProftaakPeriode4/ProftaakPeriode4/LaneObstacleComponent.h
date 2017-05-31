#pragma once

#include "Component.h"

class Vec3f;

/**
* \brief Class for obstacles on a lane
*/
class LaneObstacleComponent : public Component
{
public:

	/**
	* \brief Constructor for a LaneObstacleComponent
	* \param position The relative position on the lane
	*
	* The _position is between 0.0f and 1.0f (end and start of lane)
	* The _position is lowered when the lane is moving
	*/
	explicit LaneObstacleComponent(int laneIndex);

	void Update(float deltaTime) override;

	int _laneIndex;
	/*
	* The speed of the moving objects
	*/
    float * _speed;
	/*
	* The amount already moved
	*/
	float _lengthMoved = 0.0f;
};