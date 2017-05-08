#include "Model.h"
#include <GL\freeglut.h>
#include "DrawComponent.h"
#include "CameraComponent.h"

Model::Model()
{
	_lastTime = 0;
	
	GameObject * camera = new GameObject();
	CameraComponent * cameraComponent = new CameraComponent(1280, 720, 1, 30, 90, camera);
	camera->AddComponent(cameraComponent);
	

	camera->Update(2);
	_gameObjects.push_back(camera);

	GameObject * testObject = new GameObject();
	DrawComponent * drawComponent = LoadComponent("Assets//Models//TestCube//Cube.obj", testObject);
	testObject->AddComponent(drawComponent);
	testObject->_position.x += 10;

	_gameObjects.push_back(testObject);
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
