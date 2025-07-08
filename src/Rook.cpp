#include "Rook.h"

Rook::Rook(Color color, Square position) : Piece(color, PieceType::Rook, position)
{
    hasMoved = false;
}

std::vector<Square> Rook::GetPossibleMoves() const
{
    std::vector<Square> possibleMoves;
    for (int i = 1; i < 9; i++)
    {
        if (i != position.y)
        {
            possibleMoves.push_back(Square(position.x, i));
        }
        if (i != position.x)
        {
            possibleMoves.push_back(Square(i, position.y));
        }
    }

    return possibleMoves;
}
