#pragma once

#include <stdexcept>
#include <functional>

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
    bool operator<(const Square& other) const 
    {
        return (y < other.y) || (y == other.y && x < other.x);
    }
    std::string ToString() const 
    {
        return "(" + std::to_string(x) + "," + std::to_string(y) + ")";
    }
    int x;
    int y;
};


namespace std 
{
    template <>
    struct hash<Square> 
    {
        size_t operator()(const Square& s) const noexcept 
        {
            size_t h1 = std::hash<int>{}(s.x);
            size_t h2 = std::hash<int>{}(s.y);
            return h1 ^ (h2 + 0x9e3779b9 + (h1 << 6) + (h1 >> 2));
        }
    };
}
