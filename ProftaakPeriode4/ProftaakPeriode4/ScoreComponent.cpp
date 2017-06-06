#include "ScoreComponent.h"
#include "Text.h"

ScoreComponent::ScoreComponent(float * speed, unsigned int highscore) : Component(SCORE_COMPONENT)
{
    _highScore = highscore;
    _speed = speed;
    ResetMultiplier();
}

ScoreComponent::~ScoreComponent()
{
}

void ScoreComponent::ChangeScore(int difScore)
{
    int score = _score->score + difScore * _multiplier;  
    if (score <= 0)
    {
        _score->score = 0;
        return;
    }
    _score->score += difScore * _multiplier;
}

void ScoreComponent::ChangeName(std::string name)
{
    _score->name = name;
}

Score * ScoreComponent::ReturnScoreStruct()
{
    return _score;
}

std::string ScoreComponent::ReturnName()
{
    return _score->name;
}

unsigned int ScoreComponent::ReturnScore()
{
    return _score->score;
}

void ScoreComponent::LateUpdate(float deltaTime)
{
}

void ScoreComponent::DrawScore(int score, Text* text)
{
    text->Update("Score: " + std::to_string(score) + " " + std::to_string(_multiplier) + "x");
}

void ScoreComponent::DrawHighscore(int score, Text* text)
{
    text->Update("Highscore: " + std::to_string(score));
}

void ScoreComponent::Update(float deltaTime)
{
    _updateTimer += deltaTime;
    _mulitplierUpdateTimer -= deltaTime;

    if (_updateTimer * *_speed >= 9.0f)
    {
        ChangeScore(10);
        if (_score->score >= _highScore) _highScore = _score->score;
        _updateTimer = 0.0f;
    }

    if( _mulitplierUpdateTimer <= 0.0f)
    {
        IncMultiplier();
        _mulitplierUpdateTimer = 10.0f * _multiplier;
    }

    DrawScore(_score->score, _scoreText);
    DrawHighscore(_highScore, _highscoreText);
}

