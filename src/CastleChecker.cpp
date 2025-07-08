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
    
    std::vector<Square> kingSquares = PositionFunctions::GetOrthogonalsInBetween(Move(kingSquare, rookSquare), amountInBetween);
    return (KingAndRookAreOnCorrectSquare(kingSquare, rookSquare)) 
    && !(KingOrRookHasMoved(kingSquare, rookSquare))
    && !(m_dangerChecker.IsKingUnderAttack())
    && !(IsAPieceBetweenKingAndRook(kingSquares))
    && !(KingMovesOverAttackSquare(kingSquares));
}

bool CastleChecker::CanCastleQueenSide() const
{
    // creating the right squares
    Square kingSquare = Square(5, 1);
    Square rookSquare = Square(1, 1);
    int amountKingMoves = 2;
    int amountInBetween = 3;
    if (m_color == Color::Black)
    {
        kingSquare = Square(5, 8);
        rookSquare = Square(1, 8);
    }

    std::vector<Square> kingSquares = PositionFunctions::GetOrthogonalsInBetween(Move(kingSquare, rookSquare), amountKingMoves);
    std::vector<Square> inBetweenSquares = PositionFunctions::GetOrthogonalsInBetween(Move(kingSquare, rookSquare), amountInBetween);

    return (KingAndRookAreOnCorrectSquare(kingSquare, rookSquare)) 
    && !(KingOrRookHasMoved(kingSquare, rookSquare))
    && !(m_dangerChecker.IsKingUnderAttack())
    && !(IsAPieceBetweenKingAndRook(inBetweenSquares))
    && !(KingMovesOverAttackSquare(kingSquares));
}

bool CastleChecker::KingAndRookAreOnCorrectSquare(Square kingSquare, Square rookSquare) const
{
    return (m_board.GetPieceFromSquare(kingSquare) != nullptr)
    && (m_board.GetPieceFromSquare(rookSquare) != nullptr)
    && (m_board.GetPieceFromSquare(kingSquare)->pieceType == PieceType::King)
    && (m_board.GetPieceFromSquare(rookSquare)->pieceType == PieceType::Rook);
}

bool CastleChecker::KingOrRookHasMoved(Square kingSquare, Square rookSquare) const
{
    return (m_board.GetPieceFromSquare(kingSquare)->hasMoved == true)
    || (m_board.GetPieceFromSquare(rookSquare)->hasMoved == true);
}

bool CastleChecker::IsAPieceBetweenKingAndRook(std::vector<Square> kingSquares) const
{
    for (int i = 0; i < kingSquares.size(); i++)
    {
        if (m_board.GetPieceFromSquare(kingSquares[i]))
        {
            return true;
        }
    }

    return false;
}

bool CastleChecker::KingMovesOverAttackSquare(std::vector<Square> kingSquares) const
{
    for (int i = 0; i < kingSquares.size(); i++)
    {
        if (m_dangerChecker.IsSquareUnderAttack(kingSquares[i]))
        {
            return true;
        }
    }

    return false;
}
