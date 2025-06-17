#ifndef QUEEN_H
#define QUEEN_H

#include "Piece.h"

class Queen : public Piece
{
    public:
        explicit Queen(Color color, Square position);
        ~Queen() override;
        std::shared_ptr<Piece> clone() const override {return std::make_shared<Queen>(*this);}
        std::vector<Square> GetPossibleMoves() const override;
};

#endif