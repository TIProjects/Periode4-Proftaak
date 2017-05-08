#pragma once

#include <vector>
#include "GameObject.h"

class Model {
public:
    // Constructor for Model
    // Initialises _lastTime as 0
    Model();

    int getDeltaTime(const int* delta);

    int deltaTime;
    int lastTime;
    // Update the model by calling Update and LateUpdate
    // of every GameObject present in the model
    void update();

private:
    // Vector of every GameObject present in the model
    std::vector<GameObject> _gameObjects;

    // The last time a frame was rendered in milliseconds
    int _lastTime;
};
