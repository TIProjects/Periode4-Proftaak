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
	LifeBar() {};
	/*
	Constructor with variables
	Vec3f pos, position of GUIElement, this will be passed to the constructor of GUIElement
	float width, width of the GUIElement
	float Height, height of the GUIElement
	std::vector<std::string> paths, the paths of all the images of the lifebar
	int size, amount of strings in paths
	int sections, the amount of sections needed to be put in the lifebar
	*/
	LifeBar(Vec3f pos, float width, float height, std::vector<std::string> paths, int size, int sections);
	//Increments the LifeBar one segment if acceptable
	void Increment();
	//Decrements the LifeBar one segment if acceptable
	void Decrement();
	//draws the lifebar
	void Draw() override;

protected:
	std::vector<Image> _Images;
	float _Width, _Height;
	int _Sections;
	int _Life;
};