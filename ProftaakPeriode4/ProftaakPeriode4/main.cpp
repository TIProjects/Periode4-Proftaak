#include "iostream"
#include "Model.h"
#include "View.h"
#include "Score.h"
#include "ScoreBoard.h"
#include <GL\freeglut.h>
#include "Idle.h"
#include "Lanes.h"

void Test()
{

	Lanes lanes = Lanes(3);
}

int main(int argc, char* argv[]) {
	Test();

	glutInit(&argc, argv);

	Model model = Model();
	View view = View(&model);

	glutDisplayFunc(window);
	glutReshapeFunc(reshape);
	glutIdleFunc(idle);

	glutMainLoop();
	return 0;
}
