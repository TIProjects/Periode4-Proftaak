#include "PowerUpComponent.h"
#include "LifeUp.h"
#include "SpeedUp.h"
#include "SpeedDown.h"
#include "Invinsible.h"
#include "MultiplierUp.h"

PowerUpComponent::PowerUpComponent(float timeActive, PowerUpId id) : Component(POWER_UP_COMPONENT)
{
    _timeActive = timeActive;
    _resetTime = timeActive;
    _id = id;
    _isActive = false;
}

PowerUpComponent::~PowerUpComponent()
{
}

void PowerUpComponent::Init()
{
    LifeUp * l = new LifeUp();
    SpeedUp * su = new SpeedUp();
    SpeedDown * sd = new SpeedDown();
    MultiplierUp * mu = new MultiplierUp();
    Invinsible * i = new Invinsible();
    
    l->SetParent(_parent);
    su->SetParent(_parent);
    sd->SetParent(_parent);
    mu->SetParent(_parent);
    i->SetParent(_parent);

    powerUps.push_back(l);
    powerUps.push_back(su);
    powerUps.push_back(sd);
    powerUps.push_back(mu);
    powerUps.push_back(i);
}

void PowerUpComponent::Update(float deltaTime)
{
    _timeActive -= deltaTime;
    if (_timeActive <= 0) {
        DeActivate();
    }    
}

void PowerUpComponent::LateUpdate(float deltaTime)
{
}

void PowerUpComponent::Activate()
{
    _timeActive = _resetTime;
    Effect();
    _isActive = true;    
}

void PowerUpComponent::DeActivate()
{ 
    ReverseEffect();
    _isActive = false;
}

PowerUpComponent * PowerUpComponent::GetPowerUp(PowerUpId id)
{
    for (PowerUpComponent * pu : powerUps)
    {
        if (pu->_id == id) return pu;
    }
    return nullptr;
}

void PowerUpComponent::Effect()
{

}

void PowerUpComponent::ReverseEffect()
{
}
