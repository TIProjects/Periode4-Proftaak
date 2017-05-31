#pragma once
#include "PowerUpComponent.h"

class SpeedDown : public PowerUpComponent
{
public:
    SpeedDown();

private:
    void Effect() override;
    void ReverseEffect() override;
    /**
    * Difference in speed for slowing down effect
    */
    float _speedDif = 9.0f;
};