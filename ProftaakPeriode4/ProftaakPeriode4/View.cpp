#include "View.h"
#include <GL\freeglut.h>


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

void drawCube()
{
	glColor3f(1, 0, 0);
	glBegin(GL_QUADS);
	//front
	glVertex3f(-0.5, -0.5, -0.5);
	glVertex3f(0.5, -0.5, -0.5);
	glVertex3f(0.5, 0.5, -0.5);
	glVertex3f(-0.5, 0.5, -0.5);

	//left
	glColor3f(0, 1, 0);
	glVertex3f(-0.5, -0.5, 0.5);
	glVertex3f(-0.5, -0.5, -0.5);
	glVertex3f(-0.5, 0.5, -0.5);
	glVertex3f(-0.5, 0.5, 0.5);

	//back
	glColor3f(1, 0, 0);
	glVertex3f(-0.5, -0.5, 0.5);
	glVertex3f(0.5, -0.5, 0.5);
	glVertex3f(0.5, 0.5, 0.5);
	glVertex3f(-0.5, 0.5, 0.5);

	//right
	glColor3f(0, 1, 0);
	glVertex3f(0.5, -0.5, 0.5);
	glVertex3f(0.5, -0.5, -0.5);
	glVertex3f(0.5, 0.5, -0.5);
	glVertex3f(0.5, 0.5, 0.5);

	//top
	glColor3f(0, 0, 1);
	glVertex3f(-0.5, 0.5, -0.5);
	glVertex3f(0.5, 0.5, -0.5);
	glVertex3f(0.5, 0.5, 0.5);
	glVertex3f(-0.5, 0.5, 0.5);

	//bottom
	glColor3f(0, 0, 1);
	glVertex3f(-0.5, -0.5, -0.5);
	glVertex3f(0.5, -0.5, -0.5);
	glVertex3f(0.5, -0.5, 0.5);
	glVertex3f(-0.5, -0.5, 0.5);

	glEnd();
}

void View::update()
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

	//Models are drawn here..
//#ifdef DEBUG
	glPushMatrix();
	//glTranslatef(posX, posY, posZ);
	//glRotatef(rotation, 0, 1, 0);
	drawCube();
	glPopMatrix();
//#endif // DEBUG



	glEnable(GL_DEPTH_TEST);

	glutSwapBuffers();
}

void View::reshape(int w, int h)
{
	_screenWidth = w;
	_screenHeight = h;
	glViewport(0, 0, w, h);
}