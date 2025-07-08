#pragma once

#include <stdexcept>

struct Square
{
    Square(int x_coord, int y_coord) :  x(x_coord), y(y_coord)
    {
        if (x < 1 || x > 8)
        {
            throw std::invalid_argument("x is not between 1-8");
        }
        if (y < 1 || y > 8)
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
