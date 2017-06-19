#pragma once
#include "GameObject.h"


enum PowerUpId {
	OWN,
	LIFE_UP,
	SPEED_UP,
	SPEED_DOWN,
	MULTIPLIER_UP,
	INVINCIBLE
};

class PowerUp {
public:  
	PowerUp(float timeActive, PowerUpId id, std::string name);
	/**
	* Update methode
	*/
	void Update(float deltaTim);
	/**
	* Activates the powerup
	*/
	void Activate();
	/**
	* Deactivates the powerup
	*/
	void DeActivate();
	/**
	* Id of the powerup
	*/
	PowerUpId _id;
	/**
	* Name of the powerup
	*/
	std::string _name = "Something went wrong here";

private:
	/**
	* Time the powerup is active after the powerup is activated
	* 0 for one time effect
	*/
	float _timeActive = 0.0f;
	float _resetTimer;
	/**
	* Applies whatever effect you want a powerup to do
	*/
	virtual void Effect();
	virtual void ReverseEffect();
};