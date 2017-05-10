#pragma once
#include <GL\freeglut.h>
#include "Vec.h"

#define KEYBOARD_KEY_ESC 27

namespace Keyboard
{
	void SKeyboardDown(int key, int x, int y);
	void SKeyboardUp(int key, int x, int y);
	void KeyBoardDown(unsigned char key, int x, int y);
	void KeyBoardUp(unsigned char key, int x, int y);

	const bool* GetKeyboard();
	const bool * GetSKeyboard();
}

namespace Mouse
{
	void MoveMouse(int x, int y);
	Vec2i GetMousePos();
}