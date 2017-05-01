#pragma once
#include <GL/freeglut.h>


class Matrix3GLf {
public:
	Matrix3GLf(GLfloat x, GLfloat y, GLfloat z);
	Matrix3GLf();

	GLfloat x, y, z;
};

// Constructor
// @param x, y, z: The x y and z values for the matrix
inline Matrix3GLf::Matrix3GLf(GLfloat x, GLfloat y, GLfloat z)
{
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}

}

// Default constructor
// Initialises all variables as 0
inline Matrix3GLf::Matrix3GLf()
{
	x = 0;
	y = 0;
	z = 0;
}

