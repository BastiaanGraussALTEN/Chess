#pragma once

#include "Piece.h"

class Pawn : public Piece
{
    public:
    explicit Pawn(Color color, Square position);
    std::shared_ptr<Piece> clone() const override {return std::make_shared<Pawn>(*this);}
    std::vector<Square> GetPossibleMoves() const;
};