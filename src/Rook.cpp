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
}
