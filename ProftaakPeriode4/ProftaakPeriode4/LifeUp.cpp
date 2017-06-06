#include "LifeUp.h"
#include "LaneGeneratorComponent.h"
#include "PlayerComponent.h"
#include "LaneObstacleGenerator.h"

LifeUp::LifeUp(GameObject * parent) : PowerUp(0.0f, LIFE_UP)
{
	_parent = parent;
}

void LifeUp::Effect() {
    auto tempList = *_parent->_parentList;
	for (auto go : tempList)
	{
		LaneGeneratorComponent* pc = dynamic_cast<LaneGeneratorComponent*>(go->GetComponent(DRAW_COMPONENT));
		if (pc != nullptr)
		{
			PlayerComponent * player = static_cast<PlayerComponent*>(pc->_player->GetComponent(PLAYER_COMPONENT));
			player->_lifeBar->Increment();
			return;
		}
	}
}