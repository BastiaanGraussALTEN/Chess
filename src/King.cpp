#include "King.h"

King::King(Color color, Coord position) : Piece(color, position)
{
}

King::~King()
{
}

std::vector<Coord> King::GetPossibleMoves()
{
    return std::vector<Coord>();
}