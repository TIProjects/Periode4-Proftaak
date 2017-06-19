#include "LifeUp.h"
#include "LaneGeneratorComponent.h"
#include "Component.h"
#include "PlayerComponent.h"
#include "LaneObstacleGenerator.h"

LifeUp::LifeUp(GameObject * parent) : PowerUp(0.0f, LIFE_UP, "Life up")
{
	_parent = parent;
}

void LifeUp::Effect() {
    auto tempList = *_parent->_parentList;
	for (auto go : tempList)
	{
		LaneGeneratorComponent* lg = dynamic_cast<LaneGeneratorComponent*>(go->GetComponent(DRAW_COMPONENT));
		if (lg != nullptr)
		{
			PlayerComponent * player = dynamic_cast<PlayerComponent*>(lg->_player->GetComponent(PLAYER_COMPONENT));
			player->_lifeBar->Increment();
			return;
		}
	}
}