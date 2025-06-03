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
    // 1. Be3
    Move bishopMove = Move(Square(3, 1), Square(5, 3));

    // Act
    bool isLegal = legalityChecker.CheckMoveLegality(bishopMove);

    return 0;
}