#include "Invinsible.h"
#include "LaneGeneratorComponent.h"
#include "PlayerComponent.h"
#include "LaneObstacleGenerator.h"

Invinsible::Invinsible(GameObject * parent) : PowerUp(5.0f, INVINCIBLE, "Invincible")
{
	_parent = parent;
}

void Invinsible::Effect()
{
    auto tempList = *_parent->_parentList;
    for (auto go : tempList)
    {
		LaneGeneratorComponent* lgc = dynamic_cast<LaneGeneratorComponent*>(go->GetComponent(DRAW_COMPONENT));
		if (lgc != nullptr)
        {
            PlayerComponent * player = static_cast<PlayerComponent*>(lgc->_player->GetComponent(PLAYER_COMPONENT));
            player->_isInvinsible = true;
			return;
        }
    }
}

void Invinsible::ReverseEffect()
{
    auto tempList = *_parent->_parentList;
    for (auto go : tempList)
    {
		LaneGeneratorComponent* lgc = dynamic_cast<LaneGeneratorComponent*>(go->GetComponent(DRAW_COMPONENT));
		if (lgc != nullptr)
		{
			PlayerComponent * player = static_cast<PlayerComponent*>(lgc->_player->GetComponent(PLAYER_COMPONENT));
			player->_isInvinsible = false;
			return;
		}
    }
}
