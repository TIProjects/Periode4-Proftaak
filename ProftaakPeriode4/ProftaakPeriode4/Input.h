#pragma once
#include <GL\freeglut.h>
#include "Vec.h"
namespace Keyboard
{
	void SKeyboardDown(int key, int x, int y);
	void SKeyboardUp(int key, int x, int y);
	void KeyBoardDown(unsigned char key, int x, int y);
	void KeyBoardUp(unsigned char key, int x, int y);

	const bool* GetKeyboard();
	//void GetSKeyboard(bool* up, bool* down, bool* left, bool* right);
	
}

namespace Mouse
{
	void MoveMouse(int x, int y);
	const Vec2i GetMousePos();
}