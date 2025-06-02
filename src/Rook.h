#ifndef ROOK_H
#define ROOK_H

#include "Piece.h"

class Rook : public Piece
{
    public:
        Rook(Color color, Coord position);
        ~Rook() override;
};

#endif