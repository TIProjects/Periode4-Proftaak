#pragma once
#include "PowerUpComponent.h"

class SpeedUp : public PowerUpComponent
{
public:
    SpeedUp();

private:
    void Effect() override;
    void ReverseEffect() override;

    /**
    * Difference in speed for speeding up effect
    */
    float _speedDif = 9.0f;
};
