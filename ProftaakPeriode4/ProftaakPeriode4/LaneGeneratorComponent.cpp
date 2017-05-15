#include "LaneGeneratorComponent.h"
#include <iostream>


LaneGeneratorComponent::LaneGeneratorComponent(int laneAmount, Mesh* mesh)
{
	_laneAmount = laneAmount;
	_mesh = mesh;
	_lengthMoved = 0.0f;
}

LaneGeneratorComponent::~LaneGeneratorComponent()
{
}



void LaneGeneratorComponent::Draw()
{
	Vec3f rotation;
	float rotationAngle = 0.0f;
	

	for (int x = 0; x <= _lengthAmount; x++) {
		float widthSpent = 0.0f;
		int removed = 0;
		for (int i = 0; i < _laneAmount; i++)
		{
			Vec3f position = Vec3f(widthSpent, 0.0f, -(_mesh->_length*x) + _lengthMoved);
			if (position.z < 0.0f)
				_mesh->Draw(position, rotation, rotationAngle);
			else {
				_lengthMoved -= _mesh->_length;
				removed = 1;
			}
			widthSpent += _mesh->_width + _spaceBetween;
		}
		_lengthMoved += removed*_mesh->_length;
	}
}

void LaneGeneratorComponent::Update(float deltaTime)
{
	_lengthMoved += deltaTime*_speed;
}
