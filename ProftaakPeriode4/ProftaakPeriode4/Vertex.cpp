#include "Vertex.h"

Vertex::Vertex(const Vec3f& position, const Vec2f& texCoords, const Vec3f& normal)
{
	_x = position.x;
	_y = position.y;
	_z = position.z;

	_tx = texCoords.x;
	_ty = texCoords.y;

	_nx = normal.x;
	_ny = normal.y;
	_nz = normal.z;
}

Vertex::Vertex(float x, float y, float z, float tx, float ty, float nx, float ny, float nz)
{
	_x = x;
	_y = y;
	_z = z;
	_tx = tx;
	_ty = ty;
	_nx = nx;
	_ny = ny;
	_nz = nz;
}
Vertex::Vertex()
{
	for (int i = 0; i < sizeof(_v) / sizeof(float); i++) {
		_v[i] = 0.0f;
	}
}
