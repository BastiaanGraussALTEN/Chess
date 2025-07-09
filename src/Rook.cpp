#include "../header/Rook.h"
#include "../header/Constants.h"

Rook::Rook(Color color, Square position) : Piece(color, PieceType::Rook, position)
{
    hasMoved = false;
}

std::vector<Square> Rook::GetPossibleMoves() const
{
    std::vector<Square> possibleMoves;
    for (int i = Constants::boardBegin; i < Constants::boardEnd + 1; i++)
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