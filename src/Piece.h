#ifndef PIECE_H
#define PIECE_H

#include <vector>
#include <memory>
#include "Color.h"
#include "Square.h"
#include "PieceType.h"

class Piece
{
    public:
        explicit Piece(Color color, PieceType pieceType, Square positionOfPiece);
        virtual ~Piece();
        virtual std::shared_ptr<Piece> clone() const = 0;
        virtual std::vector<Square> GetPossibleMoves() const = 0;
        bool hasMoved;
        Color color;
        PieceType pieceType;
        Square position;
};

#endif