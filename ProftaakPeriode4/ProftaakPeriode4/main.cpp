#include "Model.h"
#include "View.h"
#include "Lanes.h"
#include "Input.h"

#include <GL\freeglut.h>
#include "CameraComponent.h"

Model model;
View view;

// The displayFunc which will call the UpdateView of the view
// This function should only be called by OpenGL and NOT manually
void display()
{
	view.UpdateView();
}

// The reshapeFunc which will call the reshape of the view
// This function should only be called by OpenGL and NOT manually
void reshape(int w, int h)
{
	view.reshape(w, h);
}

// The idleFunc which will call the UpdateView of the model
// This function should only be called by OpenGL and NOT manually
void idle()
{
	model.update();
}


int main(int argc, char* argv[]) {
	glutInit(&argc, argv);

	model = Model();
	view = View(&model);

	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutIdleFunc(idle);
	glutKeyboardFunc(Keyboard::KeyBoardDown);
	glutKeyboardUpFunc(Keyboard::KeyBoardUp);
	glutSpecialFunc(Keyboard::SKeyboardDown);
	glutSpecialUpFunc(Keyboard::SKeyboardUp);
	glutPassiveMotionFunc(Mouse::MoveMouse);


	glutMainLoop();
	return 0;
}
