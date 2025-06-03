#include "King.h"

King::King(Color color, Coord position) : Piece(color, position)
{
    hasMoved = false;
}

King::~King()
{
}

std::vector<Coord> King::GetPossibleMoves() const
{
    std::vector<Coord> possibleMoves;
    if (position.x + 1 < 9)
    {
        if (position.y + 1 < 9)
        {
            possibleMoves.push_back(Coord(position.x + 1, position.y + 1));
        }
        if (position.y - 1 > 0)
        {
            possibleMoves.push_back(Coord(position.x + 1, position.y - 1));
        }

        possibleMoves.push_back(Coord(position.x + 1, position.y));
    }

    if (position.x - 1 > 0)
    {
        if (position.y + 1 < 9)
        {
            possibleMoves.push_back(Coord(position.x - 1, position.y + 1));
        }
        if (position.y - 1 > 0)
        {
            possibleMoves.push_back(Coord(position.x - 1, position.y - 1));
        }

        possibleMoves.push_back(Coord(position.x - 1, position.y));
    }

    if (position.y + 1 < 9)
    {
        possibleMoves.push_back(Coord(position.x, position.y + 1));
    }

    if (position.y - 1 > 0)
    {
        possibleMoves.push_back(Coord(position.x , position.y - 1));
    }

    return possibleMoves;
}