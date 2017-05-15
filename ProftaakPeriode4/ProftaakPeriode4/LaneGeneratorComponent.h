#pragma once
#include "DrawComponent.h"
#include "Mesh.h"
#include <queue>
#include <ostream>
#include <iostream>

class LaneObstacle
{
public:
	LaneObstacle(Mesh*mesh, float place)
	{
		_place = place;
		_mesh = mesh;
	}
	float _place;
	Mesh* _mesh;
};

class Lane
{
public:
	Lane(std::vector<Mesh*> meshes)
	{
		_meshes = meshes;
		_lengthMoved = 0.0f;
		for (int i = 0; i < _lengthAmount; i++) {
			_queue.push_back(RandomMesh());
		}
	}

	void Draw(float width)
	{
		Vec3f rotation;
		float rotationAngle = 0.0f;

		Mesh * mesh = _queue.front();
		if (_lengthMoved > mesh->_length)
		{
			_queue.pop_front();
			_queue.push_back(RandomMesh()); // add new to back
			_lengthMoved = 0;
			for (int i = 0; i < _obstacles.size(); i++)
			{
				_obstacles[i]->_place -= 1.0f / _lengthAmount;
				if (_obstacles[i]->_place < 0.0f)
					_obstacles.erase(_obstacles.begin() +i);
			}
		}

		for (int i = 0; i < _queue.size(); i++)
		{
			Vec3f position = Vec3f(width+ _queue[i]->_width, 0.0f, -(_queue[i]->_length*i) + _lengthMoved);
			_queue[i]->Draw(position, rotation, rotationAngle);
			for (int o = 0; o < _obstacles.size(); o++)
			{
				Vec3f obstaclePosition = Vec3f(width, 1.0f, -(_obstacles[o]->_mesh->_length*(_lengthAmount*_obstacles[o]->_place)) + _lengthMoved);
				if (obstaclePosition.x > position.x-_queue[i]->_width && obstaclePosition.x < position.x + _queue[i]->_width  
					&& obstaclePosition.z < position.z + _queue[i]->_length && obstaclePosition.z > position.z - _queue[i]->_length) {
					obstaclePosition.y = _queue[i]->_height;
					_obstacles[o]->_mesh->Draw(obstaclePosition, rotation, rotationAngle);
				}
			}
		}
		
	}

	Mesh * RandomMesh()
	{
		int index = rand()%_meshes.size();
//		std::cout << index << std::endl;
		return _meshes.at(index);
	}
	// the mesh to show todo multiple meshes showed randomly
	std::vector<Mesh*> _meshes;

	// the amount already moved (automaticly lowered)
	float _lengthMoved;
	// the movement speed
	
	int _lengthAmount = 20; // todo refactor to lengthamount as distance and not amount
	deque<Mesh*> _queue;
	vector<LaneObstacle*> _obstacles;
};


/**
 * \brief Class for generating and showing lanes
 */
class LaneGeneratorComponent :
	public DrawComponent
{
public:
	/**
	 * \brief Constructor for creating a LaneGaneratorComponent
	 * \param laneAmount The amount of lanes to show
	 * \param mesh The mesh that will be drawn on the lanes
	 */
	LaneGeneratorComponent(int laneAmount, std::vector<Mesh*> meshes, Mesh * obstacle);

	/**
	 * \brief Destructor
	 * todo implement
	 */
	~LaneGeneratorComponent();
	
	/**
	 * \brief Draw the lanes
	 */
	void Draw() override;

	/**
	 * \brief Update the laneLogics (move the lanes)
	 * \param deltaTime The difference between the updates
	 */
	void Update(float deltaTime) override;

private:
	// the amount of lanes
	int _laneAmount;
	vector<Lane*> _lanes;
	float _speed = 8.5f;  // todo test accurate speed
						  // the space between the lanes
	float _spaceBetween = 2.0f;
	// the amount of lanes (in length) 
};

