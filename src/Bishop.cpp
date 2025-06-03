#include "Bishop.h"

Bishop::Bishop(Color color, Coord position) : Piece(color, position)
{
}

Bishop::~Bishop()
{
}

std::vector<Coord> Bishop::GetPossibleMoves()
{
    std::vector<Coord> possibleMoves;
    for (int i = 1; i < 8; i++)
    {
        if (position.x + i < 9)
        {
            if (position.y + i < 9)
            {
                possibleMoves.push_back(Coord(position.x + i, position.y + i));
            }
            if (position.y - i > 0)
            {
                possibleMoves.push_back(Coord(position.x + i, position.y - i));
            }
        }
        if (position.x - i > 0)
        {
            if (position.y + i < 9)
            {
                possibleMoves.push_back(Coord(position.x - i, position.y + i));
            }
            if (position.y - i > 0)
            {
                possibleMoves.push_back(Coord(position.x - i, position.y - i));
            }
        }
    }

    return possibleMoves;
}