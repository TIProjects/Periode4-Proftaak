#include "iostream"
#include "Model.h"
#include "View.h"
#include "Score.h"
#include "ScoreBoard.h"

int main() {
    Model model = Model();
    View view = View(model);
    return 0;
}