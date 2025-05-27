#include "gtest/gtest.h"
#include "../src/Pawn.h"

TEST(PawnTest, pawnCanBeMade) 
{
    // Arrange
    Coord coord = Coord(1,2);
    bool isWhite = true;

    // Act
    Pawn pawn = Pawn(isWhite, coord);

    // Assert
    EXPECT_EQ(pawn.position.x,  1);
    EXPECT_EQ(pawn.position.y,  2);
    EXPECT_EQ(pawn.isWhite,  true);
}