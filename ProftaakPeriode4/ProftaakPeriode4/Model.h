#pragma once

#include <vector>
#include "Player.h"

class Model {
	public:
		Model();
		void update(int timeDiff);

		std::vector<Player> _players;
};