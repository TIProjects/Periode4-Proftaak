#include "iostream"
#include "Model.h"
#include "View.h"
#include "Score.h"
#include "ScoreBoard.h"

int main() {
    Model model = Model();
    View view = View(model);
    Score score;

    ScoreBoard board = ScoreBoard();

    for(int i = 0; i < 10; i++)
    {
        score = Score();
        score.addScore(static_cast<int> (rand() / 10));

	    board.addScore(score);
	    board.printScoreBoard();
	    std::cout << std::endl;
    }

    getchar();

    return 0;
}