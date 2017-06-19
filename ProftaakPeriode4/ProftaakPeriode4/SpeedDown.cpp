#include "LaneGeneratorComponent.h"
#include "SpeedDown.h"

SpeedDown::SpeedDown(GameObject * parent) : PowerUp(40.0f, SPEED_DOWN, "Speed down")
{
	_parent = parent;
	_speedDif = 6.0f;
}

void SpeedDown::Effect()
{
    auto tempList = *_parent->_parentList;
    for (auto go : tempList)
    {
        LaneGeneratorComponent* lgc = dynamic_cast<LaneGeneratorComponent*>(go->GetComponent(DRAW_COMPONENT));
		if (lgc != nullptr)
		{
			lgc->_speed -= _speedDif;
			return;
		}
    }
}

void SpeedDown::ReverseEffect()
{
    auto tempList = *_parent->_parentList;
    for (auto go : tempList)
    {
		LaneGeneratorComponent* lgc = dynamic_cast<LaneGeneratorComponent*>(go->GetComponent(DRAW_COMPONENT));
		if (lgc != nullptr)
		{
			lgc->_speed += _speedDif;
			return;
		}
    }
}
