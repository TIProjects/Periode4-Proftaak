#include "Player.h"

Player::Player(std::vector<Matrix3GLf> vertices, int laneIndex) : GameObject(vertices)
{
	_laneIndex = laneIndex;
}
