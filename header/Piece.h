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

namespace std 
{
    template<>
    struct hash<Piece> 
    {
        size_t operator()(const Piece& p) const noexcept 
        {
            size_t h1 = std::hash<int>{}(static_cast<int>(p.color));
            size_t h2 = std::hash<int>{}(static_cast<int>(p.pieceType));
            size_t h3 = std::hash<Square>{}(p.position);

            size_t combined = h1;
            combined ^= h2 + 0x9e3779b9 + (combined << 6) + (combined >> 2);
            combined ^= h3 + 0x9e3779b9 + (combined << 6) + (combined >> 2);

            return combined;
        }
    };
}