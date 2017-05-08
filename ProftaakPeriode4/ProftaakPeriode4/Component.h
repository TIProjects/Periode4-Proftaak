#pragma once

enum ComponentID
{
	SCORE_COMPONENT
};

class Component
{
public:
	Component(ComponentID id);
    virtual ~Component();

	int _id;

	virtual void Update(int deltaTime);
	virtual void LateUpdate(int deltaTime);
private:
};

