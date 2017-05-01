#pragma once
#include "Score.h"
#include <vector>

class ScoreBoard
{
    public: 
        ScoreBoard();
        void addScore(Score);
        void printScoreBoard();

    private:
        void checkArray();
        int _amountOfScores;
        std::vector<int> _scores;
};
