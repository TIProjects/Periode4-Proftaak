#pragma once
#include <vector>
#include "GameObject.h"
#include "Component.h"
#include "MeshDrawComponent.h"


class LaneObstacleGenerator : public Component
{
	


public:
	LaneObstacleGenerator(std::vector<Mesh*> meshes);


	void addObstacle(int laneIndex, Mesh* mesh, float speed = 0.0f);

	float _lengthMovedSince = 0.0f;
	float _minimalDistanceBetween = 0.0f;
	float _maximalDistanceBetween = 5.0f;
	float _speed = 9.0f;//&component->_speed;
	int lastLane = 0;
	float distance = 0.9f;
	std::vector<Mesh*> _meshes;
	std::vector<GameObject*> * _lanes;
	std::vector<GameObject*> * _obstacles;

	std::vector<int> laneAmountSkipped;
	int maxSkip = 3;


	void Update(float nanotime) override;
};
