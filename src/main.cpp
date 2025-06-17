#include <iostream>
#include "MoveDialog.h"
#include "CastleChecker.h"
#include "CheckChecker.h"

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
    board.AddPiece(PieceFactory::CreateKnight(Color::Black, Square(6, 3)));
    board.AddPiece(PieceFactory::CreateKnight(Color::Black, Square(4, 3)));
    CheckChecker checkChecker = CheckChecker(board, Color::White);
    bool isCheckMate = checkChecker.IsCheckMate();

    return 0;
}