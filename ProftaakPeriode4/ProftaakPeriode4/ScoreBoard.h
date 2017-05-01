#pragma once
#include "Score.h"

class ScoreBoard
{
    public: 
        ScoreBoard();
        void addScore(Score);
        void printScoreBoard();

    private:
        void sortArray();
        void checkArray();
        int _amountOfScores;
        int _scores[11];
};
