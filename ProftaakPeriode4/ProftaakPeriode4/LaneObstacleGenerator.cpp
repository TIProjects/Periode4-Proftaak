#include "LaneObstacleGenerator.h"
#include <ostream>
#include <iostream>
#include <ctime>
#include "LaneObstacleComponent.h"
#include "CollisionComponent.h"
#include "ObstaclePatterns.h"
#include "LaneGeneratorComponent.h"

std::vector<ObstaclePattern *> patterns;
ObstaclePattern * pattern;


LaneObstacleGenerator::LaneObstacleGenerator(std::vector<Mesh*> meshes): Component(LANE_OBSTACLE_GENERATOR)
{
	_meshes = meshes;
	srand(time(nullptr));

	patterns.push_back(new TwoPattern());
	patterns.push_back(new MovingPattern());
}

void LaneObstacleGenerator::addObstacle(int laneIndex, Mesh* mesh, float speed)
{
	GameObject* obstacle = new GameObject(_obstacles);
	obstacle->AddComponent(new MeshDrawComponent(mesh));
	LaneObstacleComponent * component = new LaneObstacleComponent(laneIndex);
	if(speed != 0.0f)
		component->_speed = speed;
	obstacle->AddComponent(component);
	obstacle->AddComponent(new CollisionComponent(Hitbox({1.0f,1.0f,1.0f}), false));

	GameObject* lane = (*_lanes)[laneIndex];
	//		LaneComponent * laneComponent = dynamic_cast<LaneComponent*>(lane->GetComponent(LANE_COMPONENT));
	//	
	float heightOffset = 0.0f;
	//		if (laneComponent != nullptr)
	//			heightOffset = laneComponent->_mesh->_height;

	obstacle->_position = {
		lane->_position.x,
		lane->_position.y + heightOffset + mesh->_height / 2,
		-100.0f};
	_obstacles->push_back(obstacle);


	for (int i = 0; i < laneAmountSkipped.size(); i++)
		if (i == laneIndex)
			laneAmountSkipped[i] = 0;
		else
			laneAmountSkipped[i] += 1;
	
}

void LaneObstacleGenerator::Update(float nanotime)
{
	_lengthMovedSince += nanotime * _speed;


	LaneGeneratorComponent* component = dynamic_cast<LaneGeneratorComponent*>(_parent->GetComponent(DRAW_COMPONENT));
	if (component != nullptr)
	{
		_lanes = &component->_lanes;
		_obstacles = &component->_obstacles;

		if (laneAmountSkipped.size() < component->_lanes.size())
			for (int i = 0; i < component->_lanes.size(); i++)
				laneAmountSkipped.push_back(0);


		Mesh* obstacleMesh = _meshes[0];
		MeshDrawComponent* meshDraw = dynamic_cast<MeshDrawComponent*>(component->_player->GetComponent(DRAW_COMPONENT));
		float minNeeded = meshDraw->_mesh->_length + obstacleMesh->_length + _minimalDistanceBetween;
//		float minNeeded = obstacleMesh->_length; for testing

		

		int newLane = rand() % component->_lanes.size();
		for (int i = 0; i < laneAmountSkipped.size(); i++)
		{
			if (laneAmountSkipped[i] > maxSkip)
			{
				newLane = i;
			}
		}

		if (pattern != nullptr)
		{
			minNeeded += pattern->getLength();
		}

		

			
	
		if (_lengthMovedSince / minNeeded >= 1.0f && float(rand() % 100) >= distance)
		{
			// check if pattern used or random
			float patternChange = float(rand() % 100) / 100.0f;
			float used = 0.0f;
			pattern = nullptr;
			for (ObstaclePattern* aPattern : patterns)
				if (patternChange - (aPattern->change + used) <= 0.0f) {
					pattern = aPattern;
				}

			if (pattern == nullptr)
				addObstacle(newLane, _meshes[0]);
			else {
				pattern->Init(this, newLane);
				pattern->Execute(this, newLane);
			}
			_lengthMovedSince = 0;
			lastLane = newLane;
		}

		if (distance > 0)
			distance -= 0.01f;
	}
}

//			int laneMove = lastLane - newLane;
//			if (abs(laneMove) > 1)
//				minNeeded = laneMove*meshDraw->_mesh->_length;