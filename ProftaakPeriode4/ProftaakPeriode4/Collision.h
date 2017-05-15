#pragma once
#include "GameObject.h"

namespace Collision
{
	/**
	 * \brief Turn multiCollide on or of
	 * if it is on objects will be able to collide with multiple other objecs
	 * if it is off objects will only be able to collide with one other object.
	 * turning it off can increase performance.
	 * \param value true for on, false for off
	 */
	void SetMultiCollide(bool value);
	/**
	 * \brief Check for every GameObject in a list that has a CollisionComponent wheter it is colliding
	 * \param gameObjects list of GameObjects which will be checked.
	 */
	void CheckCollision(std::vector<GameObject*> gameObjects);
}
