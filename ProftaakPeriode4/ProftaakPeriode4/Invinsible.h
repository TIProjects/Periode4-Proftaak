#pragma once
#include "PowerUP.h"


class Invinsible : public PowerUp
{
public:
    Invinsible(GameObject * parent);

private:
    void Effect() override;
    void ReverseEffect() override;
	GameObject * _parent;
};