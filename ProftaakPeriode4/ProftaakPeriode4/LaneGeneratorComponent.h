#pragma once
#include "DrawComponent.h"
#include "Mesh.h"
#include <queue>
#include <ctime>
#include "LaneObstacleGenerator.h"

/**
 * \brief Class for generating and showing lanes
 */
class LaneGeneratorComponent :
	public DrawComponent
{
public:
	/**
	 * \brief Constructor for creating a LaneGaneratorComponent
	 * \param laneAmount The amount of lanes to show
	 * \param laneSize the amount of blocks inside the lane (the length)
	 * \param meshes The meshes that are chosen randomly over all the lanes
	 */
	LaneGeneratorComponent(int laneCount, int laneSize, std::vector<Mesh*> meshes);

	/**
	 * \brief Destructor
	 * todo implement
	 */
	~LaneGeneratorComponent();
	
	/**
	 * \brief Draw the lanes
	 */
	void Draw() override;

	/**
	 * \brief Update the laneLogics (move the lanes)
	 * \param deltaTime The difference between the updates
	 */
	void Update(float deltaTime) override;

	/**
	 * \brief For placing a Obstacle fully random
	 * Places on a random place on a random lane
	 * \param mesh the Mesh that will be added as Obstacle
	 */
	void PlaceObstacleFullyRandom(Mesh* mesh);

	std::vector<GameObject*> _obstacles;
private:
	GameObject * _player;


	/*
	 * The lanes that are shown in the component
	 * Are filled in constructor (given amount)
	 */
	vector<GameObject*> _lanes;
	/*
	 * The space between the lanes
	 */
	float _spaceBetween = 2.0f;
};

