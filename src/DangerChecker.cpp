#include "DangerChecker.h"

DangerChecker::DangerChecker(const Board& board, const LegalityChecker& legalityChecker, const Color& color) 
: m_board(board), m_legalityChecker(legalityChecker), m_color(color)
{
}

bool DangerChecker::IsKingUnderAttack()
{
    return false;
}

bool DangerChecker::IsSquareUnderAttack(Square squaee)
{
    return false;
}
