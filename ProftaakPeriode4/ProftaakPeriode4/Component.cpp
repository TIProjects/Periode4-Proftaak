#include "Component.h"

Component::Component(ComponentID id)
{
	_id = id;
	_parent = nullptr;
}

Component::~Component()
{
	// TODO destructor stuff
}

void Component::Update(int deltaTime)
{
}

void Component::LateUpdate(int deltaTime)
{
}

void Component::SetParent(GameObject* parent)
{
	_parent = parent;
}
