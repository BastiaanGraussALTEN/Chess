#include "Knight.h"

Knight::Knight(Color color, Square position) : Piece(color, PieceType::KnightType, position)
{
}

Knight::~Knight()
{
}

std::vector<Square> Knight::GetPossibleMoves() const
{
    std::vector<Square> possibleMoves;
    if (position.x + 2 < 9)
    {
        if (position.y + 1 < 9 )
        {
            possibleMoves.push_back(Square(position.x + 2, position.y + 1));
        }
        if (position.y - 1 > 0 )
        {
            possibleMoves.push_back(Square(position.x + 2, position.y - 1));
        }
    }

    if (position.x - 2 > 0)
    {
        if (position.y + 1 < 9 )
        {
            possibleMoves.push_back(Square(position.x - 2, position.y + 1));
        }
        if (position.y - 1 > 0 )
        {
            possibleMoves.push_back(Square(position.x - 2, position.y - 1));
        }
    }

    if (position.y + 2 < 9)
    {
        if (position.x + 1 < 9 )
        {
            possibleMoves.push_back(Square(position.x + 1, position.y + 2));
        }
        if (position.x - 1 > 0 )
        {
            possibleMoves.push_back(Square(position.x - 1, position.y + 2));
        }
    }

    if (position.y - 2 > 0)
    {
        if (position.x + 1 < 9 )
        {
            possibleMoves.push_back(Square(position.x + 1, position.y - 2));
        }
        if (position.x - 1 > 0 )
        {
            possibleMoves.push_back(Square(position.x - 1, position.y - 2));
        }
    }

    return possibleMoves;
}
