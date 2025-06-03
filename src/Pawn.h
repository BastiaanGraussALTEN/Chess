#ifndef PAWN_H
#define PAWN_H

#include "Piece.h"

class Pawn : public Piece
{
    public:
        Pawn(Color color, Square position);
        ~Pawn() override;
        std::vector<Square> GetPossibleMoves() const;
        bool hasMoved;
};

#endif