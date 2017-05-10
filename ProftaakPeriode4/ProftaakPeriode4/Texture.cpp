#include "Texture.h"

Texture::Texture(int id, int width, int height, int bpp)
{
	_id = id;
	_width = width;
	_height = height;
	_bp = bpp;
}

Texture::~Texture()
{
	// todo implement destructor
}
