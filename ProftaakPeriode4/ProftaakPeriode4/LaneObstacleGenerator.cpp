#include "LaneObstacleGenerator.h"
#include <ostream>
#include <iostream>
#include <ctime>
#include "LaneObstacleComponent.h"
#include "CollisionComponent.h"
#include "ObstaclePatterns.h"
#include "LaneGeneratorComponent.h"
#include "AsteroidComponent.h"
#include "PowerUpComponent.h"
#include "RotateComponent.h"

/**
 * Used for selecting a pattern, is placed here because of errors in usage (generator uses Pattern and Pattern uses generator)
 */
std::vector<ObstaclePattern *> patterns;
/**
 * The current/previous pattern used.. nullptr when no pattern is used
 */
ObstaclePattern * pattern;
/**
 * The next pattern that is going to be used (nullptr when using random obstacle)
 */
ObstaclePattern * nextPattern;

Mesh * nextMesh;
Mesh * prevMesh;

LaneObstacleGenerator::LaneObstacleGenerator(std::vector<Mesh*> obstacleModelsAsteroid, std::vector<Mesh*> obstacleModelsNormal, std::vector<Mesh*> obstacleModelsPowerUp) : Component(LANE_OBSTACLE_GENERATOR)
{
	_obstacleModelsNormal = obstacleModelsNormal;
	_obstacleModelsAsteroid = obstacleModelsAsteroid;
	_obstacleModelsPowerUp = obstacleModelsPowerUp;

	srand(time(nullptr));
	_lanes = nullptr;
	_obstacles = nullptr;
	_speed = nullptr;
	pattern = nullptr;

	// init default patterns...
	if (patterns.size() == 0) {
		patterns.push_back(new TwoPattern());
		patterns.push_back(new MovingPattern());
	}
}
void LaneObstacleGenerator::addObstacle(int laneIndex, Mesh * mesh_object, float speed)
{
	GameObject* obstacle = new GameObject(_parent->_parentList);
	obstacle->AddComponent(new MeshDrawComponent(mesh_object));
	LaneObstacleComponent * component = new LaneObstacleComponent(laneIndex);
	

	component->_speed = speed;
	component->_laneSpeed = _speed;

	obstacle->AddComponent(component);
	
	if(std::find(_obstacleModelsAsteroid.begin(), _obstacleModelsAsteroid.end(), mesh_object) != _obstacleModelsAsteroid.end())
		obstacle->AddComponent(new AsteroidComponent());

	if (std::find(_obstacleModelsPowerUp.begin(), _obstacleModelsPowerUp.end(), mesh_object) != _obstacleModelsPowerUp.end()) {
		RotateComponent * rotateComp = new RotateComponent({ 0.0f,10.0f,0.0f });
		obstacle->AddComponent(rotateComp);
	}
	obstacle->AddComponent(new CollisionComponent(Hitbox({ mesh_object->_width,mesh_object->_height,mesh_object->_length }), false));
	

	GameObject* lane = (*_lanes)[laneIndex];
	float heightOffset = 1.0f;
	LaneComponent * lane_component = dynamic_cast<LaneComponent*>(lane->GetComponent(LANE_COMPONENT));


	obstacle->_position = {
		lane->_position.x,
		lane->_position.y + heightOffset + mesh_object->_height /2,
		-lane_component->getLength()};
	_obstacles->push_back(obstacle);


	for (int i = 0; i < laneAmountSkipped.size(); i++)
		if (i == laneIndex)
			laneAmountSkipped[i] = 0;
		else
			laneAmountSkipped[i] += 1;

	prevMesh = mesh_object;
	nextMesh = nullptr;
}



Mesh * LaneObstacleGenerator::getRandomMeshObject()
{
	int randomPercentage = rand() % 100;

	if (randomPercentage <= 95)
		return _obstacleModelsAsteroid[rand() % _obstacleModelsAsteroid.size()];
	if (randomPercentage <= 98)
		return _obstacleModelsNormal[rand() % _obstacleModelsNormal.size()];
	return _obstacleModelsPowerUp[rand() % _obstacleModelsPowerUp.size()];
}



