#include "Component.h"
#include "Model.h"
#include "View.h"
#include "GUIComponent.h"
#include "GUIElement.h"
#include "Text.h"
#include "ScoreBoard.h"
#include "ScoreComponent.h"
#include <GL\freeglut.h>
#include "Input.h"

Model model;
View view;
unsigned int fps = 20;

// The displayFunc which will call the UpdateView of the view
// This function should only be called by OpenGL and NOT manually
void window()
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


int main(int argc, char* argv[]) 
{
	view = View(&model, argc, argv);

	// Call the test object initialiser 
	// For testing...
	// can be removed if testing is not necessary
	model.InitTestObjects();

	// Call the regular model init
	// this will initialise the game
	// do NOT remove
	model.Init();

	glutDisplayFunc(window);
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
