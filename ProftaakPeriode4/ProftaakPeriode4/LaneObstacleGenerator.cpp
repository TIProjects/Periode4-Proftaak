#include "LaneObstacleGenerator.h"
#include <ostream>
#include <iostream>
#include <ctime>
#include "LaneObstacleComponent.h"
#include "CollisionComponent.h"
#include "ObstaclePatterns.h"
#include "LaneGeneratorComponent.h"

/**
 * Used for selecting a pattern, is placed here because of errors in usage (generator uses Pattern and Pattern uses generator)
 */
std::vector<ObstaclePattern *> patterns;
/**
 * The current/previous pattern used.. nullptr when no pattern is used
 */
ObstaclePattern * pattern;
ObstaclePattern * nextPattern;


LaneObstacleGenerator::LaneObstacleGenerator(std::vector<GameObject*> obstacleModels): Component(LANE_OBSTACLE_GENERATOR)
{
	_obstacleModels = obstacleModels;
	srand(time(nullptr));
	_lanes = nullptr;
	_obstacles = nullptr;
	pattern = nullptr;
	if (patterns.size() == 0) {
		patterns.push_back(new TwoPattern());
		patterns.push_back(new MovingPattern());
	}
}

void LaneObstacleGenerator::addObstacle(int laneIndex, GameObject* game_object, float speed)
{
	GameObject* obstacle = new GameObject(*game_object);
//	obstacle->AddComponent(game_object->_drawComponent);
	LaneObstacleComponent * component = new LaneObstacleComponent(laneIndex);
	if(speed != 0.0f)
		component->_speed = speed;
	obstacle->AddComponent(component);
//	obstacle->AddComponent(new CollisionComponent(Hitbox({1.0f,1.0f,1.0f}), false));

	GameObject* lane = (*_lanes)[laneIndex];
	float heightOffset = 0.0f;
	LaneComponent * lane_component = dynamic_cast<LaneComponent*>(lane->GetComponent(LANE_COMPONENT));


	obstacle->_position = {
		lane->_position.x,
		lane->_position.y + heightOffset + gameObjectSize(lane)[0]/2,
		-lane_component->getLength()};
	_obstacles->push_back(obstacle);


	for (int i = 0; i < laneAmountSkipped.size(); i++)
		if (i == laneIndex)
			laneAmountSkipped[i] = 0;
		else
			laneAmountSkipped[i] += 1;
	
}

GameObject * LaneObstacleGenerator::getRandomGameObject()
{
	return _obstacleModels[rand() % _obstacleModels.size()];
}

float* LaneObstacleGenerator::gameObjectSize(GameObject* game_object)
{
	float * sizes = new float[3]{ 0.0f,0.0f,0.0f };
	MeshDrawComponent * meshDraw = dynamic_cast<MeshDrawComponent*>(game_object->GetComponent(DRAW_COMPONENT));
	if (meshDraw != nullptr) {
		sizes[0] = meshDraw->_mesh->_height;
		sizes[1] = meshDraw->_mesh->_length;
		sizes[2] = meshDraw->_mesh->_width;
	}
	return sizes;
}

