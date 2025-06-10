#include "PositionFunctions.h"

bool PositionFunctions::IsMoveDiagonal(const Move &move)
{
    if (abs(move.start.x - move.end.x) == abs(move.start.y - move.end.y))
    {
        return true;
    }

    return false;
}

bool PositionFunctions::IsMoveOrthogonal(const Move &move)
{
    if (move.start.x - move.end.x == 0 && move.start.y - move.end.y != 0)
    {
        return true;
    }
    if (move.start.x - move.end.x != 0 && move.start.y - move.end.y == 0)
    {
        return true;
    }

    return false;
}

bool PositionFunctions::IsPieceInDiagonal(const Move &move)
{
    return false;
}

bool PositionFunctions::IsPieceInLine(const Move &move)
{
    return false;
}

std::vector<Square> PositionFunctions::GetDiagonalsInBetween(const Move &move, int amoundtOfInBetweenSteps)
{
    return std::vector<Square>();
}

std::vector<Square> PositionFunctions::GetOrthogonalsInBetween(const Move &move, int amoundtOfInBetweenSteps)
{
    return std::vector<Square>();
}
