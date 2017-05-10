#include "Mesh.h"
#include "GL/freeglut.h"



MaterialInfo::MaterialInfo()
{
	_texture = nullptr;
}

Mesh::Mesh()
{
	_width = 1.0f;
	_length = 1.0f;
}


Mesh::~Mesh()
{
	// todo implement destructor
}

void Mesh::Draw(Vec3f position, Vec3f rotation, float rotationAngle)
{
	glPushMatrix();

	glTranslatef(position.x, position.y, position.z);
	glRotatef(rotationAngle, rotation.x, rotation.y, rotation.z);

	DrawRaw();

	glPopMatrix();
}

void Mesh::DrawRaw()
{
	for (ObjGroup * group : _groups)
	{
		if (group->_materialIndex != -1 && _materials.at(group->_materialIndex)->_texture != nullptr) {
			glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D, _materials.at(group->_materialIndex)->_texture->_id);
		}
		glBegin(GL_TRIANGLES);

		for (Face face : group->_faces)
		{
			for (Vertex vertex : face._vertices)
			{
				glTexCoord2fv(_texcoords[vertex._texcoord].v);
				glVertex3fv(_vertices[vertex._position].v);
			}
		}

		glEnd();
		glDisable(GL_TEXTURE_2D);
	}
}

