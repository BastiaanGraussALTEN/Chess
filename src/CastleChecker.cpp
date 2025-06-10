#include "CastleChecker.h"

CastleChecker::CastleChecker(const Board &board, const LegalityChecker &legalityChecker, const DangerChecker &dangerChecker, const Color& color)
: m_board(board), m_legalityChecker(legalityChecker), m_dangerChecker(dangerChecker), m_color(color)
{
}

bool CastleChecker::CanCastleKingSide() const
{
    Square kingSquare = Square(5, 1);
    Square rookSquare = Square(8, 1);
    if (m_color == Color::Black)
    {
        kingSquare = Square(5, 8);
        rookSquare = Square(8, 8);
    }

    if ((m_board.GetPieceFromCoord(kingSquare)->pieceType != PieceType::KingType)
    && (m_board.GetPieceFromCoord(rookSquare)->pieceType != PieceType::RookType))
    {
        return false;
    }
    // king and rook on their place and have not moved

    // there are no pieces in between them

    // the king is not attacked

    // no square the king goes to is attacked
    return true;
}

bool CastleChecker::CanCastleQueenSide() const
{
    return false;
}
