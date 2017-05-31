#pragma once
#include "GUIElement.h"
#include <GL/freeglut.h>
#include "Vec.h"
#include <string>

#define SSTR( x ) static_cast< std::ostringstream & >( \
			( std::ostringstream() << std::dec << x )).str()
/*
Class : Text
A Text is a subclass of GUIElement
This class is used for showing 2d text for the gui
*/
class Text : public GUIElement
{	
public:
	//Default Constructor
	Text() {};
	//Constructor with Vec3f pos, Vec3f col, std::string text
	//Vec3f pos, the position of the text on the screen
	//Vec3f col, the color of the text
	//std::string text, the actual text which will be shown on screen
	Text(Vec3f pos, Vec3f col, std::string text);
	//Constructor with Vec3f pos, Vec3f col, std::string text
	//Vec3f pos, the position of the text on the screen
	//Vec3f col, the color of the text
	Text(Vec3f pos, Vec3f col);
	//Updates the text needed to be shown
	void Update(std::string text);
	//Draws the text on the screen with the current variables
	void Draw() override;

private:
	Vec3f _color;
	std::string _text = "";
	void Sprint();

};