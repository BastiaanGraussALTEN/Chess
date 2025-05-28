#ifndef ROOK_H
#define ROOK_H

#include "Piece.h"

class Rook : public Piece
{
    public:
        Rook(bool isWhite, Coord position);
};

#endif