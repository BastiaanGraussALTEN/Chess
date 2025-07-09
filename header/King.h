#pragma once

#include "Piece.h"

class King : public Piece
{
    public:
        explicit King(Color color, Square position);
        std::shared_ptr<Piece> clone() const override {return std::make_shared<King>(*this);}
        std::vector<Square> GetPossibleMoves() const override;
};