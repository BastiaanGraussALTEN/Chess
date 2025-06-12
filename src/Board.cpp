#include "Board.h"

Board::Board()
{
    CreateInitialBoardState();
}

const std::vector<std::shared_ptr<Piece>> &Board::GetPieces() const
{
    return m_pieces;
}

void Board::AddPiece(const std::shared_ptr<Piece> &piece)
{
    for (const auto& boardPiece : m_pieces)
    {
        if ( boardPiece->position == piece->position)
        {
            throw std::invalid_argument("there is a piece already on this square");
        }
    }

    m_pieces.push_back(piece);
}

void Board::RemovePieceFromSquare(const Square &coord)
{
    for (int i = 0; i < m_pieces.size(); i++)
    {
        if ( m_pieces[i]->position == coord)
        {
            m_pieces.erase( m_pieces.begin() + i );
        }
    }
}

void Board::MovePiece(const Move &move)
{
    auto piece = GetPieceFromSquare(move.start);
    if (piece == nullptr)
    {
        throw std::invalid_argument("there is no piece on this square");
    }
    else
    {
        piece->position = move.end;
    }
}

std::shared_ptr<Piece> Board::GetPieceFromSquare(const Square &coord) const
{
    for (const auto& piece : m_pieces)
    {
        if ( piece->position == coord)
        {
            return piece;
        }
    }

    return nullptr;
}

void Board::CreateInitialBoardState()
{
    // Create pawns
    for (int i = 1; i < 9; i++)
    {
        AddPiece(PieceFactory::CreatePawn(Color::White, Square(i, 2)));
        AddPiece(PieceFactory::CreatePawn(Color::Black, Square(i, 7)));
    }

    // Create white pieces
    AddPiece(PieceFactory::CreateRook(Color::White, Square(1, 1)));
    AddPiece(PieceFactory::CreateKnight(Color::White, Square(2, 1)));
    AddPiece(PieceFactory::CreateBishop(Color::White, Square(3, 1)));
    AddPiece(PieceFactory::CreateQueen(Color::White, Square(4, 1)));
    AddPiece(PieceFactory::CreateKing(Color::White, Square(5, 1)));
    AddPiece(PieceFactory::CreateBishop(Color::White, Square(6, 1)));
    AddPiece(PieceFactory::CreateKnight(Color::White, Square(7, 1)));
    AddPiece(PieceFactory::CreateRook(Color::White, Square(8, 1)));
    
    // Create black pieces
    AddPiece(PieceFactory::CreateRook(Color::Black, Square(1, 8)));
    AddPiece(PieceFactory::CreateKnight(Color::Black, Square(2, 8)));
    AddPiece(PieceFactory::CreateBishop(Color::Black, Square(3, 8)));
    AddPiece(PieceFactory::CreateQueen(Color::Black, Square(4, 8)));
    AddPiece(PieceFactory::CreateKing(Color::Black, Square(5, 8)));
    AddPiece(PieceFactory::CreateBishop(Color::Black, Square(6, 8)));
    AddPiece(PieceFactory::CreateKnight(Color::Black, Square(7, 8)));
    AddPiece(PieceFactory::CreateRook(Color::Black, Square(8, 8)));
}
