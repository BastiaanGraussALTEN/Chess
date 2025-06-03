#include "Rook.h"

Rook::Rook(Color color, Coord position) : Piece(color, position)
{
}

Rook::~Rook()
{
}

std::vector<Coord> Rook::GetPossibleMoves()
{
    std::vector<Coord> possibleMoves;
    for (int i = 1; i < 9; i++)
    {
        if (i != position.y)
        {
            possibleMoves.push_back(Coord(position.x, i));
        }
        if (i != position.x)
        {
            possibleMoves.push_back(Coord(i, position.y));
        }
    }

    return possibleMoves;
}
