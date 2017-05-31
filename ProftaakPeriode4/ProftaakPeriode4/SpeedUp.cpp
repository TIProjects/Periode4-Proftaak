#include "SpeedUp.h"
#include "LaneGeneratorComponent.h"

SpeedUp::SpeedUp() : PowerUpComponent(1.0f, SPEED_UP)
{

}

void SpeedUp::Effect()
{
    auto tempList = *_parent->_gameObjects;
    for (auto go : tempList)
    {
        ScoreComponent* lgc = static_cast<ScoreComponent*>(go->GetComponent(SCORE_COMPONENT));
        if (lgc != nullptr) *lgc->_speed += _speedDif;
    }
}

void SpeedUp::ReverseEffect()
{
    auto tempList = *_parent->_gameObjects;
    for (auto go : tempList)
    {
        ScoreComponent* lgc = static_cast<ScoreComponent*>(go->GetComponent(SCORE_COMPONENT));
        if (lgc != nullptr) *lgc->_speed -= _speedDif;
    }
}
