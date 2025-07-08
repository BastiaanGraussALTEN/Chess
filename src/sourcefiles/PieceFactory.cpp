#include "../headerfiles/PieceFactory.h"

std::shared_ptr<Pawn> PieceFactory::CreatePawn(Color color, Square position)
{
    return std::make_shared<Pawn>(color, position);
}

std::shared_ptr<Bishop> PieceFactory::CreateBishop(Color color, Square position)
{
    return std::make_shared<Bishop>(color, position);
}

std::shared_ptr<Knight> PieceFactory::CreateKnight(Color color, Square position)
{
    return std::make_shared<Knight>(color, position);
}

std::shared_ptr<Rook> PieceFactory::CreateRook(Color color, Square position)
{
    return std::make_shared<Rook>(color, position);
}

std::shared_ptr<Queen> PieceFactory::CreateQueen(Color color, Square position)
{
    return std::make_shared<Queen>(color, position);
}

std::shared_ptr<King> PieceFactory::CreateKing(Color color, Square position)
{
    return std::make_shared<King>(color, position);
}
