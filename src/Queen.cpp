#include "Queen.h"

Queen::Queen(Color color, Square position) : Piece(color, PieceType::Queen, position)
{
}

Queen::~Queen()
{
}

std::vector<Square> Queen::GetPossibleMoves() const
{
    std::vector<Square> possibleMoves;
    for (int i = 1; i < 8; i++)
    {
        if (position.x + i < 9)
        {
            if (position.y + i < 9)
            {
                possibleMoves.push_back(Square(position.x + i, position.y + i));
            }
            if (position.y - i > 0)
            {
                possibleMoves.push_back(Square(position.x + i, position.y - i));
            }
        }
        if (position.x - i > 0)
        {
            if (position.y + i < 9)
            {
                possibleMoves.push_back(Square(position.x - i, position.y + i));
            }
            if (position.y - i > 0)
            {
                possibleMoves.push_back(Square(position.x - i, position.y - i));
            }
        }
    }
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