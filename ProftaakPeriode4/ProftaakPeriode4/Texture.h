#pragma once

/**
 * Class for saving Texture as object
 * \id for binding _texture to created _texture in GL
 * \width the width of the _texture
 * \height the height of the _texture
 * \bpp the amount of colorchannels in the _texture
 */
class Texture
{
public:
	Texture(unsigned int id, int width, int height, int bpp);

	unsigned int _id;
	int _width;
	int _height;
	int _bpp;
};

/**
* Loading a _texture from a given fileName
* \param fileName string filename of the texturefile
* \return Texture object
* !warning possible nullptr when _texture failed to load
*/
Texture * LoadTexture(const char * fileName);