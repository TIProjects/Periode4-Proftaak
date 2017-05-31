#include "PowerUpComponent.h"

PowerUpComponent::PowerUpComponent(float timeActive, PowerUpId id) : Component(POWER_UP_COMPONENT)
{
    _timeActive = timeActive;
    _id = id;
}

PowerUpComponent::~PowerUpComponent()
{
}

void PowerUpComponent::Update(float deltaTime)
{
    if (isActive)
    {
        _timeActive -= deltaTime;
        Effect();
        if (_timeActive <= 0) isActive = false;
    }
}

void PowerUpComponent::LateUpdate(float deltaTime)
{
}

void PowerUpComponent::Activate()
{
    if (_timeActive == 0.0f) Effect();
    else isActive = true;
}

void PowerUpComponent::Effect()
{
}
