#include "GameObject.h"


GameObject::GameObject(std::vector<Vec3f> vertices)
{
	_position = Vec3f();
	_rotation = Vec3f();
}

void GameObject::update(int deltaTime)
{
	for (Component component : _components)
	{
		component.Update(deltaTime);
	}
}

void GameObject::lateUpdate(int deltaTime)
{
	for(Component component : _components)
	{
		component.LateUpdate(deltaTime);
	}
}


void GameObject::setPosition(Vec3f position)
{
	_position = Vec3f(position);
}

void GameObject::rotate(Vec3f rotation)
{
	_rotation.x += rotation.x;
	_rotation.y += rotation.y;
	_rotation.z += rotation.z;
}

void GameObject::setRotation(Vec3f rotation)
{
	_rotation = Vec3f(rotation);
}