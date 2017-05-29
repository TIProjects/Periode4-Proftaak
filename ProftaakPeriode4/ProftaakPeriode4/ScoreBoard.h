#pragma once
#include "ScoreComponent.h"
#include <vector>

//determines wich OS is being used.
#if defined(_WIN64)
    #define WIN 1
#elif defined(_WIN32)
    #define WIN 1
#else
    #define WIN 0
#endif

class ScoreBoardComponent : public Component
{
    public: 
        ScoreBoardComponent();

        /*
         * add a score component to the vector with scores
         * after adding a score, the list will be sorted in decending order
         * @param ScoreComponent is the component
         */
        void AddScore(Score * score);

        /*
         * Prints all the scores in the scoreboard
         */
        void PrintScoreBoard();

        /*
         *Saves the scores to a json file
         *The filepath is Resource Files/scores.json
         */
        void SaveScore();

        /*
         * Loads the scores from the json file
         */
        void LoadScore();

        /*
        * Checks the array.
        * If there are more than 10 items it removes the lowest value.
        */
        void CheckArray();

        /*
        * The vector with the scores
        */
        std::vector<Score*> _scores;

        void Update(float deltaTime) override;
        void LateUpdate(float deltaTime) override;

    private:

        /*
         * Sets the path to ..\Appdata\Roaming\SubwaySurfer
         * if the folder SubwaySurfer doesn't exists it creats the folder.
         */
        void GetWindowsDirectory();

        /*
         * Sets the directory for the save and load file to Resource Files
         */
        void GetLinuxDirectory();

        /*
         * amount of scores that is stored
         */
        int _amountOfScores;

        /*
         * The path used for saving and loading the scores
         */
        std::string path;
};
