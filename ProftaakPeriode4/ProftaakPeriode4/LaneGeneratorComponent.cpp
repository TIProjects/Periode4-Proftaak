#include "LaneGeneratorComponent.h"
#include <iostream>
#include <queue>


LaneGeneratorComponent::LaneGeneratorComponent(int laneAmount, Mesh* mesh, Mesh* other)
{
	_laneAmount = laneAmount;
	_mesh = mesh;
	_lengthMoved = 0.0f;
	for (int i = 0; i < _lengthAmount; i++) {
		if(i % 2 == 0)
		{
			_queue.push_back(other);
		} {
			_queue.push_back(mesh);
		}
	}
	
}

LaneGeneratorComponent::~LaneGeneratorComponent()
{
}



void LaneGeneratorComponent::Draw()
{
	Vec3f rotation;
	float rotationAngle = 0.0f;
//	
//
//	for (int x = 0; x <= _lengthAmount; x++) {
//		float widthSpent = 0.0f;
//		int removed = 0;
//		for (int i = 0; i < _laneAmount; i++)
//		{
//			
//			Vec3f position = Vec3f(widthSpent, 0.0f, -(_mesh->_length*x) + _lengthMoved);
//			
//			if (position.z < 0.0f)
//				_mesh->Draw(position, rotation, rotationAngle);
//			else {
//				_lengthMoved -= _mesh->_length;
//				removed = 1;
//			}
//			widthSpent += _mesh->_width + _spaceBetween;
//		}
//		
//		_lengthMoved += removed*_mesh->_length;
//	}

	Mesh * mesh = _queue.front();
	if(_lengthMoved > mesh->_length)
	{
		_queue.pop_front();
		_queue.push_back(_mesh); // add new to back
		_lengthMoved = 0;
	}

	for(int i = 0; i < _queue.size(); i++)
	{
		Vec3f position = Vec3f(0.0f, 0.0f, -(_mesh->_length*i) + _lengthMoved);
		_queue[i]->Draw(position, rotation, rotationAngle);
	}
	
}

int LaneGeneratorComponent::totalQueuesize()
{
	int size = 0;
	for(int i = 0; i < _queue.size(); i++)
	{
		size += _queue[0]->_length;
	}
	return size;
}

void LaneGeneratorComponent::Update(float deltaTime)
{
	_lengthMoved += deltaTime*_speed;
}
