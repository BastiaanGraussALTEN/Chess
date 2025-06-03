#ifndef KINGHT_H
#define KNIGHT_H

#include "Piece.h"

class Knight : public Piece
{
    public:
        Knight(Color color, Square position);
        ~Knight() override;
        std::vector<Square> GetPossibleMoves() const;
};

#endif