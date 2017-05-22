#include "LaneObstacleComponent.h"
#include "LaneComponent.h"
#include <ctime>
#include "Mesh.h"

void LaneComponent::Update(float deltatime)
{
	_lengthMoved += deltatime*_speed;
	Mesh* mesh = _queue.front();
	if (_lengthMoved > mesh->_length) // check if first mesh can be shifted to the back
	{
		_queue.pop_front();
		_queue.push_back(RandomMesh()); // add new to back
		_lengthMoved = 0;
	}
}

LaneComponent::LaneComponent(int lengthAmount, std::vector<Mesh*> meshes)
	: Component(LANE_COMPONENT)
{
	srand(time(nullptr));
	_meshes = meshes;
	for (int i = 0; i < lengthAmount; i++)
		_queue.push_back(RandomMesh());

}

void LaneComponent::Draw()
{
	Vec3f rotation;
	float rotationAngle = 0.0f;

	for (int i = 0; i < _queue.size(); i++)
	{
		Mesh* drawObject = _queue[i];
		Vec3f position = Vec3f(_parent->_position.x, _parent->_position.y, -(drawObject->_length * i) + _lengthMoved);
		drawObject->Draw(position, rotation, rotationAngle); // draw lane-mesh
	}
}

Mesh* LaneComponent::RandomMesh()
{
	int index = rand() % _meshes.size();
	return _meshes.at(index);
}

float LaneComponent::getWidth()
{
	float largest = 1;
	for (int i = 0; i < _queue.size(); i++)
		if (_queue[i]->_width > largest)
			largest = _queue[i]->_width;

	return largest;
}

float LaneComponent::getLength()
{
	float length = 0;
	for (int i = 0; i < _queue.size(); i++)
		length += _queue[i]->_length;
	return length;
}