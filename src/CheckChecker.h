#pragma once

#include "DangerChecker.h"

class CheckChecker
{
    public:
        CheckChecker(const Board& board, const Color& color);
        bool DoesMovePreventCheck(const Move& move);
    private:
        Board m_board;
        Color m_color;
};