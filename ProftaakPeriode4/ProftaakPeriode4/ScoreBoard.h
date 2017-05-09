#pragma once
#include "ScoreComponent.h"
#include <vector>

class ScoreBoard
{
    public: 
        ScoreBoard();

        /*
         * add a score component to the vector with scores
         * after adding a score, the list will be sorted in decending order
         * @param ScoreComponent is the component
         */
        void addScore(ScoreComponent);

        /*
         * Prints all the scores in the scoreboard
         */
        void printScoreBoard();

        /*
         *Saves the scores to a json file
         *The filepath is Resource Files/scores.json
         */
        void saveScore();

        /*
         * Loads the scores from the json file
         */
        void loadScore();

    private:
        /*
         * Checks the array.
         * If there are more than 10 items it removes the lowest value.
         */
        void checkArray();

        /*
         * amount of scores that is stored
         */
        int _amountOfScores;

        /*
         * The vector with the scores
         */
        std::vector<ScoreComponent> _scores;
};
