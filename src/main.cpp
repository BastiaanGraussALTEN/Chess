#include <iostream>
#include "LegalityChecker.h"
#include "MoveDialog.h"

int main()
{
    // std::string move;
    // MoveDialog moveDialog;
    // while(true)
    // {
    //     moveDialog.ShowDialog();
    //     std::cin >> move;
    //     moveDialog.SetMove(move);
    // }
    Board board;
    LegalityChecker legalityChecker(board);
    Move rookMove = Move(Square(1, 1), Square(1, 4));
    bool isLegal = legalityChecker.CheckMoveLegality(rookMove);
    return 0;
}