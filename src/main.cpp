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

    // Arrange
    Board board;
    LegalityChecker legalityChecker(board);
    // 1. Nc3
    Move knightMove = Move(Square(2, 1), Square(3, 3));

    // Act
    bool isLegal = legalityChecker.CheckMoveLegality(knightMove);
    return 0;
}