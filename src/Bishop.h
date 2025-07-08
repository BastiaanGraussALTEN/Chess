#ifndef BISHOP_H
#define BISHOP_H

#include "Piece.h"

class Bishop : public Piece
{
    public:
        explicit Bishop(Color color, Square position);
        std::shared_ptr<Piece> clone() const override {return std::make_shared<Bishop>(*this);}
        std::vector<Square> GetPossibleMoves() const override;
};

#endif