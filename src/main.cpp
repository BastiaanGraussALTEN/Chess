#include <iostream>
#include "MoveDialog.h"
#include "CastleChecker.h"

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
    board.MovePiece(Move(Square(5, 2), Square(5, 4)));
    LegalityChecker legalityChecker(board);
    std::vector<Move> possibleMoves = legalityChecker.GetAllPossibleMoves(); 
    int a = 4;
    return 0;
}