#include "../header/Knight.h"
#include "../header/Constants.h"

Knight::Knight(Color color, Square position) : Piece(color, PieceType::Knight, position)
{
}

std::vector<Square> Knight::GetPossibleMoves() const
{
    std::vector<Square> possibleMoves;
    if (position.x + 2 < Constants::boardEnd + 1)
    {
        if (position.y + 1 < Constants::boardEnd + 1)
        {
            possibleMoves.push_back(Square(position.x + 2, position.y + 1));
        }
        if (position.y - 1 > Constants::boardBegin - 1 )
        {
            possibleMoves.push_back(Square(position.x + 2, position.y - 1));
        }
    }

    if (position.x - 2 > Constants::boardBegin - 1)
    {
        if (position.y + 1 < Constants::boardEnd + 1)
        {
            possibleMoves.push_back(Square(position.x - 2, position.y + 1));
        }
        if (position.y - 1 > Constants::boardBegin - 1 )
        {
            possibleMoves.push_back(Square(position.x - 2, position.y - 1));
        }
    }

    if (position.y + 2 < Constants::boardEnd + 1)
    {
        if (position.x + 1 < Constants::boardEnd + 1)
        {
            possibleMoves.push_back(Square(position.x + 1, position.y + 2));
        }
        if (position.x - 1 > Constants::boardBegin - 1)
        {
            possibleMoves.push_back(Square(position.x - 1, position.y + 2));
        }
    }

    if (position.y - 2 > Constants::boardBegin - 1)
    {
        if (position.x + 1 < Constants::boardEnd + 1)
        {
            possibleMoves.push_back(Square(position.x + 1, position.y - 2));
        }
        if (position.x - 1 > Constants::boardBegin - 1)
        {
            possibleMoves.push_back(Square(position.x - 1, position.y - 2));
        }
    }

    return possibleMoves;
}
