#include "Component.h"

Component::Component(ComponentID id)
{
	_id = id;
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
