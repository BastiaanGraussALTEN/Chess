#include "PieceFactory.h"

std::shared_ptr<Piece> PieceFactory::CreatePawn(Color color, Coord position)
{
    return std::make_shared<Pawn>(color, position);
}

std::shared_ptr<Piece> PieceFactory::CreateBishop(Color color, Coord position)
{
    return std::make_shared<Bishop>(color, position);
}

std::shared_ptr<Piece> PieceFactory::CreateKnight(Color color, Coord position)
{
    return std::make_shared<Knight>(color, position);
}

std::shared_ptr<Piece> PieceFactory::CreateRook(Color color, Coord position)
{
    return std::make_shared<Rook>(color, position);
}

std::shared_ptr<Piece> PieceFactory::CreateQueen(Color color, Coord position)
{
    return std::make_shared<Queen>(color, position);
}

std::shared_ptr<Piece> PieceFactory::CreateKing(Color color, Coord position)
{
    return std::make_shared<King>(color, position);
}
