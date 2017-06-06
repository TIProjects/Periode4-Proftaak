#pragma once
#include "Component.h"
#include "GameObject.h"
#include "PowerUP.h"

class PowerUpComponent : public Component
{
public:
	PowerUpComponent();
    /**
    * Deconstruct of PowerUpComponent
    */
    ~PowerUpComponent();
    /**
    * Update methode
    */
    void Update(float deltaTime) override;
    /**
    * LateUpdate methode
    */
    void LateUpdate(float deltaTime) override;
	void Init();
	PowerUp * GetPowerUp(PowerUpId id);
	std::vector<PowerUp*> _powerUps;

private:
};