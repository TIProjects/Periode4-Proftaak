#include "Model.h"
#include <GL\freeglut.h>
#include "DrawComponent.h"
#include "CameraComponent.h"
#include <iostream>
#include "MeshDrawComponent.h"
#include "MeshFactory.h"
#include "LaneGeneratorComponent.h"
#include "CollisionComponent.h"
#include "Collision.h"

Model::Model()
{
	_lastTime = 0;
}

void Model::update()
{
	// Calculate the deltaTime
	float currentTime = glutGet(GLUT_ELAPSED_TIME) / 1000.0f;
	float deltaTime = currentTime - _lastTime;
	_lastTime = currentTime;

	// deltaTime should never be allowed to be 0 or negative...
	if (deltaTime <= 0) deltaTime = 0.000001f;

	// Calculate and display fps
	// For performance profiling only
	// should normally be commented
    //	int fps = int(1.0 / deltaTime);
    //	std::cout << "Fps: " << fps << "DT: " << deltaTime << std::endl;

	// Call the Update of every GameObject
	for (GameObject * gameObject : _gameObjects)
	{
		gameObject->Update(deltaTime);
	}

	Collision::CheckCollision(_gameObjects);

	// Call the LateUpdate of every Gameobject afterwards
	for(GameObject * gameObject : _gameObjects)
	{
		gameObject->LateUpdate(deltaTime);
	}

	glutPostRedisplay();
}

void Model::InitTestObjects()
{
	// Test GameObjects
	// TODO: remove
	_lastTime = 0;

	GameObject * camera = new GameObject();
	CameraComponent * cameraComponent = new CameraComponent(1280.0f, 720.0f, 0.1f, 300.0f, 90.0f);
	camera->AddComponent(cameraComponent);

	_gameObjects.push_back(camera);

	GameObject * laneGenerator = new GameObject();
	std::vector<Mesh*> meshes;
	meshes.push_back(LoadMeshFile("Assets//Models//TestCube//Cube.Cobj"));

	DrawComponent * laneDrawComponent = new LaneGeneratorComponent(3,30, meshes);
	laneGenerator->AddComponent(laneDrawComponent);
	_gameObjects.push_back(laneGenerator);
}

void Model::Init()
{
	// TODO initialise gamelogic 
}
