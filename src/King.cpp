#include "King.h"

King::King(Color color, Square position) : Piece(color, PieceType::King, position)
{
    hasMoved = false;
}

std::vector<Square> King::GetPossibleMoves() const
{
    std::vector<Square> possibleMoves;
    if (position.x + 1 < 9)
    {
        if (position.y + 1 < 9)
        {
            possibleMoves.push_back(Square(position.x + 1, position.y + 1));
        }
        if (position.y - 1 > 0)
        {
            possibleMoves.push_back(Square(position.x + 1, position.y - 1));
        }

        possibleMoves.push_back(Square(position.x + 1, position.y));
    }

    if (position.x - 1 > 0)
    {
        if (position.y + 1 < 9)
        {
            possibleMoves.push_back(Square(position.x - 1, position.y + 1));
        }
        if (position.y - 1 > 0)
        {
            possibleMoves.push_back(Square(position.x - 1, position.y - 1));
        }

        possibleMoves.push_back(Square(position.x - 1, position.y));
    }

    if (position.y + 1 < 9)
    {
        possibleMoves.push_back(Square(position.x, position.y + 1));
    }

    if (position.y - 1 > 0)
    {
        possibleMoves.push_back(Square(position.x , position.y - 1));
    }

    return possibleMoves;
}