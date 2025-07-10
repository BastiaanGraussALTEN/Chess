#include "../header/Piece.h"
#include <iostream>

Piece::Piece(Color color, PieceType pieceType, Square positionOfPiece) 
: color(color), pieceType(pieceType), position(positionOfPiece)
{
    hasMoved = false;
}

bool Piece::operator==(const Piece &rhs) const
{
    if (typeid(*this) != typeid(rhs)) 
    {
        return false;
    }

    return position == rhs.position 
    && color == rhs.color 
    && pieceType == rhs.pieceType 
    && hasMoved == rhs.hasMoved;
}

std::string Piece::ToString() const 
{
    return "Piece: " + PieceTypeToString(pieceType) 
    + ", Color: " + ColorToString(color)
    + ", Position: " + SquareToString(position)
    + ", HasMoved: " + (hasMoved ? "true" : "false");
}

std::string Piece::ColorToString(Color color) const 
{
    switch(color) 
    {
        case Color::White: return "White";
        case Color::Black: return "Black";
        default: return "UnknownColor";
    }
}

std::string Piece::PieceTypeToString(PieceType pieceType) const 
{
    switch(pieceType) 
    {
        case PieceType::Pawn: return "Pawn";
        case PieceType::Knight: return "Knight";
        case PieceType::Bishop: return "Bishop";
        case PieceType::Rook: return "Rook";
        case PieceType::Queen: return "Queen";
        case PieceType::King: return "King";
        default: return "UnknownType";
    }
}

std::string Piece::SquareToString(const Square& sq) const 
{
    return "(" + std::to_string(sq.x) + "," + std::to_string(sq.y) + ")";
}