#pragma once
#include "GUIElement.h"
#include <vector>
#include "Image.h"
/*
Class : LifeBar
A LifeBar is a subclass of GUIElement
This class is used for showing a 2d representation of the a players health
*/
class LifeBar : public GUIElement
{
public:
	//Default constructor
	LifeBar()
	{
		_background = nullptr;
		_segment = nullptr;
		_frame = nullptr;
		_bar = nullptr;

		float _width =  _height;
		Vec3f _pos;
		int _sections;
		int _life;
	}
	/*
	Constructor with variables
	Vec3f pos, position of GUIElement, this will be passed to the constructor of GUIElement
	float width, width of the GUIElement
	float Height, height of the GUIElement
	std::vector<std::string> paths, the paths of all the images of the lifebar
	int sections, the amount of sections needed to be put in the lifebar
	*/
	LifeBar(Vec3f pos, float width, float height, int sections, std::string background, std::string _frame, std::string _bar, std::string _segment);
	//Increments the LifeBar one segment if acceptable
	int Increment();
	//Decrements the LifeBar one segment if acceptable
	int Decrement();
	//draws the lifebar
	void Draw() override;

protected:
	Image * _background;
	Image * _segment;
	Image * _frame;
	Image * _bar;

	float _width, _height;
	Vec3f _pos;
	int _sections;
	int _life;
};