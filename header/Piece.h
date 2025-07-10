#pragma once

#include <vector>
#include <memory>
#include "Color.h"
#include "Square.h"
#include "PieceType.h"

class Piece
{
    public:
        explicit Piece(Color color, PieceType pieceType, Square positionOfPiece);
        virtual ~Piece(){};
        virtual bool operator==(const Piece& rhs) const;
        virtual std::shared_ptr<Piece> clone() const = 0;
        virtual std::vector<Square> GetPossibleMoves() const = 0;
        std::string ToString() const;
        bool hasMoved;
        Color color;
        PieceType pieceType;
        Square position;
    private:
        std::string ColorToString(Color color) const;
        std::string PieceTypeToString(PieceType pieceType) const;
        std::string SquareToString(const Square& sq) const;
};