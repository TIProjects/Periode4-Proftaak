#pragma once

#include "Matrix3GLf.h"
#include <vector>

class GameObject {
	public:
		/*
		 * Constructor for creating object
		 * @param vertices as Vector with Matrix3GLf
		 */
		GameObject(std::vector<Matrix3GLf> vertices);
		/*
		 * Method for updating the GameObject
		 * @param timeDiff as time difference between updates
		 */
		void update(int timeDiff);
		/*
		 * Method for moving the position with a magnitude in a given direction
		 * @param direction as Matrix with the % of direction in a given way
		 * @param magitude as amount of move
		 */
		void move(Matrix3GLf direction, GLfloat magnitude);
		/*
		 * Set current position
		 * @param position as new position
		 */
		void setPosition(Matrix3GLf position);
		/*
		 * Rotate the object (add new values to current rotation)
		 * @param rotation to add to the current rotation
		 */
		void rotate(Matrix3GLf rotation);
		/*
		 * Set the current rotation of the object
		 * @param rotation as new rotation
		 */
		void setRotation(Matrix3GLf rotation);
	protected:	
		/*
		 * Vector of all vertices of the object as positions
		 */
	    std::vector<Matrix3GLf> _vertices;
		/*
		 * The current origin of the object
		 */
		Matrix3GLf _position;
		/*
		 * The current rotation of the object
		 */
		Matrix3GLf _rotation;
};
