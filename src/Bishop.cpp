#include "Bishop.h"

Bishop::Bishop(Color color, Coord position) : Piece(color, position)
{
}

Bishop::~Bishop()
{
}

std::vector<Coord> Bishop::GetPossibleMoves()
{
    return std::vector<Coord>();
}