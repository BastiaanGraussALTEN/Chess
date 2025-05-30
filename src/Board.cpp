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

void Board::CreateInitialBoardState()
{
    // Create pawns
    for (int i = 1; i < 9; i++)
    {
        AddPiece(PieceFactory::CreatePawn(true, Coord(i, 2)));
        AddPiece(PieceFactory::CreatePawn(false, Coord(i, 7)));
    }

    // Create white pieces
    AddPiece(PieceFactory::CreateRook(true, Coord(1, 1)));
    AddPiece(PieceFactory::CreateKnight(true, Coord(2, 1)));
    AddPiece(PieceFactory::CreateBishop(true, Coord(3, 1)));
    AddPiece(PieceFactory::CreateQueen(true, Coord(4, 1)));
    AddPiece(PieceFactory::CreateKing(true, Coord(5, 1)));
    AddPiece(PieceFactory::CreateBishop(true, Coord(6, 1)));
    AddPiece(PieceFactory::CreateKnight(true, Coord(7, 1)));
    AddPiece(PieceFactory::CreateRook(true, Coord(8, 1)));
    
    // Create black pieces
    AddPiece(PieceFactory::CreateRook(false, Coord(1, 8)));
    AddPiece(PieceFactory::CreateKnight(false, Coord(2, 8)));
    AddPiece(PieceFactory::CreateBishop(false, Coord(3, 8)));
    AddPiece(PieceFactory::CreateQueen(false, Coord(4, 8)));
    AddPiece(PieceFactory::CreateKing(false, Coord(5, 8)));
    AddPiece(PieceFactory::CreateBishop(false, Coord(6, 8)));
    AddPiece(PieceFactory::CreateKnight(false, Coord(7, 8)));
    AddPiece(PieceFactory::CreateRook(false, Coord(8, 8)));
}
