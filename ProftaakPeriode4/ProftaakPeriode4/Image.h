#pragma once
#include "GUIElement.h"
#include <GL/freeglut.h>
#include <vector>
#include "Texture.h"
/*
Class : Image
A Image is a subclass of GUIElement
This class is used for showing 2d images for the gui
*/
class Image : public GUIElement
{
public:
	//Default Constructor
	Image() {};
	/*
		Constructor for Image
		Vec3f pos, position on the screen of Image
		float width, the width of how wide the image should be
		float height, the height of how high the image should be
		std::string path, the path of where the image is located
	*/
	Image(Vec3f pos, float width, float height, std::string path);
	//Sets the width of the image with the value given
	void SetWidth(float width);
	//Draws the image on the screen with the current variables
	void Draw() override;

protected:
	struct Vertex
	{
		float x, y, z;
		float tx, ty;
	};

	float _Width, _Height;
	Texture * _Texture;
	std::vector<Vertex> _Vertices;

	//Calculates the vertices of the image after an resize
	void CalculateVertices();

};