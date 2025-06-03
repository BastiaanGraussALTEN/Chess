#include "Knight.h"

Knight::Knight(Color color, Coord position) : Piece(color, position)
{
}

Knight::~Knight()
{
}

std::vector<Coord> Knight::GetPossibleMoves()
{
    return std::vector<Coord>();
}
