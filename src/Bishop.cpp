#include "Bishop.h"

Bishop::Bishop(Color color, Square position) : Piece(color, position)
{
}

Bishop::~Bishop()
{
}

std::vector<Square> Bishop::GetPossibleMoves() const
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

    return possibleMoves;
}