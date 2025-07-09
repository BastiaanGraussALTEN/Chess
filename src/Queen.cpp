#include "../header/Queen.h"
#include "../header/Constants.h"

Queen::Queen(Color color, Square position) : Piece(color, PieceType::Queen, position)
{
}

std::vector<Square> Queen::GetPossibleMoves() const
{
    std::vector<Square> possibleMoves;
    for (int i = 1; i < Constants::boardEnd; i++)
    {
        if (position.x + i < Constants::boardEnd + 1)
        {
            if (position.y + i < Constants::boardEnd + 1)
            {
                possibleMoves.push_back(Square(position.x + i, position.y + i));
            }
            if (position.y - i > Constants::boardBegin - 1)
            {
                possibleMoves.push_back(Square(position.x + i, position.y - i));
            }
        }
        if (position.x - i > Constants::boardBegin - 1)
        {
            if (position.y + i < Constants::boardEnd + 1)
            {
                possibleMoves.push_back(Square(position.x - i, position.y + i));
            }
            if (position.y - i > Constants::boardBegin - 1)
            {
                possibleMoves.push_back(Square(position.x - i, position.y - i));
            }
        }
    }
    for (int i = 1; i < Constants::boardEnd + 1; i++)
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