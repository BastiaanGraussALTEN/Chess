#ifndef PIECE_H
#define PIECE_H

#include <vector>
#include "Color.h"
#include "Square.h"

class Piece
{
    public:
        Piece(Color color, Square positionOfPiece);
        virtual ~Piece();
        virtual std::vector<Square> GetPossibleMoves() const = 0;
        Color color;
        Square position;
};

#endif