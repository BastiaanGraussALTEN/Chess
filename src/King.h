#ifndef KING_H
#define KING_H

#include "Piece.h"

class King : public Piece
{
    public:
        explicit King(Color color, Square position);
        ~King() override;
        std::vector<Square> GetPossibleMoves() const override;
        bool hasMoved;
};

#endif