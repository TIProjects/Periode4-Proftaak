#include "GameObject.h"


GameObject::GameObject(std::vector<Vec3f> vertices)
{
	_position = Vec3f();
	_rotation = Vec3f();
}

void GameObject::Update(int deltaTime)
{
	for (Component component : _components)
	{
		component.Update(deltaTime);
	}
}

void GameObject::LateUpdate(int deltaTime)
{
	for(Component component : _components)
	{
		component.LateUpdate(deltaTime);
	}
}


void GameObject::SetPosition(Vec3f position)
{
	_position = Vec3f(position);
}

void GameObject::Rotate(Vec3f rotation)
{
	_rotation.x += rotation.x;
	_rotation.y += rotation.y;
	_rotation.z += rotation.z;
}

void GameObject::SetRotation(Vec3f rotation)
{
	_rotation = Vec3f(rotation);
}

Component * GameObject::GetComponent(ComponentID id)
{
	int i = 0; // index used to determine the current Component
	for (Component component : _components)
	{
		// Store pointer to the current component so it can be returned
		Component * current = &_components[i];
		i++;

		// Component is found so it's reference is returned
		if (component._id == id)
		{
			return current;
		}
	}
	// The component was not found so a nullptr is returned
	return nullptr;
}
