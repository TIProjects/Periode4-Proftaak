#pragma once
#include <GL\freeglut.h>
// #include "Component.h"
#include "Model.h"

class View {
public:
	// Constructor
	// @param Model * model: pointer to the model which will be used in this view
	// @param int argc: C++ argument which will be passed on to OpenGl
	// @param char * argv[]: C++ argument which will be passed on to OpenGl
	View(Model * model, int argc, char * argv[]);
	// Default constructor used to copy, or declere this class
	// without initialisation
	//
	// NOTE: this does NOT create a window nor does
	// it create an OpenGL context 
	View();

	// Update the view and draw all the GameObjects from the model
	// NOTE: should only be called by the OpenGL displayFunc
	void UpdateView();

	// Reshape the window using a new width and height
	// NOTE: should only be called by the OpenGL reshapeFunc
	void reshape(int w, int h);
private:
	// Pointer to the model from which all the GameObjects will be drawn
	Model * _modelPtr;
};