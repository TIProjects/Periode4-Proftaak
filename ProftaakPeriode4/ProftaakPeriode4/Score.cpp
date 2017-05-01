#include "Score.h"

Score::Score()
{
    _score = 0;
}

void Score::addScore(int plusScore)
{
    _score += plusScore;
}

void Score::reduceScore(int minScore)
{
    _score -= minScore;
}

int Score::returnScore()
{
    return _score;
}

