#include "gtest/gtest.h"
#include "../src/PieceFactory.h"

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

TEST(PieceTest, pawnCanBeMadeUsingFactory) 
{
    // Arrange
    Coord coord = Coord(1,2);
    bool isWhite = true;

    // Act
    auto pawn = PieceFactory::CreatePawn(isWhite, coord);

    // Assert
    EXPECT_EQ(pawn->position.x,  1);
    EXPECT_EQ(pawn->position.y,  2);
    EXPECT_EQ(pawn->isWhite,  true);
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

TEST(PieceTest, bishopCanBeMadeUsingFactory) 
{
    // Arrange
    Coord coord = Coord(1,2);
    bool isWhite = true;

    // Act
    auto bishop = PieceFactory::CreateBishop(isWhite, coord);

    // Assert
    EXPECT_EQ(bishop->position.x,  1);
    EXPECT_EQ(bishop->position.y,  2);
    EXPECT_EQ(bishop->isWhite,  true);
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

TEST(PieceTest, knightCanBeMadeUsingFactory) 
{
    // Arrange
    Coord coord = Coord(1,2);
    bool isWhite = true;

    // Act
    auto knight = PieceFactory::CreateKnight(isWhite, coord);

    // Assert
    EXPECT_EQ(knight->position.x,  1);
    EXPECT_EQ(knight->position.y,  2);
    EXPECT_EQ(knight->isWhite,  true);
}

TEST(PieceTest, rookCanBeMade) 
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

TEST(PieceTest, rookCanBeMadeUsingFactory) 
{
    // Arrange
    Coord coord = Coord(1,2);
    bool isWhite = true;

    // Act
    auto rook = PieceFactory::CreateRook(isWhite, coord);

    // Assert
    EXPECT_EQ(rook->position.x,  1);
    EXPECT_EQ(rook->position.y,  2);
    EXPECT_EQ(rook->isWhite,  true);
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

TEST(PieceTest, queenCanBeMadeUsingFactory) 
{
    // Arrange
    Coord coord = Coord(1,2);
    bool isWhite = true;

    // Act
    auto queen = PieceFactory::CreateQueen(isWhite, coord);

    // Assert
    EXPECT_EQ(queen->position.x,  1);
    EXPECT_EQ(queen->position.y,  2);
    EXPECT_EQ(queen->isWhite,  true);
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

TEST(PieceTest, kingCanBeMadeUsingFactory) 
{
    // Arrange
    Coord coord = Coord(1,2);
    bool isWhite = true;

    // Act
    auto king = PieceFactory::CreateKing(isWhite, coord);

    // Assert
    EXPECT_EQ(king->position.x,  1);
    EXPECT_EQ(king->position.y,  2);
    EXPECT_EQ(king->isWhite,  true);
}