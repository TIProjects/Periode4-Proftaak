#include "Model.h"
#include <GL\freeglut.h>
#include "DrawComponent.h"
#include "CameraComponent.h"

Model::Model()
{
	
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
