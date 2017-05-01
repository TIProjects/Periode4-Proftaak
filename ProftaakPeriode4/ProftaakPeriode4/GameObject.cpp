#include "GameObject.h"


GameObject::GameObject(std::vector<Matrix3GLf> vertices)
{
	_vertices = vertices;
	_position.x = 0.0f;
	_position.y = 0.0f;
	_position.z = 0.0f;
	
	_rotation.x = 0.0f;
	_rotation.y = 0.0f;
	_rotation.z = 0.0f;
}

void GameObject::update(int timeDiff)
{

}

void GameObject::move(Matrix3GLf direction, GLfloat magnitude)
{
	_position.x += direction.x * magnitude;
	_position.y += direction.y * magnitude;
	_position.z += direction.z * magnitude;
}

void GameObject::setPosition(Matrix3GLf position)
{
	_position = position;
}

void GameObject::rotate(Matrix3GLf rotation)
{
	_rotation.x += rotation.x;
	_rotation.y += rotation.y;
	_rotation.z += rotation.z;
}

void GameObject::setRotation(Matrix3GLf rotation)
{
	_rotation = rotation;
}
