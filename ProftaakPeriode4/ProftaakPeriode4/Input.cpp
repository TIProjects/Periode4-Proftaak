// #include "Component.h"
#include "Input.h"
/*
* bool arrays, are read by components
*/
bool keyboard[255];
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
	switch (key)
	{
	case GLUT_KEY_LEFT:
		keyLeft = true;
		break;
	case GLUT_KEY_RIGHT:
		keyRight = true;
		break;
	case GLUT_KEY_UP:
		keyUp = true;
		break;
	case GLUT_KEY_DOWN:
		keyDown = true;
		break;
	default:
		break;
	}
}

/*
* special key release detection
*/
void Keyboard::SKeyboardUp(int key, int x, int y)
{
	switch (key)
	{
	case GLUT_KEY_LEFT:
		keyLeft = false;
		break;
	case GLUT_KEY_RIGHT:
		keyRight = false;
		break;
	case GLUT_KEY_UP:
		keyUp = false;
		break;
	case GLUT_KEY_DOWN:
		keyDown = false;
		break;
	default:
		break;
	}
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

/*
* returns special keyboard array as contant pointer
*/
//void Keyboard::GetSKeyboard(bool* up, bool* down, bool* left, bool* right)
//{
//	*up = keyUp;
//	*down = keyDown;
//	*left = keyLeft;
//	*right = keyRight;
//}

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

