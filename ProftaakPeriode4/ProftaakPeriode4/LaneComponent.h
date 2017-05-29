#pragma once
#include "GameObject.h"
#include "Mesh.h"
#include <deque>

class LaneComponent : public Component
{
public:
	/**
	* The constructor for creating a Lane
	* Fills the list with random Meshes (the given lengthAmount)
	* \param lengthAmount the amount of blocks in the lane
	* \param meshes the possible meshes inside the lane
	*/
	LaneComponent(int lengthAmount, std::vector<Mesh*> meshes);

	/**
	* The destructor (but not used)
	* TODO implement destructor
	*/
	~LaneComponent() {}

	/**
	* Draw the Lane
	*/
	void Draw();

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

	/**
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
	* For updating the LaneObstacleComponent
	* \param deltatime the time between the updates
	*/
	void Update(float deltatime) override;

	/*
	* The speed that are moved every some time
	*/
	float _speed = 9.0f; // do not change this one
};
