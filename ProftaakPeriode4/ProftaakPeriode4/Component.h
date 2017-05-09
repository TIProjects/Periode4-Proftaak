#pragma once

// Enum which will indicate the functionality of a Component
enum ComponentID
{
	SCORE_COMPONENT,
	DRAW_COMPONENT
};

class Component
{
public:
	// Base Constructor for a component
	// if a class overrides this function it's important to
	// still call this function to make sure the id is set
	explicit Component(ComponentID id);

	// Base Destructor for a component
	// TODO Add base Destructor functionality
	virtual ~Component();

	// Update is called as often as possible
	// @param int deltaTime: the time in milliseconds between the current and last frame
	virtual void Update(int deltaTime);

	// LateUpdate is also called as often as possible,
	// but always after the Update of EVERY GameObject
	// has been called
	// @param int deltaTime: the time in milliseconds between the current and last frame
	virtual void LateUpdate(int deltaTime);

	// The identifier of the component
	ComponentID _id;
private:
};

