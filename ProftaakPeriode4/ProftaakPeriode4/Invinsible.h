#pragma once
#include "PowerUpComponent.h"

class Invinsible : public PowerUpComponent
{
public:
    Invinsible();

private:
    void Effect() override;
    void ReverseEffect() override;
};