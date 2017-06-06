#pragma once
#include "PowerUP.h"

class LifeUp : public PowerUp {
public:
    LifeUp(GameObject * parent);

private:
    void Effect() override;
	GameObject * _parent;

};