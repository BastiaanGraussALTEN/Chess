#ifndef KINGHT_H
#define KNIGHT_H

#include "Piece.h"

class Knight : public Piece
{
    public:
        Knight(bool isWhite, Coord position);
        ~Knight() override;
};

#endif