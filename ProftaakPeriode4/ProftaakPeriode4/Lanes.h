//#pragma once
//#include <vector>
//#include <GL/freeglut.h>
//#include "GameObject.h"
//
//class Lane : public GameObject
//{
//public:
//	Lane(std::vector<Vec3f> _vertices);
//
//	// Add a GameObject to the lane
//	// @param GameObject *: The pointer to the gameObject wich will be added to the lane
//	// @return bool: true if successful
//	bool addObject(GameObject * gameObject);
//
//	// Remove a GameObject from the lane
//	// @param GameObject *: The pointer to the gameObject wuch will be removed from the lane
//	// @return bool: true if the object was succesfully removed
//	bool removeObject(GameObject * gameObject);
//private:
//	// Find out the index of an object in the vector
//	// @param GameObject *: the pointer to the GameObject which will be searched
//	// @return int: The index of the GameObject, or -1 if it's not present
//	int isInLane(GameObject * gameObject);
//
//	// List of pointers to the every GameObject on the lane
//	std::vector<GameObject *> _gameObjects; 
//};
//
//class Lanes 
//{
//public:
//	// Constructor
//	// @param int count: The amount of lanes
//	Lanes(int count);
//
//	// Update the lanes
//	void UpdateView();
//
//	// The amount of lanes
//	int _count; 
//	
//	// vector of all the lanes
//	std::vector<Lane> _lanes; 
//private:
//
//};
