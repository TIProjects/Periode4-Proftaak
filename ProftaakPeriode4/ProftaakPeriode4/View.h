#pragma once
#include <GL\freeglut.h>
#include "Model.h"

class View {
public:
	View(Model * model);
	View();

	void update();
	void reshape(int w, int h);
private:
	int _screenWidth;
	int _screenHeight;
	float _camNear;
	float _camFar;
	
	Model * _modelPtr;
};