#pragma once
#include "Component.h"
#include "GameObject.h"

enum PowerUpId {
    LIFE_UP,
    SPEED_UP,
    SPEED_DOWN,
    MULTIPLIER_UP,
    MULTIPLIER_DOWN,
    INVINCIBLE
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
    * Id of the powerup
    */
    PowerUpId _id;

private:
    /**
    * Time the powerup is active after the powerup is activated
    * 0 for one time effect
    */
    float _timeActive;
    /**
    * Bool determining the powerup being active or not
    */
    bool isActive = false; 
    /**
    * Applies whatever effect you want a powerup to do
    */
    virtual void Effect();
};