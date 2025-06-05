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
    board.AddPiece(PieceFactory::CreatePawn(Color::Black, Square(3,3)));
    LegalityChecker legalityChecker(board);
    Move knightMove = Move(Square(2,1), Square(3,3));
    bool isLegal = legalityChecker.CheckMoveLegality(knightMove);
    return 0;
}