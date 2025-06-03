#ifndef PAWN_H
#define PAWN_H

#include "Piece.h"

class Pawn : public Piece
{
    public:
        Pawn(Color color, Coord position);
        ~Pawn() override;
        std::vector<Coord> GetPossibleMoves() const;
        bool hasMoved;
};

#endif