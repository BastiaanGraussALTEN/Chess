#ifndef KING_H
#define KING_H

#include "Piece.h"

class King : public Piece
{
    public:
        King(Color color, Square position);
        ~King() override;
        std::vector<Square> GetPossibleMoves() const;
        bool hasMoved;
};

#endif