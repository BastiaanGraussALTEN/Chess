#include "Knight.h"

Knight::Knight(Color color, Coord position) : Piece(color, position)
{
}

Knight::~Knight()
{
}

std::vector<Coord> Knight::GetPossibleMoves() const
{
    return std::vector<Coord>();
}
