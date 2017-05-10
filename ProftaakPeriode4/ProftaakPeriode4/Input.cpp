// #include "Component.h"
#include "Input.h"
/*
* bool arrays, are read by components
*/
bool keyboard[255];
bool sKeyoard[255];

bool keyLeft = false;
bool keyRight = false;
bool keyUp = false;
bool keyDown = false;
Vec2i mousePos = Vec2i();

/*
* special key press detection
*/
void Keyboard::SKeyboardDown(int key, int x, int y)
{
	sKeyoard[key] = true; 
}

/*
* special key release detection
*/
void Keyboard::SKeyboardUp(int key, int x, int y)
{
	sKeyoard[key] = false;
}

/*
* _normal key press detection
*/
void Keyboard::KeyBoardDown(unsigned char key, int x, int y)
{
	keyboard[key] = true;
}

/*
* _normal key release detection
*/
void Keyboard::KeyBoardUp(unsigned char key, int x, int y)
{
	keyboard[key] = false;
}

/*
* returns keyboard array as contant pointer
*/
const bool * Keyboard::GetKeyboard()
{
	return keyboard;
}

const bool* Keyboard::GetSKeyboard()
{
	return sKeyoard;
}

/*
* detects mouse movement and updates coordinates
*/
void Mouse::MoveMouse(int x, int y)
{
	mousePos = Vec2i(x, y);
}

/*
* returns mouseposition vec2i as const pointer
*/
Vec2i Mouse::GetMousePos()
{
	return mousePos;
}

