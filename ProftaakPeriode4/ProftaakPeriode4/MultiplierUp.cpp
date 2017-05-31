#include "MultiplierUp.h"
#include "ScoreComponent.h"

MultiplierUp::MultiplierUp() : PowerUpComponent(0.0f, MULTIPLIER_UP){

}

void MultiplierUp::Effect()
{
    auto tempList = *_parent->_gameObjects;
    for (auto go : tempList)
    {
        ScoreComponent* sc = static_cast<ScoreComponent*>(go->GetComponent(SCORE_COMPONENT));
        //I dunno how much u want
        if (sc != nullptr) sc->IncMultiplier();
    }
}
