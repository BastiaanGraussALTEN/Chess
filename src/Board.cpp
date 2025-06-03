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
    for (int i = 0; i < m_pieces.size(); i++)
    {
        if ( m_pieces[i]->position.x == piece->position.x && m_pieces[i]->position.y == piece->position.y)
        {
            throw std::out_of_range("there is a piece already on this coord");
        }
    }

    m_pieces.push_back(piece);
}

void Board::RemovePiece(const Coord &coord)
{
    for (int i = 0; i < m_pieces.size(); i++)
    {
        if ( m_pieces[i]->position.x == coord.x && m_pieces[i]->position.y == coord.y)
        {
            m_pieces.erase( m_pieces.begin() + i );
        }
    }
}

std::shared_ptr<Piece> Board::GetPieceFromCoord(const Coord &coord)
{
    for (int i = 0; i < m_pieces.size(); i++)
    {
        if ( m_pieces[i]->position.x == coord.x && m_pieces[i]->position.y == coord.y)
        {
            return m_pieces[i];
        }
    }

    return nullptr;
}

void Board::CreateInitialBoardState()
{
    // Create pawns
    for (int i = 1; i < 9; i++)
    {
        AddPiece(PieceFactory::CreatePawn(Color::White, Coord(i, 2)));
        AddPiece(PieceFactory::CreatePawn(Color::Black, Coord(i, 7)));
    }

    // Create white pieces
    AddPiece(PieceFactory::CreateRook(Color::White, Coord(1, 1)));
    AddPiece(PieceFactory::CreateKnight(Color::White, Coord(2, 1)));
    AddPiece(PieceFactory::CreateBishop(Color::White, Coord(3, 1)));
    AddPiece(PieceFactory::CreateQueen(Color::White, Coord(4, 1)));
    AddPiece(PieceFactory::CreateKing(Color::White, Coord(5, 1)));
    AddPiece(PieceFactory::CreateBishop(Color::White, Coord(6, 1)));
    AddPiece(PieceFactory::CreateKnight(Color::White, Coord(7, 1)));
    AddPiece(PieceFactory::CreateRook(Color::White, Coord(8, 1)));
    
    // Create black pieces
    AddPiece(PieceFactory::CreateRook(Color::Black, Coord(1, 8)));
    AddPiece(PieceFactory::CreateKnight(Color::Black, Coord(2, 8)));
    AddPiece(PieceFactory::CreateBishop(Color::Black, Coord(3, 8)));
    AddPiece(PieceFactory::CreateQueen(Color::Black, Coord(4, 8)));
    AddPiece(PieceFactory::CreateKing(Color::Black, Coord(5, 8)));
    AddPiece(PieceFactory::CreateBishop(Color::Black, Coord(6, 8)));
    AddPiece(PieceFactory::CreateKnight(Color::Black, Coord(7, 8)));
    AddPiece(PieceFactory::CreateRook(Color::Black, Coord(8, 8)));
}
