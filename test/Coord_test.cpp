#include "gtest/gtest.h"
#include "../src/Coord.cpp"

TEST(CoordTest, coordCanBeConstructed)
{
    // Arrange 
    Coord coord = Coord(1,2);

    // Act - no act

    // Assert
    EXPECT_EQ(coord.x,  1);
    EXPECT_EQ(coord.y,  2);
}

TEST(CoordTest, coordCanBeConstructed2)
{
    // Arrange 
    Coord coord = Coord(8,8);

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
    EXPECT_THROW(Coord(0, 1), std::out_of_range);
    EXPECT_THROW(Coord(1, 0), std::out_of_range);
    EXPECT_THROW(Coord(9, 1), std::out_of_range);
    EXPECT_THROW(Coord(1, 9), std::out_of_range);
}