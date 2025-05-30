#include "Board.h"

const std::vector<std::shared_ptr<Piece>> &Board::GetPieces() const
{
    return m_pieces;
}

void Board::AddPiece(const std::shared_ptr<Piece> &piece)
{
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
