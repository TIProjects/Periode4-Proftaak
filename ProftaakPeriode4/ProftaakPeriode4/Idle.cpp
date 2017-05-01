#include "Idle.h"

/*
	idle function, model is called here
*/
void idle()
{
	int currentTime = glutGet(GLUT_ELAPSED_TIME);
	deltaTime = (currentTime - lastTime) / 1000;
	lastTime = currentTime;

	glutPostRedisplay();
}


/*
	returns deltatime as a constant int
*/
int getDeltaTime(const int* delta)
{
	delta = &deltaTime;
	return *delta;
}