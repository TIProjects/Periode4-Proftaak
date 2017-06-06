#pragma once
#include "LaneObstacleGenerator.h"
#include "LaneComponent.h"

/**
 * Base class for all patterns
 */
class ObstaclePattern
{
public:
	/**
	 * Default constructor for creating a simple pattern with no speed and first lane
	 */
	ObstaclePattern()
	{
		_speed = 0.0f;
		_newLane = 0;
	}
	/**
	 * Not used destructor
	 */
	virtual ~ObstaclePattern()
	{
		// todo implement destructor
	}
	/**
	 * The change of executing
	 */
	float change = 0.0f;

	/**
	 * Init pattern (create variables from laneObstacleGenerator
	 */

	virtual void Init(LaneObstacleGenerator* lane_obstacle_generator);
	/**
	 * Execute the pattern with the given mesh
	 */

	virtual void Execute(LaneObstacleGenerator* lane_obstacle_generator, Mesh* mesh);


	/**
	 * Get the length before the pattern (to keep clear) todo not used
	 */
	virtual float getLengthBefore(float speedBefore, float lengthLane) {
		return 0.0f;
	};
	/**
	 * Get the reserved length after placing the pattern
	 */
	virtual float getLengthAfter(float speedAfter, float lengthLane) {
		return 0.0f;
	};

	/**
	 * The speed of the pattern (used when adding obstacle)
	 */
	float _speed;
	/**
	 * The new lane to execute the pattern at
	 */
	int _newLane;
};

/**
 * A pattern for placing two obstacles next to eachother (or on ends when no nex)
 */
class TwoPattern : public ObstaclePattern
{
public:
	void Execute(LaneObstacleGenerator* lane_obstacle_generator, Mesh* mesh) override;;


	TwoPattern()
	{
		// 25% change of executing this pattern
		change = 0.25f;
	}
};
/**
 * A pattern for placing a moving obstacle on the lane and reserving the distance after the placement
 */
class MovingPattern : public ObstaclePattern
{
public:


	void Init(LaneObstacleGenerator* lane_obstacle_generator) override;;

	float getLengthAfter(float speedAfter, float lengthLane) override;;

	MovingPattern()
	{
		// 25% change of executing this pattern
		change = 0.25f;
	}
};
