#include "GameObject.h"
#include "DrawComponent.h"


GameObject::GameObject()
{
	_position = Vec3f();
	_rotation = Vec3f();
}

void GameObject::Update(float deltaTime)
{
	for (Component * component : _components)
	{
		component->Update(deltaTime);
	}
}

void GameObject::LateUpdate(float deltaTime)
{
	for(Component * component : _components)
	{
		component->LateUpdate(deltaTime);
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

void GameObject::Draw()
{
	// Return if there is no DrawComponent
	if(_drawComponent == nullptr) return;

	_drawComponent->Draw();
}

Component * GameObject::GetComponent(ComponentID id)
{
	for (Component * component : _components)
	{
		// Component is found so it's reference is returned
		if (component->_id == id)
		{
			return component;
		}
	}
	// The component was not found so a nullptr is returned
	return nullptr;
}

void GameObject::AddComponent(Component * component)
{
	component->SetParent(this);
	_components.push_back(component);

	// If the GameObject does not have a DrawComponent yet, add the new component as
	// A draw component. if the new component is not a draw component, this GameObjects
	// Draw component will simply be nullptr due to the dynamic_cast
	if (_drawComponent == nullptr)
		_drawComponent = dynamic_cast<DrawComponent*>(component);
}

bool GameObject::RemoveComponent(Component* component)
{
	// TODO implement
	return false;
}
