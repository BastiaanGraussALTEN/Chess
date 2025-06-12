#include <iostream>
#include "MoveDialog.h"
#include "CastleChecker.h"

Board CreateEmptyBoard()
{
    Board board;
    for (int i = 1; i < 9; i++)
    {
        board.RemovePieceFromSquare(Square(i, 1));
        board.RemovePieceFromSquare(Square(i, 2));
        board.RemovePieceFromSquare(Square(i, 7));
        board.RemovePieceFromSquare(Square(i, 8));
    }
    return board;
}

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

    Board board = CreateEmptyBoard();
    auto king = PieceFactory::CreateKing(Color::White, Square(5, 1));
    king->hasMoved = true;
    board.AddPiece(king);
    board.AddPiece(PieceFactory::CreateRook(Color::White, Square(8, 1)));
    LegalityChecker legalityChecker = LegalityChecker(board);
    DangerChecker dangerChecker = DangerChecker(board, legalityChecker, Color::White);
    CastleChecker castleChecker = CastleChecker(board, legalityChecker, dangerChecker, Color::White);
    bool canCastle = castleChecker.CanCastleKingSide();
    return 0;
}