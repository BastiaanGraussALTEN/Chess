#ifndef COORD
#define COORD

#include <stdexcept>

struct Square
{
    Square(int x_coord, int y_coord) :  x(x_coord), y(y_coord)
    {
        if (x < 1 || x > 8)
        {
            throw std::out_of_range("x is out of range");
        }
        if (y < 1 || y > 8)
        {
            throw std::out_of_range("y is out of range");
        }
    };
    bool operator==(const Square& rhs) const
    {
        return this->x == rhs.x && this->y == rhs.y;
    }
    int x;
    int y;
};


#endif
