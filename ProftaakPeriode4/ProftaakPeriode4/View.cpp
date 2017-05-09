#include "View.h"
#include <GL\freeglut.h>
#include "Component.h"
#include "CameraComponent.h"

View::View(Model * model, int argc, char * argv[])
{
	_screenWidth = 1280;
	_screenHeight = 720;

	_camNear = 0.01f;
	_camFar = 50.0f;

	_modelPtr = model;

	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize(_screenWidth, _screenHeight);
	glutInit(&argc, argv);


	glutCreateWindow("Cube_Runner");


	_modelPtr->_lastTime = 0;

	GameObject * camera = new GameObject();
	CameraComponent * cameraComponent = new CameraComponent(1280.0f, 720.0f, 0.1f, 30.0f, 90.0f);
	camera->AddComponent(cameraComponent);


	camera->Update(2);
	_modelPtr->_gameObjects.push_back(camera);

	GameObject * testObject = new GameObject();
	DrawComponent * drawComponent = LoadComponent("Assets//Models//TestCube//Cube.obj");
	testObject->_position.z -= 3;
	testObject->AddComponent(drawComponent);

	_modelPtr->_gameObjects.push_back(testObject);
}

View::View()
{
	_screenWidth = 1280;
	_screenHeight = 720;

	_camNear = 0.01f;
	_camFar = 50.0f;
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
