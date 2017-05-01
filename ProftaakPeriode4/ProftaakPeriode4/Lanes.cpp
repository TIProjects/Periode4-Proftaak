#include "Lanes.h"

bool Lane::addObject()
{	
	return false;
}

bool Lane::removeObject()
{
	return false;
}

Lanes::Lanes(Lane * lanes, int count)
{
	_lanesPtr = lanes;

	_count = count;
}

void Lanes::update()
{
}
