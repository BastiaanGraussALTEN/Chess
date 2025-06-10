#include <iostream>
#include "LegalityChecker.h"
#include "MoveDialog.h"
#include "DangerChecker.h"

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
    board.AddPiece(PieceFactory::CreateKnight(Color::White, Square(4, 6)));
    LegalityChecker legalityChecker(board);
    DangerChecker dangerChecker(board, legalityChecker, Color::White);
    bool isUnderAttack = dangerChecker.IsKingUnderAttack();
    return 0;
}