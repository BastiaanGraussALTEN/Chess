#include "gtest/gtest.h"
#include "../header/Square.h"

TEST(CoordTest, coordCanBeConstructed)
{
    // Arrange 
    Square coord = Square(1,2);

    // Act - no act

    // Assert
    EXPECT_EQ(coord.x,  1);
    EXPECT_EQ(coord.y,  2);
}

TEST(CoordTest, coordCanBeConstructed2)
{
    // Arrange 
    Square coord = Square(8,8);

    // Act - no act

    // Assert
    EXPECT_EQ(coord.x,  8);
    EXPECT_EQ(coord.y,  8);
}

TEST(CoordTest, exceptionThrownWhenOutOfRange)
{
    // Arrange - no arrange

    // Act - no act

    // Assert
    EXPECT_THROW(Square(0, 1), std::invalid_argument);
    EXPECT_THROW(Square(1, 0), std::invalid_argument);
    EXPECT_THROW(Square(9, 1), std::invalid_argument);
    EXPECT_THROW(Square(1, 9), std::invalid_argument);
}