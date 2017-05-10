#pragma once
#include "DrawComponent.h"
#include "Mesh.h"

class LaneGeneratorComponent :
	public DrawComponent
{
public:
	LaneGeneratorComponent(int laneAmount, Mesh * mesh);
	~LaneGeneratorComponent();
	void Draw() override;
	void Update(float deltaTime) override;

private:
	Mesh * _mesh;
	int _laneAmount;
	float _lengthMoved;
	float _speed = 7.5f; // todo test accurate speed
	float _spaceBetween = 1.0f;
	int _lengthAmount = 20;
};

