#ifndef QUEEN_H
#define QUEEN_H

#include "Piece.h"

class Queen : public Piece
{
    public:
        explicit Queen(Color color, Square position);
        ~Queen() override;
        std::vector<Square> GetPossibleMoves() const override;
};

#endif