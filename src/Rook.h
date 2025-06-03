#ifndef ROOK_H
#define ROOK_H

#include "Piece.h"

class Rook : public Piece
{
    public:
        Rook(Color color, Square position);
        ~Rook() override;
        std::vector<Square> GetPossibleMoves() const;
};

#endif