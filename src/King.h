#ifndef KING_H
#define KING_H

#include "Piece.h"

class King : public Piece
{
    public:
        King(Color color, Coord position);
        ~King() override;
        std::vector<Coord> GetPossibleMoves() const;
        bool hasMoved;
};

#endif