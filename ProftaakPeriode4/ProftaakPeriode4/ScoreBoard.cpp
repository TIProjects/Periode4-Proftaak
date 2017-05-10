#include "ScoreBoard.h"
#include "json.hpp"
#include <iostream>
#include <algorithm>
#include <functional>
#include <fstream>

std::string path = "Resource Files/scores.json";

ScoreBoard::ScoreBoard()
{
    _amountOfScores = 0;
}

void ScoreBoard::addScore(ScoreComponent score)
{
    _scores.push_back(score);
    _amountOfScores++;
    ScoreBoard::checkArray();
}

void ScoreBoard::checkArray()
{
    std::sort(_scores.begin(), _scores.end(), std::greater<>());
    if(_amountOfScores > 10)
    {
        _scores.pop_back();
        _amountOfScores--;
        checkArray();
    }
}

void ScoreBoard::printScoreBoard()
{
    for(int i = 0; i < _amountOfScores; i++)
    {
        std::cout << "[" << i+1 << "] " << _scores[i].returnName() << " got a score of " << _scores[i].returnScore() << std::endl;
    }
}

void ScoreBoard::saveScore()
{
    nlohmann::json j;
    j["amount"] = _amountOfScores;

    for(int i = 0; i < _amountOfScores; i++)
    {
        j["scores"][i]["name"] = _scores[i].returnName();
        j["scores"][i]["points"] = _scores[i].returnScore();
    }

    std::ofstream file(path);
    file << std::setw(4) << j << std::endl;
}

void ScoreBoard::loadScore()
{
    std::ifstream file(path);
    nlohmann::json j;

    if (file.is_open())
    {
        ScoreComponent score;
        file >> j;
        _amountOfScores = j["amount"];
        for(int i = 0; i < _amountOfScores; i++)
        {
            score = ScoreComponent();
            score.changeName(j["scores"][i]["name"]);
            score.changeScore(j["scores"][i]["points"]);
            _scores.push_back(score);
        }
        checkArray();
    }
    else
    {
        std::cout << "Unable to open file" << std::endl;
    }
}

