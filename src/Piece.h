#ifndef PIECE_H
#define PIECE_H

#include <vector>
#include "Color.h"
#include "Square.h"
#include "PieceType.h"

class Piece
{
    public:
        explicit Piece(Color color, PieceType pieceType, Square positionOfPiece);
        virtual ~Piece();
        virtual std::vector<Square> GetPossibleMoves() const = 0;
        bool hasMoved;
        Color color;
        PieceType pieceType;
        Square position;
};

#endif