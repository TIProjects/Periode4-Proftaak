#include "ScoreBoard.h"
#include "json.hpp"

#include <iostream>
#include <algorithm>
#include <functional>
#include <fstream>
#include <windows.h>
#include <ShlObj.h>
#include <filesystem>
#include <sys/stat.h>
#include <direct.h>

ScoreBoard::ScoreBoard()
{
    _amountOfScores = 0;
    if(WIN) getWindowsDirectory();
    else getLinuxDirectory();
}

void ScoreBoard::addScore(ScoreComponent * score)
{
    _scores.push_back(score);
    _amountOfScores++;
}

/**
 * \brief compares two score pointer
 * Used in sorting the list with score pointers so it won't sort the pointers on memory adress....
 * \param a score pointer one
 * \param b score pointer two
 * \return true id pointer a is bigger than pointer b
 */
bool comparePtrToScore(ScoreComponent* a, ScoreComponent* b) { return a->returnScore() > b->returnScore(); }

void ScoreBoard::checkArray()
{
    std::sort(_scores.begin(), _scores.end(), comparePtrToScore);
    while(_amountOfScores > 10)
    {
        delete _scores[_amountOfScores - 1];
        _scores.pop_back();
        _amountOfScores--;
    }
}

void ScoreBoard::getLinuxDirectory()
{
    //Default path within the game directory itself, stays the same if the directory doesn't work.
    path = "Resource Files/scores.cr";

    //TODO: test if this works
    const char* temp_p = "$XDG_DATA_HOME/CubeRunner";
    if (_mkdir(temp_p) == -1)//creating a directory
    {
        //ReSharper disable once CppDeprecatedEntity
        std::cerr << "Error :  " << strerror(errno) << std::endl;
        return;
    }

    //Linux directory
    path = temp_p;
    path += "/scores.cr";
}

void ScoreBoard::getWindowsDirectory()
{
    TCHAR szPath[MAX_PATH];
    if (SUCCEEDED(SHGetFolderPath(HWND_DESKTOP, CSIDL_APPDATA, NULL, SHGFP_TYPE_CURRENT, szPath)))
    {
        std::wstring temp(szPath);
        std::string temps(temp.begin(), temp.end());
        path = temps;

        path += "\\CubeRunner";

        struct stat info;
        //Checks if the directory already exists if not it creates the directory
        if (stat(path.c_str(), &info) != 0) std::experimental::filesystem::create_directory(path.c_str());
        path += "\\scores.cr";
    }

}

void ScoreBoard::printScoreBoard()
{
    for(int i = 0; i < _amountOfScores; i++)
    {
        std::cout << "[" << i+1 << "] " << _scores[i]->returnName() << " got a score of " << _scores[i]->returnScore() << std::endl;
    }
}

void ScoreBoard::saveScore()
{
    checkArray();
    nlohmann::json j;
    j["amount"] = _amountOfScores;

    for(int i = 0; i < _amountOfScores; i++)
    {
        j["scores"][i]["name"] = _scores[i]->returnName();
        j["scores"][i]["points"] = _scores[i]->returnScore();
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
        file >> j;
        _amountOfScores = j["amount"];
        for(int i = 0; i < _amountOfScores; i++)
        {
            ScoreComponent* score = new ScoreComponent(nullptr, nullptr, 0);
            score->changeName(j["scores"][i]["name"]);
            score->changeScore(j["scores"][i]["points"]);
            _scores.push_back(score);
        }
        checkArray();
    }

    else std::cout << "Unable to open file: " << path << std::endl;
}

