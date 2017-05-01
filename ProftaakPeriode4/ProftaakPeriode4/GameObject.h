#pragma once
#include "Matrix3GLf.h"
#include <vector>


class GameObject {
	public:
		GameObject(std::vector<Matrix3GLf> vertices);
		void update(int timeDiff);

		void move(Matrix3GLf direction, GLfloat magnitude);
		void setPosition(Matrix3GLf position);

		void rotate(Matrix3GLf rotation);
		void setRotation(Matrix3GLf rotation);

	
	protected:	
	    std::vector<Matrix3GLf> _vertices;
		Matrix3GLf _position;
		Matrix3GLf _rotation;
};
