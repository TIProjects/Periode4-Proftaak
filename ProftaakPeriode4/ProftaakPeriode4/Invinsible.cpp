#include "Invinsible.h"
#include "LaneGeneratorComponent.h"
#include "PlayerComponent.h"
#include "LaneObstacleGenerator.h"

Invinsible::Invinsible() : PowerUpComponent(5.0f, INVINSIBLE)
{
}

void Invinsible::Effect()
{
    auto tempList = *_parent->_gameObjects;
    for (auto go : tempList)
    {
        LaneObstacleGenerator* pc = static_cast<LaneObstacleGenerator*>(go->GetComponent(LANE_OBSTACLE_GENERATOR));
        if (pc != nullptr)
        {
            LaneGeneratorComponent* component = static_cast<LaneGeneratorComponent*>(pc->GetParent()->GetComponent(DRAW_COMPONENT));
            PlayerComponent * player = static_cast<PlayerComponent*>(component->_player->GetComponent(PLAYER_COMPONENT));
            player->_isInvinsible = true;
        }
    }
}

void Invinsible::ReverseEffect()
{
    auto tempList = *_parent->_gameObjects;
    for (auto go : tempList)
    {
        LaneObstacleGenerator* pc = static_cast<LaneObstacleGenerator*>(go->GetComponent(LANE_OBSTACLE_GENERATOR));
        if (pc != nullptr)
        {
            LaneGeneratorComponent* component = static_cast<LaneGeneratorComponent*>(pc->GetParent()->GetComponent(DRAW_COMPONENT));
            PlayerComponent * player = static_cast<PlayerComponent*>(component->_player->GetComponent(PLAYER_COMPONENT));
            player->_isInvinsible = false;
        }
    }
}
