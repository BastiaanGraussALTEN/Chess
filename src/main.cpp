#include <iostream>
#include "MoveDialog.h"

int main()
{
    std::string move;
    MoveDialog moveDialog;
    while(true)
    {
        std::string moveHistory = moveDialog.GetMoveHistory();
        std::string dialog = moveDialog.GetDialog();
        std::cout << moveHistory << dialog;
        std::cin >> move;
        moveDialog.SetMove(move);
    }

    return 0;
}