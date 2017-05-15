#pragma once
#include "Vec.h"

class Vertex
{
public:
	/**
	 * \brief Constructor for non-indexed Vertex using Vec3f and Vec2f
	 * \param position the coordinates for this Vertex
	 * \param texCoords the Optional texture coordinates for this object
	 * \param normal the optional normal coordinates for this object
	 */
	explicit Vertex(const Vec3f& position, const Vec2f& texCoords = Vec2f(), const Vec3f& normal = Vec3f());
	/**
	 * \brief Constructor for non-indexed Vertex using seperate values
	 * \param x position
	 * \param y position
	 * \param z position
	 * \param tx texCoord
	 * \param ty texCoord
	 * \param nx normalCoord
	 * \param ny normalCoord
	 * \param nz normalCoord
	 */
	explicit Vertex(float x, float y, float z, float tx = 0, float ty = 0, float nx = 0, float ny = 0, float nz = 0);
	/**
	 * \brief Constructor for creating an empty non-indexed Vertex
	 */
	Vertex();

	/**
	 * \brief The data of the vertex
	 */
	union
	{
		struct
		{
			float _x, _y, _z; // Position
			float _tx, _ty; // TexCoords
			float _nx, _ny, _nz; // NormalCoord
		};
		float _v[8]; // Array version
	};
};
