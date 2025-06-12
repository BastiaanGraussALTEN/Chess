#include "CastleChecker.h"

CastleChecker::CastleChecker(const Board &board, const LegalityChecker &legalityChecker, const DangerChecker &dangerChecker, const Color& color)
: m_board(board), m_legalityChecker(legalityChecker), m_dangerChecker(dangerChecker), m_color(color)
{
}

bool CastleChecker::CanCastleKingSide() const
{
    // creating the right squares
    Square kingSquare = Square(5, 1);
    Square rookSquare = Square(8, 1);
    std::vector<Square> inBetweenSquares = {Square(6, 1), Square(7 ,1)};
    if (m_color == Color::Black)
    {
        kingSquare = Square(5, 8);
        rookSquare = Square(8, 8);
        std::vector<Square> inBetweenSquares = {Square(6, 8), Square(7, 8)};
    }

    // king and rook on the right squares
    if ((m_board.GetPieceFromSquare(kingSquare) == nullptr)
    || (m_board.GetPieceFromSquare(rookSquare) == nullptr)
    || (m_board.GetPieceFromSquare(kingSquare)->pieceType != PieceType::KingType)
    || (m_board.GetPieceFromSquare(rookSquare)->pieceType != PieceType::RookType))
    {
        return false;
    }

    // king and rook have not moved
    if ((m_board.GetPieceFromSquare(kingSquare)->hasMoved == true)
    || (m_board.GetPieceFromSquare(rookSquare)->hasMoved == true))
    {
        return false;
    }

    // there are no pieces in between them

    // the king is not attacked

    // no square the king goes to is attacked
    return true;
}

bool CastleChecker::CanCastleQueenSide() const
{
    return false;
}
