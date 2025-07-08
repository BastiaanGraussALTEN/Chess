#include "../headerfiles/King.h"
#include "../headerfiles/Constants.h"

King::King(Color color, Square position) : Piece(color, PieceType::King, position)
{
    hasMoved = false;
}

std::vector<Square> King::GetPossibleMoves() const
{
    std::vector<Square> possibleMoves;
    if (position.x < Constants::boardEnd)
    {
        if (position.y < Constants::boardEnd)
        {
            possibleMoves.push_back(Square(position.x + 1, position.y + 1));
        }
        if (position.y > Constants::boardBegin)
        {
            possibleMoves.push_back(Square(position.x + 1, position.y - 1));
        }

        possibleMoves.push_back(Square(position.x + 1, position.y));
    }

    if (position.x > Constants::boardBegin)
    {
        if (position.y < Constants::boardEnd)
        {
            possibleMoves.push_back(Square(position.x - 1, position.y + 1));
        }
        if (position.y > Constants::boardBegin)
        {
            possibleMoves.push_back(Square(position.x - 1, position.y - 1));
        }

        possibleMoves.push_back(Square(position.x - 1, position.y));
    }

    if (position.y < Constants::boardEnd)
    {
        possibleMoves.push_back(Square(position.x, position.y + 1));
    }

    if (position.y > Constants::boardBegin)
    {
        possibleMoves.push_back(Square(position.x , position.y - 1));
    }

    return possibleMoves;
}