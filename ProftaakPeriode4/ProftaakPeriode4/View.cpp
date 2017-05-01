#include "View.h"

View::View(Model * model)
{
	_modelPtr = model;

	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowSize(width, height);

	glutCreateWindow("Cube_Runner");
}