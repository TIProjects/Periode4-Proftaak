#include "Model.h"
#include <GL\freeglut.h>
#include "DrawComponent.h"
#include "CameraComponent.h"

Model::Model()
{
	_lastTime = 0;
}

void Model::update()
{
	// Calculate the deltaTime
	int currentTime = glutGet(GLUT_ELAPSED_TIME);
	int deltaTime = (currentTime - _lastTime) / 1000;
	_lastTime = currentTime;

	// Call the Update of every GameObject
	for (GameObject * gameObject : _gameObjects)
	{
		gameObject->Update(deltaTime);
	}

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
	CameraComponent * cameraComponent = new CameraComponent(1280.0f, 720.0f, 0.1f, 30.0f, 90.0f);
	camera->AddComponent(cameraComponent);

	_gameObjects.push_back(camera);

	GameObject * testObject = new GameObject();
	DrawComponent * drawComponent = LoadComponent("Assets//Models//TestCube//Cube.obj");
	testObject->_position.z -= 3;
	testObject->AddComponent(drawComponent);

	_gameObjects.push_back(testObject);
}

void Model::Init()
{
	// TODO initialise gamelogic 
}
