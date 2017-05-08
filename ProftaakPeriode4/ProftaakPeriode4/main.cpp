#include "iostream"
#include "Model.h"
#include "View.h"
#include "Score.h"
#include <GL\freeglut.h>
#include "Lanes.h"

void window()
{
    
}

void reshape(int, int)
{
    
}

void idle()
{
    
}

int main(int argc, char* argv[]) {
	glutInit(&argc, argv);

	Model model = Model();
	View view = View(&model);

	glutDisplayFunc(window);
	glutReshapeFunc(reshape);
	glutIdleFunc(idle);

	glutMainLoop();
	return 0;
}
