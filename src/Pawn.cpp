#include "Pawn.h"

Pawn::Pawn(Color color, Coord position) : Piece(color, position)
{
    hasMoved = false;
}

Pawn::~Pawn()
{
}

std::vector<Coord> Pawn::GetPossibleMoves() const
{
    std::vector<Coord> possibleMoves;
    if (color == Color::White)
    {
        if (position.y + 1 < 9)
        {
            possibleMoves.push_back(Coord(position.x, position.y + 1));
            if (position.x + 1 < 9)
            {
                possibleMoves.push_back(Coord(position.x + 1, position.y + 1));
            }
            if (position.x - 1 > 0)
            {
                possibleMoves.push_back(Coord(position.x - 1, position.y + 1));
            }
        }
        if (hasMoved == false && position.y + 2 < 9)
        {
            possibleMoves.push_back(Coord(position.x, position.y + 2));
        }
    }

    if (color == Color::Black)
    {
        if (position.y - 1 > 0)
        {
            possibleMoves.push_back(Coord(position.x, position.y - 1));
            if (position.x + 1 < 9)
            {
                possibleMoves.push_back(Coord(position.x + 1, position.y - 1));
            }
            if (position.x - 1 > 0)
            {
                possibleMoves.push_back(Coord(position.x - 1, position.y - 1));
            }
        }
        if (hasMoved == false && position.y - 2 > 0)
        {
            possibleMoves.push_back(Coord(position.x, position.y - 2));
        }
    }
    return possibleMoves;
}