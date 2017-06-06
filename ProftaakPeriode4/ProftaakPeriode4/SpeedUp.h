#pragma once
#include "PowerUP.h"

class SpeedUp : public PowerUp
{
public:
    SpeedUp(GameObject * parent);

private:
    void Effect() override;
    void ReverseEffect() override;

    /**
    * Difference in speed for speeding up effect
    */
    float _speedDif = 9.0f;
	GameObject * _parent;
};
