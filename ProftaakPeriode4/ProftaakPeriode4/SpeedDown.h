#pragma once
#include "PowerUP.h"

class SpeedDown : public PowerUp
{
public:
    SpeedDown(GameObject * parent);

private:
    void Effect() override;
    void ReverseEffect() override;
    /**
    * Difference in speed for slowing down effect
    */
    float _speedDif = 9.0f;
	GameObject * _parent;
};