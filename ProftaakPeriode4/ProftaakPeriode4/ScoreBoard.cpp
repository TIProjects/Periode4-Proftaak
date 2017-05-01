#include "ScoreBoard.h"
#include <iostream>


ScoreBoard::ScoreBoard()
{
    _amountOfScores = 0;
}

void ScoreBoard::addScore(Score score)
{
    _scores[_amountOfScores] = score.returnScore();
    _amountOfScores++;
    ScoreBoard::sortArray();
    ScoreBoard::checkArray();
}

//Sorts the array with the bubbleSort methode.
void ScoreBoard::sortArray()
{
    bool isSorting = true;

    while (isSorting)
    {
        isSorting = false;
        for (int i = 0; i < _amountOfScores - 1; i++)
        {
            int oldValue;
            //The < and > are the way the array is being sorted.
            //> is low to high.
            //< is high to low.
            if (_scores[i] < _scores[i + 1])
            {
                oldValue = _scores[i];
                _scores[i] = _scores[i + 1];
                _scores[i + 1] = oldValue;
                isSorting = true;
            }
        }
    }
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
        std::cout << i << " Score: " << _scores[i] << std::endl;
    }
}



