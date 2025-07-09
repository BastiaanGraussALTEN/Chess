#pragma once

#include "Piece.h"

class Rook : public Piece
{
    public:
        explicit Rook(Color color, Square position);
        std::shared_ptr<Piece> clone() const override {return std::make_shared<Rook>(*this);}
        std::vector<Square> GetPossibleMoves() const override;
};