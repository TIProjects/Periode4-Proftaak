#include "MultiplierUp.h"
#include "ScoreComponent.h"

MultiplierUp::MultiplierUp(GameObject * parent) : PowerUp(0.0f, MULTIPLIER_UP){
	_parent = parent;
}

void MultiplierUp::Effect()
{
    auto tempList = *_parent->_parentList;
    for (auto go : tempList)
    {
        ScoreComponent* sc = static_cast<ScoreComponent*>(go->GetComponent(SCORE_COMPONENT));
        //I dunno how much u want
		if (sc != nullptr) {
			sc->IncMultiplier();
			return;
		}
    }
}
