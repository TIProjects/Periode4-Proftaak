#include "Mesh.h"
#include "GL/freeglut.h"



MaterialInfo::MaterialInfo()
{
	_texture = nullptr;
}

IndexedMesh::IndexedMesh()
{
	_width = 1.0f;
	_length = 1.0f;
	_height = 1.0f;
}


IndexedMesh::~IndexedMesh()
{
	// todo implement destructor
}


void IndexedMesh::Draw(Vec3f position, Vec3f rotation, float rotationAngle)
{
	glPushMatrix();

	glTranslatef(position.x, position.y, position.z);
	glRotatef(rotationAngle, rotation.x, rotation.y, rotation.z);


	for (IndexedObjGroup * group : _groups)
	{
		if (group->_materialIndex != -1 && _materials.at(group->_materialIndex)->_texture != nullptr) {
			glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D, _materials.at(group->_materialIndex)->_texture->_id);
		}
		glBegin(GL_TRIANGLES);

		for (Face face : group->_faces)
		{
			for (IndexedVertex vertex : face._vertices)
			{
				glTexCoord2fv(_texcoords[vertex._texcoord].v);
				glVertex3fv(_vertices[vertex._position].v);
			}
		}

		glEnd();
		glDisable(GL_TEXTURE_2D);
	}


	glPopMatrix();
}

Mesh::Group::Group(MaterialInfo* material)
{
	_material = material;
}

Mesh::Mesh()
{
	_width = 0;
	_length = 0;
	_height = 0;
}

Mesh::Mesh(const IndexedMesh * indexedMesh)
{
	_width = indexedMesh->_width;
	_length = indexedMesh->_length;
	_height = indexedMesh->_height;

	for(IndexedObjGroup * group : indexedMesh->_groups)
	{
		Group newGroup = Group(indexedMesh->_materials[group->_materialIndex]);

		for(Face face : group->_faces)
		{
			for(IndexedVertex indexedVertex : face._vertices)
			{
				Vertex newVertex = Vertex(
					indexedMesh->_vertices[indexedVertex._position], 
					indexedMesh->_texcoords[indexedVertex._texcoord], 
					indexedMesh->_normals[indexedVertex._normal]);

				newGroup._vertices.push_back(newVertex);
			}
		}

		_groups.push_back(newGroup);
	}
}

void Mesh::Draw(Vec3f position, Vec3f rotation, float rotationAngle)
{

	glEnable(GL_TEXTURE_2D);

	glPushMatrix();

	glTranslatef(position.x, position.y, position.z);
	glRotatef(rotationAngle, rotation.x, rotation.y, rotation.z);

	for(Group group : _groups)
	{
		glEnableClientState(GL_VERTEX_ARRAY);
		glEnableClientState(GL_NORMAL_ARRAY);
		glEnableClientState(GL_TEXTURE_COORD_ARRAY);

		glBindTexture(GL_TEXTURE_2D, group._material->_texture->_id);

		glVertexPointer(3, GL_FLOAT, sizeof(float) * 8, ((float*)group._vertices.data()));
		glNormalPointer(GL_FLOAT, sizeof(float) * 8, ((float*)group._vertices.data()) + 5);
		glTexCoordPointer(2, GL_FLOAT, sizeof(float) * 8, ((float*)group._vertices.data()) + 3);

		glDrawArrays(GL_TRIANGLES, 0, GLsizei(group._vertices.size()));

		glDisableClientState(GL_TEXTURE_COORD_ARRAY);
		glDisableClientState(GL_NORMAL_ARRAY);
		glDisableClientState(GL_VERTEX_ARRAY);

	}

	glDisable(GL_TEXTURE_2D);

	glPopMatrix();
}

