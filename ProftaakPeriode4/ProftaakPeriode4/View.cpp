#include "View.h"
#include <GL\freeglut.h>
#include "Component.h"
#include "CameraComponent.h"

View::View(Model * model, int argc, char * argv[])
{
	_modelPtr = model;

	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize(1280, 720);
	glutInit(&argc, argv);

	glutCreateWindow("Cube_Runner");
}

View::View()
{
	_modelPtr = nullptr;
}

void View::UpdateView()
{
	glClearColor(0, 0.5, 1, 0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Use the Camera GameObject to create a view
	for (GameObject * gameObject : _modelPtr->_gameObjects)
	{
		CameraComponent * camera = dynamic_cast<CameraComponent *>(gameObject->GetComponent(CAMERA_COMPONENT));
		if(camera != nullptr)
		{
			// Found camera, apply it's view and stop looping the list
			camera->ApplyCamera();
			break;
		}
	}
	glEnable(GL_DEPTH_TEST);


	// Draw all the gameObject
	for(GameObject * gameObject : _modelPtr->_gameObjects)
	{
		gameObject->Draw(); 
	}

	glutSwapBuffers();
}

void View::reshape(int w, int h)
{
	for (GameObject * gameObject : _modelPtr->_gameObjects)
	{
		CameraComponent * camera = dynamic_cast<CameraComponent *>(gameObject->GetComponent(CAMERA_COMPONENT));
		if (camera != nullptr)
		{
			camera->_screenWidth = float(w);
			camera->_screenHeight = float(h);
			break;
		}
	}
}
