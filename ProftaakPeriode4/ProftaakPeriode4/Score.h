#pragma once
#include <type_traits>

class Score
{
    public:
        Score();
        void changeScore(int);
        int returnScore();
    private:
        unsigned int _score;
};
