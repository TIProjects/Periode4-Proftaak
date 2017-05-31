#include "ScoreComponent.h"
#include "Text.h"

ScoreComponent::ScoreComponent(Text * scoreText, Text * highscoreText, int highscore) : Component(SCORE_COMPONENT)
{
    _scoreText = scoreText;
    _highscoreText = highscoreText;
    _highScore = highscore;
}

ScoreComponent::~ScoreComponent()
{
}

void ScoreComponent::changeScore(int difScore)
{
    int score = _score + difScore * _multiplier;    
    if (score <= 0)
    {
        _score = 0;
        return;
    }
    _score += difScore * _multiplier;
}

void ScoreComponent::changeName(std::string name)
{
    _name = name;
}

std::string ScoreComponent::returnName()
{
    return _name;
}

unsigned int ScoreComponent::returnScore()
{
    return _score;
}

void ScoreComponent::LateUpdate(float deltaTime)
{
    
}

void ScoreComponent::drawScore(int score, Text* text)
{
    text->Update("Score: " + std::to_string(score) + " " + std::to_string(_multiplier) + "x");
}

void ScoreComponent::drawHighscore(int score, Text* text)
{
    text->Update("Highscore: " + std::to_string(score));
}

void ScoreComponent::Update(float deltaTime)
{
    //TODO: convert this to the distance not time
    _updateTimer -= deltaTime;
    _mulitplierUpdateTimer -= deltaTime;

    if (_updateTimer <= 0.0f)
    {
        changeScore(1);
        if (_score >= _highScore) _highScore = _score;
        _updateTimer = 0.2f;
    }

    if( _mulitplierUpdateTimer <= 0.0f)
    {
        incMultiplier();
        _mulitplierUpdateTimer = 10.0f * _multiplier;
    }

    drawScore(_score, _scoreText);
    drawHighscore(_highScore, _highscoreText);
}