void LaneObstacleGenerator::Update(float nanotime)
{
	LaneGeneratorComponent* component = dynamic_cast<LaneGeneratorComponent*>(_parent->GetComponent(DRAW_COMPONENT));
	if (component != nullptr)
	{
		_lanes = &component->_lanes;
		_obstacles = &component->_obstacles;

		if (laneAmountSkipped.size() < component->_lanes.size())
			for (int i = 0; i < component->_lanes.size(); i++)
				laneAmountSkipped.push_back(0);

		for(int i = 0; i < component->_lanes.size(); i++)
		{
			if (_lengthMovedSince.size() <= i)
				_lengthMovedSince.push_back(0.0f);
			_lengthMovedSince[i] += nanotime * _speed;
		}



		GameObject* obstacleMesh = getRandomGameObject(); // todo implement multiple meshes
		MeshDrawComponent* meshDraw = dynamic_cast<MeshDrawComponent*>(component->_player->GetComponent(DRAW_COMPONENT));
		float minNeeded = meshDraw->_mesh->_length + gameObjectSize(obstacleMesh)[1] + _minimalDistanceBetween;
//		float minNeeded = obstacleMesh->_length;// for testing purposes

		if(_minimalDistanceBetween > 0.0f)
			_minimalDistanceBetween -= nanotime/20.0;
//		std::cout << _minimalDistanceBetween << std::endl;


		float minNeededPattern = minNeeded;
		if (nextPattern != nullptr) {
			GameObject * laneObject = (*_lanes)[nextPattern->_newLane];
			LaneComponent * lane_component = dynamic_cast<LaneComponent*>(laneObject->GetComponent(LANE_COMPONENT));
			if (lane_component != nullptr) {
				float speed = 9.0f;
//				if (nextPattern != nullptr && nextPattern->_speed >= 0.0f)
//					speed = nextPattern->_speed;
				if (pattern != nullptr) {
					minNeededPattern = pattern->getLengthAfter(speed, lane_component->getLength());
				}
			}
		}

		if (pattern != nullptr  && _lengthMovedSince[pattern->_newLane] / minNeededPattern < 1.0f) // so wait for pattern to end
		{
			int newLane = getNewLane();
			while (newLane == pattern->_newLane)
				newLane = rand() % (*_lanes).size();
			if (_lengthMovedSince[newLane] / minNeeded >= 1.0f) //&& rand() % 100 >= 50) // todo add randomness
			{
				std::cout << minNeededPattern << " - " << _lengthMovedSince[pattern->_newLane] << std::endl;
//				std::cout << "NORMAL " << _lengthMovedSince[pattern->_newLane] / minNeededPattern << std::endl;
				addObstacle(newLane, obstacleMesh);
				for (int i = 0; i < component->_lanes.size(); i++)
					if (i != pattern->_newLane)
						_lengthMovedSince[i] = 0;
				lastLane = newLane;
			}
		}
		else {
			int newLane;
			if (nextPattern != nullptr)
				newLane = nextPattern->_newLane;
			else
				newLane = getNewLane();
			if (_lengthMovedSince[newLane] / minNeededPattern >= 1.0f) {
				if (nextPattern != nullptr) {
//					std::cout << "PATTERN " << newLane << std::endl;
					nextPattern->Execute(this);
					pattern = nextPattern;
					lastLane = nextPattern->_newLane;
					nextPattern = nullptr;
				}
				else {
//					std::cout << "RANDOM " << newLane << std::endl;
					if (_lengthMovedSince[newLane] / minNeeded >= 1.0f) //&& rand() % 100 >= 50) // todo add randomness
					{
						addObstacle(newLane, obstacleMesh);
						for (int i = 0; i < component->_lanes.size(); i++)
							_lengthMovedSince[i] = 0;

						lastLane = newLane;

						float patternChange = float(rand() % 100) / 100.0f;
						float used = 0.0f;
						for (ObstaclePattern* aPattern : patterns)
							if (patternChange - (aPattern->change + used) <= 0.0f) {
								nextPattern = aPattern;
								nextPattern->_newLane = getNewLane();
								nextPattern->Init(this);
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
	// randomly select the new lane
	int newLane = rand() % (*_lanes).size();
	for (int i = 0; i < laneAmountSkipped.size(); i++)
		if (laneAmountSkipped[i] > maxSkip) // check if randomly chosen lane can be used or..
			newLane = i;					// a lane that has a lot of empty places
	return newLane;
}

//			todo implmement the minNeeded when switching multiple lanes
//			int laneMove = lastLane - newLane;
//			if (abs(laneMove) > 1)
//				minNeeded = laneMove*meshDraw->_mesh->_length;