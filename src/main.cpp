#include <iostream>
#include "LegalityChecker.h"
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

    Board board;
    LegalityChecker legalityChecker(board);
    Move knightMove = Move(Square(2, 1), Square(3, 3));
    bool isLegal = legalityChecker.CheckMoveLegality(knightMove);
    bool isCapture = legalityChecker.DoesMoveCapturePiece(knightMove);
    if(isLegal)
    {
        if (isCapture)
        {
            board.RemovePieceFromSquare(knightMove.end);
        }
        board.MovePiece(knightMove);
    }
    return 0;
}