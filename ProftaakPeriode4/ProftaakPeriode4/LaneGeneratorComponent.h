#pragma once
#include "DrawComponent.h"
#include "Mesh.h"

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
	 * \param mesh The mesh that will be drawn on the lanes
	 */
	LaneGeneratorComponent(int laneAmount, Mesh * mesh);

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

private:
	// the mesh to show todo multiple meshes showed randomly
	Mesh * _mesh;
	// the amount of lanes
	int _laneAmount;
	// the amount already moved (automaticly lowered)
	float _lengthMoved;
	// the movement speed
	float _speed = 0.0f;  // todo test accurate speed
	// the space between the lanes
	float _spaceBetween = 1.0f;
	// the amount of lanes (in length) 
	int _lengthAmount = 20; // todo refactor to lengthamount as distance and not amount
};

