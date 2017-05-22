#pragma once
#include <type_traits>
#include "Component.h"
#include "Text.h"
#include <string>

#define MILLION 1000000
#define THOUSAND 1000

class ScoreComponent : public Component
{
public:
    Text* _scoreText, *_highscoreText;

    /**
    * Name of the person holding the score
    * Template name is Gijs for now
    */
    std::string _name = "Gijs";

    ScoreComponent(Text* scoreText, Text* highscoreText, int highScore);

    ~ScoreComponent();

    /**
    * Adds the score you fill in
    * The score can't be below zero 
    */
    void changeScore(int);

    /**
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
    void decMultiplier() { if(_multiplier > 1) _multiplier--; }

    /**
     * \brief resets the multiplier
     */
    void resetMultiplier() { _multiplier = 1; }

    /**
     * \brief adds a given amount to the multiplier
     * \param addMultiplier value being added to the multiplier
     */
    void changeMultiplier(int addMultiplier) { if(_multiplier + addMultiplier > 1) _multiplier += addMultiplier; }

    /** 
    * Returns the name
    */
    std::string returnName();

    /**
    * Returns the score
    */
    unsigned int returnScore();

    void Update(float deltaTime) override;
    void LateUpdate(float deltaTime) override;
    
private:

    /**
    * Score can't get below zero
    */
    unsigned int _score = 0, _highScore = 0;

    /**
     * amount of time left for the score and the multiplier are getting updated.
     */
    float _updateTimer = 0.2f, _mulitplierUpdateTimer = 10.0f;

    /**
    * Multieplier for the score
    */
    unsigned int _multiplier = 1;

    void drawScore(int score, Text* text);
    void drawHighscore(int score, Text* text);

};
