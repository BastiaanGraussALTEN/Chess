#pragma once

#include "../src/Board.h"

class TestFunctions
{
    public:
        static Board CreateEmptyBoard()
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
};