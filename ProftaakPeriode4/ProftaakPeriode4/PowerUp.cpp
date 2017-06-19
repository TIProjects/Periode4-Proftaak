#include "PowerUP.h"
#include <iostream>

PowerUp::PowerUp(float timeActive, PowerUpId id, std::string name)
{
	_resetTimer = timeActive;
	_id = id;
	_name = name;
}

void PowerUp::Update(float deltaTime)
{
	if (_timeActive == 0) return;
	if (_timeActive > 0)
	{
		std::cout << _timeActive << std::endl;
		_timeActive -= deltaTime;
		if (_timeActive <= 0)
		{
			DeActivate();
		}
	}
}

void PowerUp::Activate()
{
	if(_timeActive <= 0) Effect();
	_timeActive = _resetTimer;
	std::cout << _timeActive << std::endl;
}

void PowerUp::DeActivate()
{
	ReverseEffect();
}

void PowerUp::Effect()
{
}

void PowerUp::ReverseEffect()
{
}
