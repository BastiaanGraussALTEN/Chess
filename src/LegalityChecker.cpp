#include <algorithm>
#include "LegalityChecker.h"

LegalityChecker::LegalityChecker(const Board& board) : m_board(board)
{
}

bool LegalityChecker::CheckMoveLegality(Move move) const
{
    auto piece = m_board.GetPieceFromCoord(move.Start);
    std::vector<Square> possibleMoves = piece->GetPossibleMoves();
    if (std::find(possibleMoves.begin(), possibleMoves.end(), move.End) != possibleMoves.end())
    {
        return true;
    }
    return false;
}
