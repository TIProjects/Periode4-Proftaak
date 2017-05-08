#pragma once

#include <vector>
#include "Player.h"

class Model {
	public:
		Model();

		int getDeltaTime(const int* delta);
		void update();

		int deltaTime;
		int lastTime;
		std::vector<Player> _players;
};