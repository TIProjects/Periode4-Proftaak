#pragma once
#include "PowerUpComponent.h"

class LifeUp : public PowerUpComponent {
public:
    LifeUp();

private:
    void Effect() override;

};