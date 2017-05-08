#pragma once

#include "Vec.h"
#include <vector>
#include "Component.h"

class GameObject {
	public:
		/*
		 * Constructor for creating object
		 * @param vertices as Vector with Matrix3GLf
		 */
		GameObject(std::vector<Vec3f> vertices);
		/*
		 * Method for updating the GameObject
		 * @param timeDiff as time difference between updates
		 */
		void update(int deltaTime);
	
		void lateUpdate(int deltaTime);

		/*
		 * Set current position
		 * @param position as new position
		 */
		void setPosition(Vec3f position);
		/*
		 * Rotate the object (add new values to current rotation)
		 * @param rotation to add to the current rotation
		 */
		void rotate(Vec3f rotation);
		/*
		 * Set the current rotation of the object
		 * @param rotation as new rotation
		 */
		void setRotation(Vec3f rotation);
	protected:
		std::vector<Component> _components;

		/*
		 * The current origin of the object
		 */
		Vec3f _position;
		/*
		 * The current rotation of the object
		 */
		Vec3f _rotation;
};
