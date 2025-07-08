#pragma once

#include "Piece.h"

class Knight : public Piece
{
    public:
        explicit Knight(Color color, Square position);
        std::shared_ptr<Piece> clone() const override {return std::make_shared<Knight>(*this);}
        std::vector<Square> GetPossibleMoves() const override;
};