void LaneObstacleGenerator::Update(float nanotime)
{
	LaneGeneratorComponent* component = dynamic_cast<LaneGeneratorComponent*>(_parent->GetComponent(DRAW_COMPONENT));
	if (component != nullptr)
	{
		_lanes = &component->_lanes;
		_obstacles = &component->_obstacles;
		_speed = &component->_speed;

		if (laneAmountSkipped.size() < component->_lanes.size())
			for (int i = 0; i < component->_lanes.size(); i++)
				laneAmountSkipped.push_back(0);

		for (int i = 0; i < component->_lanes.size(); i++)
		{
			if (_lengthMovedSince.size() <= i)
				_lengthMovedSince.push_back(0.0f);
			_lengthMovedSince[i] += nanotime * *_speed;
		}


		if (nextMesh == nullptr) {
			nextMesh = getRandomMeshObject();
		}

		// get lane lenght
		MeshDrawComponent* meshDraw = dynamic_cast<MeshDrawComponent*>(component->_player->GetComponent(DRAW_COMPONENT));
		float meshDrawSize = 0.0f;
		if (meshDraw != nullptr)
			meshDrawSize = meshDraw->_mesh->_length;
		
		//calculate min needed size
		
		float prevOffset = 0.0f;
		if (prevMesh != nullptr)
			prevOffset = prevMesh->_length;
		float minNeeded = meshDrawSize + prevOffset + _minimalDistanceBetween;

		// lower the size for the next update
		if(_minimalDistanceBetween > 0.0f)
			_minimalDistanceBetween -= nanotime/40.0;


		float minNeededPattern = minNeeded;
		int newLane;
		if (nextPattern != nullptr)
			newLane = nextPattern->_newLane;
		else
			newLane = getNewLane();

		GameObject * laneObject = (*_lanes)[newLane];
		LaneComponent * lane_component = dynamic_cast<LaneComponent*>(laneObject->GetComponent(LANE_COMPONENT));
		if (lane_component != nullptr) {
			float speed = *_speed;
			if (nextPattern != nullptr && nextPattern->_speed != -1.0f)
				speed = nextPattern->_speed;
			if (pattern != nullptr) {
				float length = pattern->getLengthAfter(speed, lane_component->getLength());
				if (length != 0.0f) {
					minNeededPattern = length;
				}
			}
		}
		

		if (minNeededPattern != 0.0f && pattern != nullptr && _lengthMovedSince[pattern->_newLane] < minNeededPattern) {
				newLane = getNewLane();
				while (newLane == pattern->_newLane)
					newLane = rand() % (*_lanes).size();
				if (_lengthMovedSince[newLane] / minNeeded >= 1.0f)
				{
					addObstacle(newLane, nextMesh);
					for (int i = 0; i < component->_lanes.size(); i++)
						if (i != pattern->_newLane)
							_lengthMovedSince[i] = 0;
					lastLane = newLane;
				}
		}
		else {
			if (nextPattern != nullptr)
				newLane = nextPattern->_newLane;
			else
				newLane = getNewLane();


			if (_lengthMovedSince[newLane] >= minNeededPattern) {
				if (nextPattern != nullptr) {
					nextPattern->Execute(this, nextMesh);
					pattern = nextPattern;
					lastLane = nextPattern->_newLane;
					nextPattern = nullptr;
				} else {
					
					if (_lengthMovedSince[newLane] >= minNeeded)
					{
						pattern = nullptr;
						addObstacle(newLane, nextMesh);
						lastLane = newLane;
						nextPattern = nullptr;
						float patternChange = float(rand() % 100) / 100.0f;
						float used = 0.0f;
						for (ObstaclePattern* aPattern : patterns) {
							if (patternChange < aPattern->change + used && patternChange > used) {
								nextPattern = aPattern;
								nextPattern->_newLane = getNewLane();
								nextPattern->Init(this);
							}
							used += aPattern->change;
						}

					}
				}
				for (int i = 0; i < component->_lanes.size(); i++) {
					_lengthMovedSince[i] = 0;
				}
			}
		}


		
		
	}
}

int LaneObstacleGenerator::getNewLane()
{
	int newLane = rand() % (*_lanes).size();
	for (int i = 0; i < laneAmountSkipped.size(); i++)
		if (laneAmountSkipped[i] > maxSkip) // check if randomly chosen lane can be used or..
			newLane = i;					// a lane that has a lot of empty places
	return newLane;
}