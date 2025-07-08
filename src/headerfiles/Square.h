#pragma once

#include <stdexcept>
#include "Constants.h"

struct Square
{
    Square(int x_coord, int y_coord) :  x(x_coord), y(y_coord)
    {
        if (x < Constants::boardBegin || x > Constants::boardEnd)
        {
            throw std::invalid_argument("x is not between 1-8");
        }
        if (y < Constants::boardBegin || y > Constants::boardEnd)
        {
            throw std::invalid_argument("y is not between 1-8");
        }
    };
    Square(const Square& other) : x(other.x), y(other.y) {}
    bool operator==(const Square& rhs) const
    {
        return this->x == rhs.x && this->y == rhs.y;
    }
    int x;
    int y;
};
