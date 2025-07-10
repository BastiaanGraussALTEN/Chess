#include "../header/Piece.h"

Piece::Piece(Color color, PieceType pieceType, Square positionOfPiece) 
: color(color), pieceType(pieceType), position(positionOfPiece)
{
}

bool Piece::operator==(const Piece &rhs) const
{
    return this->position == rhs.position 
    && this->color == rhs.color 
    && this->pieceType == rhs.pieceType 
    && this->hasMoved == rhs.hasMoved;
}