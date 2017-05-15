#include "LaneGeneratorComponent.h"
#include <iostream>
#include <queue>


LaneGeneratorComponent::LaneGeneratorComponent(int laneAmount, std::vector<Mesh*> meshes, Mesh * obstacle)
{
	_laneAmount = laneAmount;
	for (int i = 0; i < _laneAmount; i++) {
		_lanes.push_back(new Lane(meshes));
	}
	_lanes[0]->_obstacles.push_back(new LaneObstacle(obstacle,0.5f));
	_lanes[0]->_obstacles.push_back(new LaneObstacle(obstacle, 1.0f));
	_lanes[0]->_obstacles.push_back(new LaneObstacle(obstacle, 0.1f));
}

LaneGeneratorComponent::~LaneGeneratorComponent()
{
}



void LaneGeneratorComponent::Draw()
{
	for (int i = 0; i < _laneAmount; i++) {
		_lanes.at(i)->Draw(i*_spaceBetween);
	}
}

void LaneGeneratorComponent::Update(float deltaTime)
{
	for (int i = 0; i < _laneAmount; i++) {
		_lanes.at(i)->_lengthMoved += deltaTime*_speed;
	}
}
