#pragma once

#include <vector>

class Model {
	public:
		Model();

		int getDeltaTime(const int* delta);
		void update();

		int deltaTime;
		int lastTime;
};