#include <iostream>
#include "Board.h"
#include "MoveDialog.h"

int main()
{
    std::string move;
    MoveDialog moveDialog;
    while(true)
    {
        moveDialog.ShowDialog();
        std::cin >> move;
        moveDialog.SetMove(move);
    }

    return 0;
}