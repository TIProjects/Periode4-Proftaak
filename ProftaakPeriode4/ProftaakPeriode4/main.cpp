#include "Component.h"
#include "Model.h"
#include "View.h"
#include "GUIComponent.h"
#include "VisionComponent.h"
#include "LaneGeneratorComponent.h"
#include "GUIElement.h"
#include "Text.h"
#include <GL\freeglut.h>
#include "Input.h"

Model model;
View view;
unsigned int fps = 20;

// Function that will be called on exiting the game
void onExit()
{
    //TODO: add here the methodes that you want to be called on exit
    ScoreBoardComponent * tempBoard;
    
    for (auto m : model._gameObjects)
    {
        tempBoard = static_cast<ScoreBoardComponent *>(m->GetComponent(SCOREBOARD_COMPONENT));
        if (tempBoard != nullptr) {
            tempBoard->SaveScore();
            break;
        }        
    }

    delete tempBoard;


	for (GameObject* g : model._gameObjects)
	{
		LaneGeneratorComponent* lane = dynamic_cast<LaneGeneratorComponent*>(g->GetComponent(ComponentID::DRAW_COMPONENT));
		if (lane != nullptr)
		{
			for (GameObject* c : lane->_obstacles)
			{
				VisionComponent* vision = dynamic_cast<VisionComponent*>(c->GetComponent(ComponentID::VISION_COMPONENT));
				if (vision != nullptr)
				{
					vision->stopVisionThread();
					break;
				}
			}
		}
	}
}

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

	// Call the regular model init
	// this will initialise the game
	// do NOT remove
	model.Init();
	model.InitSound();
    atexit(onExit);
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
