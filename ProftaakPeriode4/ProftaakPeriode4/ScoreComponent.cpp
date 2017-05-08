#include "ScoreComponent.h"

ScoreComponent::ScoreComponent() : Component(SCORE_COMPONENT)
{
    _score = 0;
}

//Score can't get below zero.
void ScoreComponent::changeScore(int difScore)
{
    int score = _score + difScore;    
    if (score <= 0)
    {
        _score = 0;
        return;
    }
    _score += difScore;
}

int ScoreComponent::returnScore()
{
    return _score;
}

void ScoreComponent::LateUpdate(int deltaTime)
{
    
}

void ScoreComponent::Update(int deltaTime)
{
    
}



