#include "iostream"
#include "Model.h"
#include "View.h"
#include "ScoreComponent.h"
#include <GL\freeglut.h>
#include "Lanes.h"
#include "ScoreBoard.h"

Model model;
View view;

// The displayFunc which will call the update of the view
// This function should only be called by OpenGL and NOT manually
void window()
{
    
}

// The reshapeFunc which will call the reshape of the view
// This function should only be called by OpenGL and NOT manually
void reshape(int w, int h)
{
    
}

// The idleFunc which will call the update of the model
// This function should only be called by OpenGL and NOT manually
void idle()
{
	model.update();
}

int main(int argc, char* argv[]) {
	glutInit(&argc, argv);

	Model model = Model();
	View view = View(&model);
    ScoreComponent score = ScoreComponent();
    ScoreBoard board = ScoreBoard();

    board.loadScore();
    board.printScoreBoard(); 

	glutDisplayFunc(window);
	glutReshapeFunc(reshape);
	glutIdleFunc(idle);

	glutMainLoop();
	return 0;
}
