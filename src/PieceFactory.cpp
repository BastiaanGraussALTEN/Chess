#include "PieceFactory.h"

std::shared_ptr<Piece> PieceFactory::CreatePawn(bool isWhite, Coord position)
{
    return std::make_shared<Pawn>(isWhite, position);
}

std::shared_ptr<Piece> PieceFactory::CreateBishop(bool isWhite, Coord position)
{
    return std::make_shared<Bishop>(isWhite, position);
}

std::shared_ptr<Piece> PieceFactory::CreateKnight(bool isWhite, Coord position)
{
    return std::make_shared<Knight>(isWhite, position);
}

std::shared_ptr<Piece> PieceFactory::CreateRook(bool isWhite, Coord position)
{
    return std::make_shared<Rook>(isWhite, position);
}

std::shared_ptr<Piece> PieceFactory::CreateQueen(bool isWhite, Coord position)
{
    return std::make_shared<Queen>(isWhite, position);
}

std::shared_ptr<Piece> PieceFactory::CreateKing(bool isWhite, Coord position)
{
    return std::make_shared<King>(isWhite, position);
}
