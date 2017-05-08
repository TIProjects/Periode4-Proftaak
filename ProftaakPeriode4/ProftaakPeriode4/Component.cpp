#include "Component.h"

Component::Component(ComponentID id, GameObject * parent)
{
	_id = id;
	_parent = parent;
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
