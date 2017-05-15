#include "MeshDrawComponent.h"
#include "GameObject.h"

MeshDrawComponent::MeshDrawComponent(Mesh* mesh) : DrawComponent()
{
	_mesh = mesh;
}

MeshDrawComponent::~MeshDrawComponent()
{
	// todo implement destructor
}

void MeshDrawComponent::Draw()
{
	if (_parent != nullptr) {
		_mesh->Draw(_parent->_position, _parent->_rotation,0.0f);
		// todo implement rotationAngle!
	}
}
