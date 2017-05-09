#pragma once

#include <vector>
#include "GameObject.h"

class Model {
public:
	// Constructor for Model
	// Initialises _lastTime as 0
	Model();

	// Update the model by calling Update and LateUpdate
	// of every GameObject present in the model
	void update();

	// Vector of every GameObject present in the model
	std::vector<GameObject*> _gameObjects;
private:
	// The last time a frame was rendered in milliseconds
	int _lastTime;
};
