#include "Queen.h"

Queen::Queen(Color color, Coord position) : Piece(color, position)
{
}

Queen::~Queen()
{
}

std::vector<Coord> Queen::GetPossibleMoves()
{
    return std::vector<Coord>();
}