#ifndef KING_H
#define KING_H

#include "Piece.h"

class King : public Piece
{
    public:
        explicit King(Color color, Square position);
        ~King() override;
        std::shared_ptr<Piece> clone() const override {return std::make_shared<King>(*this);}
        std::vector<Square> GetPossibleMoves() const override;
};

#endif