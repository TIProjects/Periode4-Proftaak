#include "Text.h"
#include <iostream>
#include <sstream>

Text::Text(Vec3f pos, Vec3f col, std::string text) : GUIElement(pos)
{
	_color = col;
	_text = text;
}

Text::Text(Vec3f pos, Vec3f col) : GUIElement(pos)
{
	_color = col;
}

void Text::Draw() {
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	glOrtho(0.0, 800, 600, 0.0, -1.0, 10.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glClear(GL_DEPTH_BUFFER_BIT);

	glPushAttrib(GL_CURRENT_BIT);
	glColor3f(_color.x,_color.y,_color.z);
	Sprint();
	glPopAttrib();
}

void Text::Update(std::string text) {
	if(_enabled) _text = text;
}

// This prints a string to the screen
void Text::Sprint()
{
	if (_visible) {
		Vec3f pos = GetPosition();
		std::string temp = _text;
		const char *st = temp.c_str();
		size_t l = strlen(st); // see how many characters are in text string.
		glRasterPos2f(pos.x, pos.y); // location to start printing text
		for (size_t i = 0; i < l; i++) // loop until i is greater then l
		{
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, st[i]); // Print a character on the screen
			//std::cout << st[i] << std::endl;
		}
	}
}