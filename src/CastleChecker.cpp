#include "CastleChecker.h"
#include "PositionFunctions.h"

CastleChecker::CastleChecker(const Board &board, const LegalityChecker &legalityChecker, const DangerChecker &dangerChecker, const Color& color)
: m_board(board), m_legalityChecker(legalityChecker), m_dangerChecker(dangerChecker), m_color(color)
{
}

bool CastleChecker::CanCastleKingSide() const
{
    // creating the right squares
    Square kingSquare = Square(5, 1);
    Square rookSquare = Square(8, 1);
    int amountInBetween = 2;
    if (m_color == Color::Black)
    {
        kingSquare = Square(5, 8);
        rookSquare = Square(8, 8);
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
    
    // the king is not attacked
    if (m_dangerChecker.IsKingUnderAttack() == true)
    {
        return false;
    }


    std::vector<Square> kingSquares = PositionFunctions::GetOrthogonalsInBetween(Move(kingSquare, rookSquare), amountInBetween);
    for (int i = 0; i < kingSquares.size(); i++)
    {
        // there are no pieces in between them
        if (m_board.GetPieceFromSquare(kingSquares[i]) != nullptr)
        {
            return false;
        }
        // no square the king goes to is attacked
        // if (m_dangerChecker.IsSquareUnderAttack(kingSquares[i]))
        // {
        //     return false;
        // }
    }


    return true;
}

bool CastleChecker::CanCastleQueenSide() const
{
    return false;
}
