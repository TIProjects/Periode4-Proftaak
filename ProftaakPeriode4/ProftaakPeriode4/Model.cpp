#include "Model.h"
#include <GL\freeglut.h>

Model::Model()
{
}

int Model::getDeltaTime(const int* delta)
{
	delta = &deltaTime;
	return *delta;
}

void Model::update()
{
	int currentTime = glutGet(GLUT_ELAPSED_TIME);
	deltaTime = (currentTime - lastTime) / 1000;
	lastTime = currentTime;

	glutPostRedisplay();
}
