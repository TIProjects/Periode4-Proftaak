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
		glRasterPos2f(pos.x, pos.y); // location to start printing text
	
		const char* chars = _text.c_str();
		glutBitmapString(GLUT_BITMAP_HELVETICA_18, (unsigned char *)chars);
	}
}