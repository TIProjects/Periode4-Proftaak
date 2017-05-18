#include "LaneGeneratorComponent.h"
#include <iostream>
#include <queue>


LaneObstacle::LaneObstacle(Mesh* mesh, float place)
{
	_position = place;
	_mesh = mesh;
	std::cout << place << std::endl;
}

Lane::Lane(int lengthAmount, std::vector<Mesh*> meshes)
{
	srand(time(nullptr));
	_meshes = meshes;
	for (int i = 0; i < lengthAmount; i++)
		_queue.push_back(RandomMesh());
	
}

void Lane::Draw(float width)
{
	Vec3f rotation;
	float rotationAngle = 0.0f;

	for (int i = 0; i < _queue.size(); i++)
	{
		Mesh* drawObject = _queue[i];
		Vec3f position = Vec3f(width, 0.0f, -(drawObject->_length * i) + _lengthMoved);
		drawObject->Draw(position, rotation, rotationAngle); // draw lane-mesh

		for (int o = 0; o < _obstacles.size(); o++)
		{
			LaneObstacle * obstacle = _obstacles[o];
			Vec3f obstaclePosition = Vec3f(width, 1.0f,(-getLength()*obstacle->_position) + obstacle->_lengthMoved - (drawObject->_length));
	
			if (obstaclePosition.x >= (position.x - drawObject->_width) && obstaclePosition.x <= (position.x + drawObject->_width)
					&& obstaclePosition.z <= (position.z + drawObject->_length) && obstaclePosition.z >= (position.z - drawObject->_length))
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

float Lane::getLength()
{
	float length = 0;
	for (int i = 0; i < _queue.size(); i++)
		length += _queue[i]->_length;
	return length;
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
		_lanes.at(i)->Update(deltaTime);
	}
}

void LaneGeneratorComponent::PlaceObstacleFullyRandom(Mesh* mesh)
{
	srand(time(nullptr)); // set fully random (on time)
	if (_lanes.size() == 0) // do nothing when no lanes visible
		return;
	_lanes[rand() % _lanes.size()]->_obstacles.push_back(new LaneObstacle(mesh, (float)(rand() % 100 / 100.0)));
}

void Lane::Update(float deltatime)
{
	_lengthMoved += deltatime*_speed;
	Mesh* mesh = _queue.front();
	if (_lengthMoved > mesh->_length) // check if first mesh can be shifted to the back
	{
		_queue.pop_front();
		_queue.push_back(RandomMesh()); // add new to back
		_lengthMoved = 0;
	}
	for (int i = 0; i < _obstacles.size(); i++)
	{
		LaneObstacle * obstacle = _obstacles[i];
		obstacle->_lengthMoved += deltatime*obstacle->_speed;
		if(obstacle->_lengthMoved > (getLength()*obstacle->_position + ((getLength()/_queue.size())*2)))
			_obstacles.erase(_obstacles.begin() + i);
		
	}
}
