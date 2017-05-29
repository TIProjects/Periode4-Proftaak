#pragma once
#include <type_traits>
#include "Component.h"
#include "Text.h"
#include <string>

struct Score {
    unsigned int score;
    std::string name;
};

class ScoreComponent : public Component
{
public:
    float* _speed;

    Score* _score = new Score{ 0, "Gijs" };

    Text* _scoreText, *_highscoreText;

    ScoreComponent(float* speed, unsigned int highScore);

    ~ScoreComponent();

    /**
    * Adds the score you fill in
    * The score can't be below zero 
    */
    void ChangeScore(int);

    /**
    * Replaces the name of the one holding the score
    */
    void ChangeName(std::string name);

    /**
     * \brief increments the multiplier
     */
    void IncMultiplier() { _multiplier++; }

    /**
     * \brief decrements the multiplier
     */
    void DecMultiplier() { if(_multiplier > 1) _multiplier--; }

    /**
     * \brief resets the multiplier
     */
    void ResetMultiplier() { _multiplier = 1; }

    /**
     * \brief adds a given amount to the multiplier
     * \param addMultiplier value being added to the multiplier
     */
    void HangeMultiplier(int addMultiplier) { if(_multiplier + addMultiplier > 1) _multiplier += addMultiplier; }

    Score * ReturnScoreStruct();

    /** 
    * Returns the name
    */
    std::string ReturnName();

    /**
    * Returns the score
    */
    unsigned int ReturnScore();

    void Update(float deltaTime) override;
    void LateUpdate(float deltaTime) override;
    
private:
    /**
    * Score can't get below zero
    */
    unsigned int _highScore = 0;

    /**
     * amount of time left for the score and the multiplier are getting updated.
     */
    float _updateTimer = 0.0f, _mulitplierUpdateTimer = 10.0f;

    /**
    * Multieplier for the score
    */
    unsigned int _multiplier = 1;

    void DrawScore(int score, Text* text);
    void DrawHighscore(int score, Text* text);

};
