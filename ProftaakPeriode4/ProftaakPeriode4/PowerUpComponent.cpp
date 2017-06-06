#include "PowerUpComponent.h"
#include "LifeUp.h"
#include "SpeedUp.h"
#include "SpeedDown.h"
#include "Invinsible.h"
#include "MultiplierUp.h"
#include <iostream>

PowerUpComponent::PowerUpComponent() : Component(POWER_UP_COMPONENT)
{
}

PowerUpComponent::~PowerUpComponent()
{
}

void PowerUpComponent::Update(float deltaTime)
{
	for (auto pu : _powerUps) pu->Update(deltaTime);
}

void PowerUpComponent::LateUpdate(float deltaTime)
{
}

void PowerUpComponent::Init()
{
	_powerUps.push_back(new LifeUp(_parent));
	_powerUps.push_back(new SpeedUp(_parent));
	_powerUps.push_back(new SpeedDown(_parent));
	_powerUps.push_back(new MultiplierUp(_parent));
	_powerUps.push_back(new Invinsible(_parent));
}

PowerUp * PowerUpComponent::GetPowerUp(PowerUpId id)
{
	for (auto pu : _powerUps) if (pu->_id == id) return pu;
	return nullptr;
}

