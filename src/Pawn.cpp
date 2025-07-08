#include "Pawn.h"

Pawn::Pawn(Color color, Square position) : Piece(color, PieceType::Pawn, position)
{
    hasMoved = false;
}

std::vector<Square> Pawn::GetPossibleMoves() const
{
    std::vector<Square> possibleMoves;
    if (color == Color::White)
    {
        if (position.y + 1 < 9)
        {
            possibleMoves.push_back(Square(position.x, position.y + 1));
            if (position.x + 1 < 9)
            {
                possibleMoves.push_back(Square(position.x + 1, position.y + 1));
            }
            if (position.x - 1 > 0)
            {
                possibleMoves.push_back(Square(position.x - 1, position.y + 1));
            }
        }
        if (hasMoved == false && position.y + 2 < 9)
        {
            possibleMoves.push_back(Square(position.x, position.y + 2));
        }
    }
    
    if (color == Color::Black)
    {
        if (position.y - 1 > 0)
        {
            possibleMoves.push_back(Square(position.x, position.y - 1));
            if (position.x + 1 < 9)
            {
                possibleMoves.push_back(Square(position.x + 1, position.y - 1));
            }
            if (position.x - 1 > 0)
            {
                possibleMoves.push_back(Square(position.x - 1, position.y - 1));
            }
        }
        if (hasMoved == false && position.y - 2 > 0)
        {
            possibleMoves.push_back(Square(position.x, position.y - 2));
        }
    }
    return possibleMoves;
}