#pragma once
#include "DrawComponent.h"
#include "Mesh.h"
#include <queue>
#include <ctime>
// The speed of the objects moving (both LaneObstacle and Lane)
#define SPEED 9.0f 


/**
 * \brief Class for obstacles on a lane
 */
class LaneObstacle
{
public:
	
	/**
	 * \brief Constructor for a LaneObstacle
	 * \param mesh The mesh to draw on the lane
	 * \param position The relative position on the lane
	 * 
	 * The _position is between 0.0f and 1.0f (end and start of lane)
	 * The _position is lowered when the lane is moving
	 */
	LaneObstacle(Mesh* mesh, float position);
	/**
	 * The relative position on the lane
	 * (Between 0.0f and 1.0f)
	 * WARNING! Drawn outside lane when given > 1.0 or < 0.0!
	 */
	float _position;
	/*
	 * The speed of the moving objects
	 */
	float _speed = SPEED; // do not change

	/*
	 * The amount already moved 
	 */

	float _lengthMoved = 0.0f;
	/*
	 * The Mesh that will be drawn
	 */
	Mesh* _mesh;

};

class Lane
{
public:
	/**
	 * The constructor for creating a Lane
	 * Fills the list with random Meshes (the given lengthAmount)
	 * \param lengthAmount the amount of blocks in the lane
	 * \param meshes the possible meshes inside the lane
	 */
	Lane(int lengthAmount, std::vector<Mesh*> meshes);

	/**
	 * The destructor (but not used)
	 * TODO implement destructor
	 */
	~Lane(){}

	/**
	 * Draw the Lane on a given width 
	 * \param width the width-offset the lane will be drawn on
	 * TODO check if width is needed (and can be replaced)
	 * : Width is given because i don't want a duplicate translate (for shifting in width and between all blocks)
	 */
	void Draw(float width);

	/**
	 * Function for getting a new Random mesh
	 * \return Mesh random mesh-ptr
	 */
	Mesh* RandomMesh();
	/**
	 * Get the total width of the lane (used when different 3D models are given)
	 * todo test with multiple 3d models to be sure the alignment is correct
	 * \return the Maximum width of the lane
	 */
	float getWidth();

	/**
	 * For getting the total length of the lane
	 * \return the total length of the lane
	 */
	float getLength();

	/*
	 * The meshes that are randomly chosen (loaded in constructor)
	 */
	std::vector<Mesh*> _meshes;


	/**
	 * the amount already moved (automaticly lowered)
	 */
	float _lengthMoved = 0.0f;

	/**
	 * The dequeue which contains the different meshes that are shown in the lane
	 */
	deque<Mesh*> _queue;
	/**
	 * The obstacles on the lane (is empty on default)
	 */
	vector<LaneObstacle*> _obstacles;


	/**
	 * For updating the LaneObstacle
	 * \param deltatime the time between the updates
	 */
	void Update(float deltatime);

	/*
	* The speed that are moved every some time
	*/
	float _speed = SPEED; // do not change this one
};


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
	LaneGeneratorComponent(int laneAmount, int laneSize, std::vector<Mesh*> meshes);

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

private:
	/*
	 * The lanes that are shown in the component
	 * Are filled in constructor (given amount)
	 */
	vector<Lane*> _lanes;
	/*
	 * The space between the lanes
	 */
	float _spaceBetween = 2.0f;
};

