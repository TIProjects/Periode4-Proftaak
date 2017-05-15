#include "LaneGeneratorComponent.h"
#include <iostream>
#include <queue>


LaneObstacle::LaneObstacle(Mesh* mesh, float place)
{
	_position = place;
	_mesh = mesh;
}

Lane::Lane(int lengthAmount, std::vector<Mesh*> meshes)
{
	_meshes = meshes;
	for (int i = 0; i < lengthAmount; i++)
		_queue.push_back(RandomMesh());
	
}

void Lane::Draw(float width)
{
	Vec3f rotation;
	float rotationAngle = 0.0f;

	Mesh* mesh = _queue.front();
	if (_lengthMoved > mesh->_length) // check if first mesh can be shifted to the back
	{
		_queue.pop_front();
		_queue.push_back(RandomMesh()); // add new to back
		_lengthMoved = 0;
		for (int i = 0; i < _obstacles.size(); i++)
		{
			_obstacles[i]->_position -= 1.0f / _queue.size();
			if (_obstacles[i]->_position < 0.0f)
				_obstacles.erase(_obstacles.begin() + i);
		}
	}

	for (int i = 0; i < _queue.size(); i++)
	{
		Mesh* drawObject = _queue[i];
		Vec3f position = Vec3f(width, 0.0f, -(drawObject->_length * i) + _lengthMoved);
		drawObject->Draw(position, rotation, rotationAngle); // draw lane-mesh
		for (int o = 0; o < _obstacles.size(); o++)
		{
			Vec3f obstaclePosition = Vec3f(width, 1.0f, -(_obstacles[o]->_mesh->_length * (_queue.size() * _obstacles[o]->_position)) + _lengthMoved);
			if (obstaclePosition.x > position.x - drawObject->_width && obstaclePosition.x < position.x + drawObject->_width
				&& obstaclePosition.z < position.z + drawObject->_length && obstaclePosition.z > position.z - drawObject->_length)
			{
				obstaclePosition.y = drawObject->_height; // set height of position to height of lane-mesh
				_obstacles[o]->_mesh->Draw(obstaclePosition, rotation, rotationAngle); // draw obstacle
			}
		}
	}
}

Mesh* Lane::RandomMesh()
{
	int index = rand() % _meshes.size();
	//		std::cout << index << std::endl;
	return _meshes.at(index);
}

float Lane::getWidth()
{
	float largest = 1;
	for (int i = 0; i < _queue.size(); i++)
		if (_queue[i]->_width > largest)
			largest = _queue[i]->_width;

	return largest;
}

LaneGeneratorComponent::LaneGeneratorComponent(int laneAmount, int laneSize, std::vector<Mesh*> meshes)
{
	for (int i = 0; i < laneAmount; i++) 
		_lanes.push_back(new Lane(laneSize,meshes));
}

LaneGeneratorComponent::~LaneGeneratorComponent()
{
}



void LaneGeneratorComponent::Draw()
{
	float alreadyDrawn = 0;
	for (int i = 0; i < _lanes.size(); i++) {
		_lanes.at(i)->Draw(alreadyDrawn + (i*_spaceBetween));
		alreadyDrawn += _lanes[i]->getWidth();
	}
}

void LaneGeneratorComponent::Update(float deltaTime)
{
	for (int i = 0; i < _lanes.size(); i++) {
		_lanes.at(i)->_lengthMoved += deltaTime*_speed;
	}
}
