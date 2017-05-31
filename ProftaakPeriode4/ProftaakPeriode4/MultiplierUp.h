#pragma once
#include "PowerUpComponent.h"

class MultiplierUp : public PowerUpComponent
{
public:
    MultiplierUp();

private:
    void Effect() override;
};