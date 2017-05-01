#pragma once
#include <vector>
#include "GameObject.h"

class Lane
{
public:
	// List of gameObjects
	
	// Add a GameObject to the lane
	// @param GameObject *: The pointer to the gameObject wich will be added to the lane
	// @return bool: true if successful
	bool addObject();

	// Remove a GameObject from the lane
	// @param GameObject *: The pointer to the gameObject wuch will be removed from the lane
	// @return bool: true if the object was succesfully removed
	bool removeObject();
private:
	std::vector<GameObject> _gameObjects; // List of pointers to the every GameObject on the lane
};

class Lanes
{
public:
	Lanes(Lane * lanes, int count);

	void update();

	int _count; // The amount of lanes
	Lane * _lanesPtr; // Pointer to an array of all the lanes
private:

};