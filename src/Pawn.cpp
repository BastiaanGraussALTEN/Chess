#include "Pawn.h"

Pawn::Pawn(Color color, Coord position) : Piece(color, position)
{
}

Pawn::~Pawn()
{
}

std::vector<Coord> Pawn::GetPossibleMoves()
{
    return std::vector<Coord>();
}