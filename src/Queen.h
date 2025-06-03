#ifndef QUEEN_H
#define QUEEN_H

#include "Piece.h"

class Queen : public Piece
{
    public:
        Queen(Color color, Coord position);
        ~Queen() override;
        std::vector<Coord> GetPossibleMoves() const;
};

#endif