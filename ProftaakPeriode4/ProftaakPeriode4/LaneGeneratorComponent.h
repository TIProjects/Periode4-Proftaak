#pragma once
#include "DrawComponent.h"
#include "Mesh.h"
#include <queue>
#include <ctime>

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
	LaneGeneratorComponent(int laneCount, int laneSize, std::vector<Mesh*> meshes, Mesh * playerMesh);
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

	/*
	* The lanes that are shown in the component
	* Are filled in constructor (given amount)
	*/
	vector<GameObject*> _lanes;

	vector<GameObject*> _obstacles;
	GameObject * _player;

private:
	
	/*
	 * The space between the lanes
	 */
	float _spaceBetween = 2.0f;
};

