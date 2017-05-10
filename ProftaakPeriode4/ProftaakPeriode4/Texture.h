#pragma once
class Texture
{
public:
	/*
	* Constructor for creating a Texture
	* \id is ID of created texture, used for binding to vertex
	* \width is the width of the texture file
	* \height is the height of the texture file
	* \bpp is the amount of channels used in the texture (RGB/RGBA/...)
	*/
	Texture(int id, int width, int height, int bpp);
	~Texture();
private:
	int _id;
	int _width;
	int _height;
	int _bp;
};

