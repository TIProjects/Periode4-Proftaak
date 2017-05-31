#include "LaneGeneratorComponent.h"
#include "SpeedDown.h"

SpeedDown::SpeedDown() : PowerUpComponent(10.0f, SPEED_DOWN)
{
}

void SpeedDown::Effect()
{
    auto tempList = *_parent->_gameObjects;
    for (auto go : tempList)
    {
        ScoreComponent* lgc = static_cast<ScoreComponent*>(go->GetComponent(SCORE_COMPONENT));
        if (lgc != nullptr) *lgc->_speed -= _speedDif;
    }
}

void SpeedDown::ReverseEffect()
{
    auto tempList = *_parent->_gameObjects;
    for (auto go : tempList)
    {
        ScoreComponent* lgc = static_cast<ScoreComponent*>(go->GetComponent(SCORE_COMPONENT));
        if (lgc != nullptr) *lgc->_speed += _speedDif;
    }
}
