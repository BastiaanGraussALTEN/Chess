#include "../headerfiles/Bishop.h"
#include "../headerfiles/Constants.h"

Bishop::Bishop(Color color, Square position) : Piece(color, PieceType::Bishop, position)
{
}

std::vector<Square> Bishop::GetPossibleMoves() const
{
    std::vector<Square> possibleMoves;
    for (int i = Constants::boardBegin; i < Constants::boardEnd; i++)
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

    return possibleMoves;
}