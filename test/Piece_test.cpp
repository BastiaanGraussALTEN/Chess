#include "gtest/gtest.h"
#include "../src/Pawn.h"
#include "../src/Bishop.h"
#include "../src/Knight.h"
#include "../src/Rook.h"
#include "../src/Queen.h"
#include "../src/King.h"

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

TEST(PieceTest, knightCanBeMade) 
{
    // Arrange
    Coord coord = Coord(1,2);
    bool isWhite = true;

    // Act
    Knight knight = Knight(isWhite, coord);

    // Assert
    EXPECT_EQ(knight.position.x,  1);
    EXPECT_EQ(knight.position.y,  2);
    EXPECT_EQ(knight.isWhite,  true);
}

TEST(PieceTest, rookpCanBeMade) 
{
    // Arrange
    Coord coord = Coord(1,2);
    bool isWhite = true;

    // Act
    Rook rook = Rook(isWhite, coord);

    // Assert
    EXPECT_EQ(rook.position.x,  1);
    EXPECT_EQ(rook.position.y,  2);
    EXPECT_EQ(rook.isWhite,  true);
}

TEST(PieceTest, queenCanBeMade) 
{
    // Arrange
    Coord coord = Coord(1,2);
    bool isWhite = true;

    // Act
    Queen queen = Queen(isWhite, coord);

    // Assert
    EXPECT_EQ(queen.position.x,  1);
    EXPECT_EQ(queen.position.y,  2);
    EXPECT_EQ(queen.isWhite,  true);
}

TEST(PieceTest, kingCanBeMade) 
{
    // Arrange
    Coord coord = Coord(1,2);
    bool isWhite = true;

    // Act
    King king = King(isWhite, coord);

    // Assert
    EXPECT_EQ(king.position.x,  1);
    EXPECT_EQ(king.position.y,  2);
    EXPECT_EQ(king.isWhite,  true);
}