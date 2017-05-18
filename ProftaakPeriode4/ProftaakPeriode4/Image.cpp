#include "Image.h"

Image::Image(Vec3f pos, float width, float height, std::string path) : GUIElement(pos)
{
	_Width = width;
	_Height = height;
	_Texture =LoadTexture(path.c_str());
	CalculateVertices();
}

void Image::SetWidth(float width)
{
	_Width = width;
	CalculateVertices();
}

void Image::Draw()
{
	glDisable(GL_LIGHTING);
	glDisable(GL_LIGHT0);
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_BLEND);
	glDisable(GL_DEPTH_TEST);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glBindTexture(GL_TEXTURE_2D, _Texture->_id);

	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);

	glVertexPointer(3, GL_FLOAT, sizeof(Vertex), ((float*)_Vertices.data()) + 0);
	glTexCoordPointer(2, GL_FLOAT, sizeof(Vertex), ((float*)_Vertices.data()) + 3);

	glDrawArrays(GL_QUADS, 0, _Vertices.size());

	glDisableClientState(GL_COLOR_ARRAY);
	glDisableClientState(GL_VERTEX_ARRAY);
	glDisable(GL_BLEND);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
}

void Image::CalculateVertices()
{
	_Vertices.clear();
	_Vertices.push_back(Vertex{ _position.x + _Width, _position.y + _Height, _position.z, 1.0f, 1.0f });
	_Vertices.push_back(Vertex{ _position.x + _Width, _position.y, _position.z, 1.0f, 0.0f });
	_Vertices.push_back(Vertex{ _position.x, _position.y, _position.z, 0.0f, 0.0f });
	_Vertices.push_back(Vertex{ _position.x, _position.y + _Height, _position.z, 0.0f, 1.0f });
}
