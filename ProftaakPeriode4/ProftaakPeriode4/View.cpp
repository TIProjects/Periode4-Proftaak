#include "View.h"
#include <GL/freeglut.h>
#include "DrawComponent.h"
#include <iostream>

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

void View::UpdateView()
{

	glClearColor(0, 0, 0, 0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();


	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	gluPerspective(90.0f, _screenWidth / (float)_screenHeight, _camNear, _camFar);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	gluLookAt(0, 5, 5,
		0, 0, 0,
		0, 1, 0);

	/*
	 * for DrawComponent in beautifullcomponents:
	 * glPushMatrix();
	 *		draw that!
	 * glPopMatrix();	
	 */


	glEnable(GL_DEPTH_TEST);

	glutSwapBuffers();
}



void View::reshape(int w, int h)
{
	_screenWidth = w;
	_screenHeight = h;
	glViewport(0, 0, w, h);
}
