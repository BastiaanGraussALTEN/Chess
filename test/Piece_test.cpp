#include "gtest/gtest.h"
#include "../src/Pawn.h"
#include "../src/Bishop.h"

TEST(PieceTest, pawnCanBeMade) 
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

TEST(PieceTest, bishopCanBeMade) 
{
    // Arrange
    Coord coord = Coord(1,2);
    bool isWhite = true;

    // Act
    Bishop bishop = Bishop(isWhite, coord);

    // Assert
    EXPECT_EQ(bishop.position.x,  1);
    EXPECT_EQ(bishop.position.y,  2);
    EXPECT_EQ(bishop.isWhite,  true);
}