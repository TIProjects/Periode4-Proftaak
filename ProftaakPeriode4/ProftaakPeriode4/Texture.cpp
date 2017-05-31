#include "Texture.h"
#include <GL/freeglut.h>

#include <ostream>
#include <iostream>


#define COLOR_CHANNELS 4
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"


Texture::Texture(unsigned int id, int width, int height, int bpp)
{
	_id = id;
	_width = width;
	_height = height;
	_bpp = bpp;
}

Texture* LoadTexture(const char* fileName)
{
	// flips image vertically to be sure that image is shown correctly
	stbi_set_flip_vertically_on_load(true);

	// define used variables
	int width, height, bpp;
	unsigned int textureId;
	unsigned char * imgData = stbi_load(fileName, &width, &height, &bpp, STBI_rgb_alpha);

	// return nullptr when image failed to load (memory issue or file not found!)
	if (imgData == nullptr)
	{
		std::cout << "Image failed to load when reading textureFile! " << std::endl;
		return nullptr;
	}
	// generate textures and get textureId of image
	glGenTextures(1, &textureId);
	glBindTexture(GL_TEXTURE_2D, textureId);

	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, imgData);

	// free imagedata to save some precious memory
	stbi_image_free(imgData);
	
	// return new _texture
	return new Texture(textureId, width, height, bpp);
}
