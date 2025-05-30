#ifndef PAWN_H
#define PAWN_H

#include "Piece.h"

class Pawn : public Piece
{
    public:
        Pawn(bool isWhite, Coord position);
        ~Pawn() override;
};

#endif