#pragma once

#include "DangerChecker.h"

class CheckChecker
{
    public:
        CheckChecker(const Board& board, const Color& color);
        bool IsKingSafeAfterMove(const Move& move) const;
        bool EveryMoveChecksSelf() const;
    private:
        Board m_board;
        Color m_color;
};