#pragma once
#include <type_traits>
#include "Component.h"
#include "Text.h"
#include <string>

class ScoreComponent : public Component
{
public:
    /*
    * Score can't get below zero
    */
    unsigned int _score = 0;
    Text* _scoreText;

    /*
    * Name of the person holding the score
    * Template name is Gijs for now
    */
    std::string _name = "Gijs";

    ScoreComponent(Text* scoreText);

    ~ScoreComponent();

    /*
    * Adds the score you fill in
    * The score can't be below zero 
    */
    void changeScore(int);

    /*
    * Replaces the name of the one holding the score
    */
    void changeName(std::string name);

    /**
     * \brief increments the multiplier
     */
    void incMultiplier() { _multiplier++; }

    /**
     * \brief decrements the multiplier
     */
    void decMultiplier() { _multiplier--; }

    /**
     * \brief resets the multiplier
     */
    void resetMultiplier() { _multiplier = 1; }

    /**
     * \brief adds a given amount to the multiplier
     * \param addMultiplier value being added to the multiplier
     */
    void addMultiplier(int addMultiplier) { _multiplier += addMultiplier; }
    /* 
    * Returns the name
    */
    std::string returnName();

    /*
    * Returns the score
    */
    unsigned int returnScore();

    void Update(float deltaTime) override;
    void LateUpdate(float deltaTime) override;
private:
    /*
     * amount of time left for the score gets updated.
     */
    float _updateTimer = 0.2f, _mulitplierUpdateTimer = 10.0f;

    /*
    * Multieplier for the score
    */
    int _multiplier = 1;
};
