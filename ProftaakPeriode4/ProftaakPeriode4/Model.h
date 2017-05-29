#pragma once

#include <vector>
// #include "Component.h"
#include "GameObject.h"
#include "ScoreBoard.h"

class Model {
public:
    // Constructor for Model
    // Initialises _lastTime as 0
    Model();

    // Update the model by calling Update and LateUpdate
    // of every GameObject present in the model
    void update();

    // Initialise a simple set of test objects
    // by adding a few GameObjects to the GameObject vector
    // NOTE: should ONLY be called AFTER an OpenGL context has been created
    // and ONLY ONCE
    void InitTestObjects();

	/*
	 * Initialise audio for game
	 * Is static for not needing other data
	 */
	static void InitSound();

	/*
	 * Initialise the GUI elements
	 */
	void InitGUIElements();

    // Initialise the gameLogic
    // NOTE: should ONLY be called AFTER an OpenGL context has been created
    // and ONLY ONCE
    void Init();

    // Vector of every GameObject present in the model
    std::vector<GameObject*> _gameObjects;


    void play(int i);
private:

    // The last time a frame was rendered in milliseconds
    float _lastTime;
};
