#pragma once
#include <type_traits>

class Score
{
    public:
        Score();
        void addScore(int);
        void reduceScore(int);
        int returnScore();
    private:
        unsigned int _score;
};
