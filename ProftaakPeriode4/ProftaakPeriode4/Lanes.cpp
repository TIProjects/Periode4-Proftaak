#include "Lanes.h"

Lane::Lane(std::vector<Matrix3GLf> vertices) : GameObject(vertices)
{
	
}

bool Lane::addObject(GameObject * gameObject)
{	
	if(isInLane(gameObject) == -1)
	{
		_gameObjects.push_back(gameObject);
		return true;
	}
	
	return false;
}

bool Lane::removeObject(GameObject * gameObject)
{
	int index = isInLane(gameObject);

	if(index != -1)
	{
		_gameObjects.erase(_gameObjects.begin() + index);
		return true;
	} 

	return false;
}

int Lane::isInLane(GameObject* gameObject)
{
	for(int i = 0; i < _gameObjects.size(); i++)
	{
		if(_gameObjects[i] == gameObject)
		{
			return i;
		}
	}

	return -1;
}

Lanes::Lanes(int count)
{
	std::vector<Matrix3GLf> vertices;
	vertices.push_back(Matrix3GLf( 0.0f,  0.0f, 0.0f   ));
	vertices.push_back(Matrix3GLf( 10.0f, 0.0f, 0.0f   ));
	vertices.push_back(Matrix3GLf( 10.0f, 0.0f, -50.0f ));
	vertices.push_back(Matrix3GLf( 0.0f,  0.0f, -50.0f ));

	// Assign members
	_count = count;

	Matrix3GLf basePosition = Matrix3GLf(10.0f, 0.0f, 0.0f);

	// Fill the list of lanes
	for(int i = 0; i < count; i++)
	{
		basePosition.x += (i * 10.0f) + 4.0f;

		Lane lane = Lane(vertices);
		lane.setPosition(basePosition);

		_lanes.push_back(lane);

	}
}

void Lanes::update()
{
	// TODO update
}
