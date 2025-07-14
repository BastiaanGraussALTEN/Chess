#pragma once

#include "DangerChecker.h"

class CheckChecker
{
    public:
        CheckChecker(const Board& board, const Color& color);
        bool IsKingSafeAfterMove(const Move& move) const;
        bool EveryMoveChecksSelf() const;
        bool SufficientMaterialForCheckmate() const;
    private:
        bool PiecesAreOnSameColor(const std::shared_ptr<Piece>& piece1, const std::shared_ptr<Piece>& piece2) const;
        Board m_board;
        Color m_color;
};