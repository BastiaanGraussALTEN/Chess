#ifndef BISHOP_H
#define BISHOP_H

#include "Piece.h"

class Bishop : public Piece
{
    public:
        Bishop(Color color, Coord position);
        ~Bishop() override;
        std::vector<Coord> GetPossibleMoves();
};

#endif