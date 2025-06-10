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

std::vector<Square> PositionFunctions::GetDiagonalsInBetween(const Move &move, int amoundtOfInBetweenSteps)
{
    std::vector<Square> inBetweenSteps;
    // move is to the right
    if (move.end.x - move.start.x > 0)
    {
        // move is upwards
        if (move.end.y - move.start.y > 0)
        {
            for (int i = 1; i < amoundtOfInBetweenSteps + 1; i++)
            {
                inBetweenSteps.push_back(Square(move.start.x + i, move.start.y + i));
            }
        }

        // move is downwards
        if (move.end.y - move.start.y < 0)
        {
            for (int i = 1; i < amoundtOfInBetweenSteps + 1; i++)
            {
                inBetweenSteps.push_back(Square(move.start.x + i, move.start.y - i));
            }
        }
    }

    // move is to the left
    if (move.end.x - move.start.x < 0)
    {
        // move is upwards
        if (move.end.y - move.start.y > 0)
        {
            for (int i = 1; i < amoundtOfInBetweenSteps + 1; i++)
            {
                inBetweenSteps.push_back(Square(move.start.x - i, move.start.y + i));
            }
        }

        // move is downwards
        if (move.end.y - move.start.y < 0)
        {
            for (int i = 1; i < amoundtOfInBetweenSteps + 1; i++)
            {
                inBetweenSteps.push_back(Square(move.start.x - i, move.start.y - i));
            }
        }
    }

    return inBetweenSteps;
}

std::vector<Square> PositionFunctions::GetOrthogonalsInBetween(const Move &move, int amoundtOfInBetweenSteps)
{
    std::vector<Square> inBetweenSteps;
    // move is to the right
    if (move.end.x - move.start.x > 0)
    {
        for (int i = 1; i < amoundtOfInBetweenSteps + 1; i++)
        {
            inBetweenSteps.push_back(Square(move.start.x + i, move.start.y));
        }
    }

    // move is to the left
    if (move.end.x - move.start.x < 0)
    {
        for (int i = 1; i < amoundtOfInBetweenSteps + 1; i++)
        {
            inBetweenSteps.push_back(Square(move.start.x - i, move.start.y));
        }
    }

    // move is upwards
    if (move.end.y - move.start.y > 0)
    {
        for (int i = 1; i < amoundtOfInBetweenSteps + 1; i++)
        {
            inBetweenSteps.push_back(Square(move.start.x, move.start.y + i));
        }
    }

    // move is downwards
    if (move.end.y - move.start.y < 0)
    {
        for (int i = 1; i < amoundtOfInBetweenSteps + 1; i++)
        {
            inBetweenSteps.push_back(Square(move.start.x, move.start.y - i));
        }
    }

    return inBetweenSteps;
}
