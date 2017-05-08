#include "ScoreBoard.h"
#include <iostream>
#include <algorithm>
#include <functional>


ScoreBoard::ScoreBoard()
{
    _amountOfScores = 0;
}

//Adds the new score and directly sorts the list
void ScoreBoard::addScore(Score score)
{
    _scores.push_back(score.returnScore());
    std::sort(_scores.begin(), _scores.end(), std::greater<>());

    _amountOfScores++;
    ScoreBoard::checkArray();
}

//Checks the array for more than 10 items.
//If the array has more than 10 items it deletes the items that are past place 10.
void ScoreBoard::checkArray()
{
    if(_amountOfScores > 10)
    {
        _scores[_amountOfScores - 1] = '/0';
        _amountOfScores--;
        checkArray();
    }
}

void ScoreBoard::printScoreBoard()
{
    for(int i = 0; i < _amountOfScores; i++)
    {
        std::cout << i+1 << " Score: " << _scores[i] << std::endl;
    }
}



