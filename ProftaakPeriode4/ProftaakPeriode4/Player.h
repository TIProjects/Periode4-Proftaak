#pragma once
#include "GameObject.h"

class Player : public GameObject {
	public:
		Player(std::vector<Matrix3GLf> vertices, int laneIndex);
		int _laneIndex;
};
