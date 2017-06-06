#pragma once
#include "PowerUP.h"

class MultiplierUp : public PowerUp
{
public:
    MultiplierUp(GameObject * parent);

private:
    void Effect() override;
	GameObject * _parent;
};