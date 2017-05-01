#include "iostream"
#include "Model.h"
#include "View.h"
#include "Score.h"
#include "ScoreBoard.h"
<<<<<<< HEAD
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
=======

int main() {
    Model model = Model();
    View view = View(&model);

    return 0;
}
>>>>>>> 3ca763f6fc9e697643f0caa46cd37b4d07e503ca
