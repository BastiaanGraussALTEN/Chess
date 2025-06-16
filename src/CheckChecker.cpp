#include "CheckChecker.h"

CheckChecker::CheckChecker(const Board &board, const Color &color)
: m_board(board), m_color(color)
{
}

bool CheckChecker::DoesMovePreventCheck(const Move &move)
{
    Board boardCopy = m_board;
    boardCopy.MovePiece(move);
    LegalityChecker legalityChecker(boardCopy);
    DangerChecker dangerChecker(boardCopy, legalityChecker, m_color);
    return dangerChecker.IsKingUnderAttack();
}