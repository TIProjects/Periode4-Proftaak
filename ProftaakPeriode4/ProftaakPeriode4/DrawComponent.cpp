#include "DrawComponent.h"
#include <GL/freeglut.h>

DrawComponent::DrawComponent() : Component(DRAW_COMPONENT)
{
}

DrawComponent::~DrawComponent()
{
	// todo implement destructor
}


void DrawComponent::Update(int deltaTime)
{
	// todo deltaTime not implemented
	for (ObjGroup * group : groups)
	{
		for (Face face : group->faces)
		{
			glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D, materials.at(group->materialIndex)->texture->_id);
			glBegin(GL_TRIANGLES);
			for (Vertex vertex : face.vertices)
			{
				Vec3f vec = vertices.at(vertex.position);
				Vec2f tex = texcoords.at(vertex.texcoord);
				glTexCoord2f(tex.x, tex.y);
				glVertex3f(vec.x, vec.y, vec.z);
			}
			glEnd();
			glDisable(GL_TEXTURE_2D);
		}
	}
}
