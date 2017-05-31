#include "LifeUp.h"
#include "LaneGeneratorComponent.h"
#include "PlayerComponent.h"
#include "LaneObstacleGenerator.h"

LifeUp::LifeUp() : PowerUpComponent(0.0f, LIFE_UP)
{

}

void LifeUp::Effect() {
    auto tempList = *_parent->_gameObjects;
    for (auto go : tempList)
    {
        LaneObstacleGenerator* pc = static_cast<LaneObstacleGenerator*>(go->GetComponent(LANE_OBSTACLE_GENERATOR));
        if (pc != nullptr)
        {
            LaneGeneratorComponent* component = dynamic_cast<LaneGeneratorComponent*>(pc->GetParent()->GetComponent(DRAW_COMPONENT));
            PlayerComponent * player = static_cast<PlayerComponent*>(component->_player->GetComponent(PLAYER_COMPONENT));
            player->_lifeBar->Increment();
        }
    }
}