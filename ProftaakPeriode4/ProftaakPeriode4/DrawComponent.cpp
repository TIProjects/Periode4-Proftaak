#include "DrawComponent.h"
#include "GameObject.h"
#include <GL/freeglut.h>

DrawComponent::DrawComponent() : Component(DRAW_COMPONENT)
{
}

DrawComponent::~DrawComponent()
{
	// todo implement destructor
}


void DrawComponent::Draw()
{
	glPushMatrix();

	glTranslatef(_parent->_position.x, _parent->_position.y, _parent->_position.z);
	// TODO rotate object

	for (ObjGroup * group : groups)
	{
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, materials.at(group->materialIndex)->texture->_id);
		glBegin(GL_TRIANGLES);

		for (Face face : group->faces)
		{
			for (Vertex vertex : face.vertices)
			{
				glTexCoord2fv(texcoords[vertex.texcoord].v);
				glVertex3fv(vertices[vertex.position].v);
			}
		}

		glEnd();
		glDisable(GL_TEXTURE_2D);
	}

	glPopMatrix();
}
