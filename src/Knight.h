#ifndef KINGHT_H
#define KNIGHT_H

#include "Piece.h"

class Knight : public Piece
{
    public:
        Knight(Color color, Coord position);
        ~Knight() override;
        std::vector<Coord> GetPossibleMoves() const;
};

#endif