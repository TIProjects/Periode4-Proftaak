#include "Score.h"

Score::Score()
{
    _score = 0;
}

//Score can't get below zero.
void Score::changeScore(int difScore)
{
    int score = _score + difScore;    
    if (score <= 0)
    {
        _score = 0;
        return;
    }
    _score += difScore;
}

int Score::returnScore()
{
    return _score;
}

