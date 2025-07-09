#pragma once

#include "board.h"

class PositionFunctions
{
    public:
        static bool IsMoveDiagonal(const Move& move);
        static bool IsMoveOrthogonal(const Move& move);
        static std::vector<Square> GetDiagonalsInBetween(const Move &move, int amoundtOfInBetweenSteps);
        static std::vector<Square> GetOrthogonalsInBetween(const Move &move, int amoundtOfInBetweenSteps);
};