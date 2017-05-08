#include "View.h"
#include <GL\freeglut.h>
#include "CameraComponent.h"

View::View(Model * model)
{
	_screenWidth = 1280;
	_screenHeight = 720;

	_camNear = 0.01f;
	_camFar = 50.0f;

	_modelPtr = model;

	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowSize(_screenWidth, _screenHeight);

	glutCreateWindow("Cube_Runner");
}

View::View()
{
	_screenWidth = 1280;
	_screenHeight = 720;

	_camNear = 0.01f;
	_camFar = 50.0f;
}

void View::update()
{
	glClearColor(100, 100, 150, 0);

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();


	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	// Use the Camera GameObject to create a view
	for (GameObject gameObject : _modelPtr->_gameObjects)
	{
		CameraComponent * camera = dynamic_cast<CameraComponent *>(gameObject.GetComponent(CAMERA_COMPONENT));
		if(camera != nullptr)
		{
			// Found camera, apply it's view and stop looping the list
			camera->ApplyCamera();
			break;
		}
	}

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	glEnable(GL_DEPTH_TEST);

	glutSwapBuffers();
}

void View::reshape(int w, int h)
{
	_screenWidth = w;
	_screenHeight = h;
	glViewport(0, 0, w, h);
}
