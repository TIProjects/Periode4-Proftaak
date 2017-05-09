#pragma once

/*
 * Class for saving Texture as object
 * \id for binding texture to created texture in GL
 * \width the width of the texture
 * \height the height of the texture
 * \bpp the amount of colorchannels in the texture
 */
class Texture
{
public:
	Texture(int id, int width, int height, int bpp);

	int _id;
	int _width;
	int _height;
	int _bpp;
};

/*
* Loading a texture from a given fileName
* \fileName string filename of the texturefile
* \return Texture object
* !warning possible nullptr when texture failed to load
*/
Texture * LoadTexture(const char * fileName);