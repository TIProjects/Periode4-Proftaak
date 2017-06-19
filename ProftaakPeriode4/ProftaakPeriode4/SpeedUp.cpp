#include "SpeedUp.h"
#include "LaneGeneratorComponent.h"

SpeedUp::SpeedUp(GameObject* parent) : PowerUp(30.0f, SPEED_UP, "Speed boost")
{
	_parent = parent;
} 

void SpeedUp::Effect()
{
    auto tempList = *_parent->_parentList;
    for (auto go : tempList)
    {
		LaneGeneratorComponent* lgc = dynamic_cast<LaneGeneratorComponent*>(go->GetComponent(DRAW_COMPONENT));
		if (lgc != nullptr)
		{
			lgc->_speed += _speedDifUp;
			return;
		}
    }
}

void SpeedUp::ReverseEffect()
{
	auto tempList = *_parent->_parentList;
    for (auto go : tempList)
    {
		LaneGeneratorComponent* lgc = dynamic_cast<LaneGeneratorComponent*>(go->GetComponent(DRAW_COMPONENT));
		if (lgc != nullptr)
		{
			lgc->_speed -= _speedDifUp;
			return;
		}
    }
}
