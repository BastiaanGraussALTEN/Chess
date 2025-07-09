#include "../headerfiles/DangerChecker.h"
#include "../headerfiles/PositionFunctions.h"

DangerChecker::DangerChecker(const Board& board, const Color& color) 
: m_board(board), m_color(color), m_legalityChecker(LegalityChecker(board))
{
}

bool DangerChecker::IsKingUnderAttack() const
{
    Square kingSquare = GetKingPosition();
    for (auto piece : m_board.GetPieces())
    {
        if (piece->color != m_color)
        {
            std::vector<Square> possibleMoves = piece->GetPossibleMoves();
            for (auto square : possibleMoves)
            {
                if ((square == kingSquare) 
                && (m_legalityChecker.CheckMoveLegality(Move(piece->position, square))))
                {
                    return true;
                }
            }
        }
    }
    return false;
}

bool DangerChecker::IsSquareUnderAttack(Square Targetsquare) const
{
    for (auto piece : m_board.GetPieces())
    {
        if (piece->color != m_color)
        {
            std::vector<Square> possibleMoves = piece->GetPossibleMoves();
            if (piece->pieceType == PieceType::Pawn)
            {
                for (auto square : possibleMoves)
                {
                    if ((square == Targetsquare) 
                    && (PositionFunctions::IsMoveDiagonal(Move(piece->position, square))))
                    {
                        return true;
                    }
                }
            }
            
            else
            {
                for (auto square : possibleMoves)
                {
                    if ((square == Targetsquare) 
                    && (m_legalityChecker.CheckMoveLegality(Move(piece->position, square))))
                    {
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

Square DangerChecker::GetKingPosition() const
{
    for (auto piece : m_board.GetPieces())
    {
        if ((piece->color == m_color) && (piece->pieceType == PieceType::King))
        {
            return piece->position;
        }
    }

    throw std::domain_error("No king is found");
}
