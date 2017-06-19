#include "LaneGeneratorComponent.h"
#include "SpeedDown.h"

SpeedDown::SpeedDown(GameObject * parent) : PowerUp(10.0f, SPEED_DOWN, "Speed down")
{
	_parent = parent;
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
