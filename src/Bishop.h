#ifndef BISHOP_H
#define BISHOP_H

#include "Piece.h"

class Bishop : public Piece
{
    public:
        Bishop(Color color, Square position);
        ~Bishop() override;
        std::vector<Square> GetPossibleMoves() const;
};

#endif