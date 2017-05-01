#include "Window.h"

/*
	display update
*/
void window()
{
	glClearColor(0, 0, 0, 0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();


	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	gluPerspective(90.0f, width / (float)height, camNear, camFar);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	gluLookAt(0, 5, 5,
		0, 0, 0,
		0, 1, 0);

	//Models are drawn here..
#ifdef DEBUG
	glPushMatrix();
	//glTranslatef(posX, posY, posZ);
	//glRotatef(rotation, 0, 1, 0);
	drawCube();
	glPopMatrix();
#endif // DEBUG



	glEnable(GL_DEPTH_TEST);
	
	glutSwapBuffers();
}

void reshape(int w, int h)
{
	width = w;
	height = h;
	glViewport(0, 0, w, h);
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