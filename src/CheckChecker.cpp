#include "../header/CheckChecker.h"

CheckChecker::CheckChecker(const Board &board, const Color &color)
: m_board(board), m_color(color)
{
}

bool CheckChecker::IsKingSafeAfterMove(const Move &move) const
{
    Board boardCopy = m_board;
    if (boardCopy.GetPieceFromSquare(move.end) != nullptr)
    {
        boardCopy.RemovePieceFromSquare(move.end);
    }
    boardCopy.MovePiece(move);
    LegalityChecker legalityChecker(boardCopy);
    DangerChecker dangerChecker(boardCopy, m_color);
    return !dangerChecker.IsKingUnderAttack();
}

bool CheckChecker::EveryMoveChecksSelf() const
{
    LegalityChecker legalityChecker = LegalityChecker(m_board);
    std::vector<Move> possibleMoves = legalityChecker.GetAllPossibleMoves(m_color);
    for (const Move& move : possibleMoves)
    {
        if (IsKingSafeAfterMove(move))
        {
            return false;
        }
    }

    return true;
}
bool CheckChecker::HasSufficientMaterial() const
{
    return false;
}