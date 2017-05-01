#include "iostream"
#include "Model.h"
#include "View.h"
#include "Score.h"
#include "ScoreBoard.h"

int main() {
    Model model = Model();
    View view = View(&model);

    Score score = Score();
    ScoreBoard board = ScoreBoard();

    for(int i = 0; i < 10; i++)
    {
        score.changeScore(100);
        board.addScore(score);
        board.printScoreBoard();
        std::cout << std::endl;
    }
    getchar();

    return 0;
}