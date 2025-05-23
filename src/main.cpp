#include <iostream>
#include "MoveDialog.h"

int main()
{
    std::string move;
    MoveDialog moveDialog;
    while(true)
    {
        std::string dialog = moveDialog.GetDialog();
        std::cout << dialog;
        std::cin >> move;
        moveDialog.SetMove(move);
    }

    return 0;
}