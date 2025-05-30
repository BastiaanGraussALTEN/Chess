#ifndef BISHOP_H
#define BISHOP_H

#include "Piece.h"

class Bishop : public Piece
{
    public:
        Bishop(bool isWhite, Coord position);
        ~Bishop() override;
};

#endif