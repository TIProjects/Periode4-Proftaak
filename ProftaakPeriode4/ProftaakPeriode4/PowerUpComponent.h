#pragma once
#include "Component.h"
#include "GameObject.h"

enum PowerUpId {
    OWN,
    LIFE_UP,
    SPEED_UP,
    SPEED_DOWN,
    MULTIPLIER_UP,
    INVINSIBLE
};

class PowerUpComponent : public Component
{
public:
    /**
    * Construct of PowerUpComponent
    */
    PowerUpComponent(float timeActive, PowerUpId id);
    /**
    * Deconstruct of PowerUpComponent
    */
    ~PowerUpComponent();
    
    void Init();
    /**
    * Update methode
    */
    void Update(float deltaTime) override;
    /**
    * LateUpdate methode
    */
    void LateUpdate(float deltaTime) override;
    /**
    * Activates the powerup
    */
    void Activate();
    /**
    * Deactivates the powerup
    */
    void DeActivate();
    PowerUpComponent * GetPowerUp(PowerUpId id);
    /**
    * Id of the powerup
    */
    PowerUpId _id;
    std::vector<PowerUpComponent*> powerUps;

private:
    /**
    * Time the powerup is active after the powerup is activated
    * 0 for one time effect
    */
    float _timeActive, _resetTime;
    /**
    * Bool determining the powerup being active or not
    */
    bool _isActive;
    /**
    * Applies whatever effect you want a powerup to do
    */
    virtual void Effect();
    virtual void ReverseEffect();
};