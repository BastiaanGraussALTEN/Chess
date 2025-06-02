#include "gtest/gtest.h"
#include "../src/PieceFactory.h"

TEST(PieceTest, pawnCanBeMade) 
{
    // Arrange
    Coord coord = Coord(1,2);

    // Act
    Pawn pawn = Pawn(Color::White, coord);

    // Assert
    EXPECT_EQ(pawn.position.x,  1);
    EXPECT_EQ(pawn.position.y,  2);
    EXPECT_EQ(pawn.color, Color::White);
}

TEST(PieceTest, pawnCanBeMadeUsingFactory) 
{
    // Arrange
    Coord coord = Coord(1,2);

    // Act
    auto pawn = PieceFactory::CreatePawn(Color::White, coord);

    // Assert
    EXPECT_EQ(pawn->position.x,  1);
    EXPECT_EQ(pawn->position.y,  2);
    EXPECT_EQ(pawn->color, Color::White);
}

TEST(PieceTest, bishopCanBeMade) 
{
    // Arrange
    Coord coord = Coord(1,2);

    // Act
    Bishop bishop = Bishop(Color::White, coord);

    // Assert
    EXPECT_EQ(bishop.position.x,  1);
    EXPECT_EQ(bishop.position.y,  2);
    EXPECT_EQ(bishop.color, Color::White);
}

TEST(PieceTest, bishopCanBeMadeUsingFactory) 
{
    // Arrange
    Coord coord = Coord(1,2);

    // Act
    auto bishop = PieceFactory::CreateBishop(Color::White, coord);

    // Assert
    EXPECT_EQ(bishop->position.x,  1);
    EXPECT_EQ(bishop->position.y,  2);
    EXPECT_EQ(bishop->color, Color::White);
}

TEST(PieceTest, knightCanBeMade) 
{
    // Arrange
    Coord coord = Coord(1,2);

    // Act
    Knight knight = Knight(Color::White, coord);

    // Assert
    EXPECT_EQ(knight.position.x,  1);
    EXPECT_EQ(knight.position.y,  2);
    EXPECT_EQ(knight.color, Color::White);
}

TEST(PieceTest, knightCanBeMadeUsingFactory) 
{
    // Arrange
    Coord coord = Coord(1,2);

    // Act
    auto knight = PieceFactory::CreateKnight(Color::White, coord);

    // Assert
    EXPECT_EQ(knight->position.x,  1);
    EXPECT_EQ(knight->position.y,  2);
    EXPECT_EQ(knight->color, Color::White);
}

TEST(PieceTest, rookCanBeMade) 
{
    // Arrange
    Coord coord = Coord(1,2);

    // Act
    Rook rook = Rook(Color::White, coord);

    // Assert
    EXPECT_EQ(rook.position.x,  1);
    EXPECT_EQ(rook.position.y,  2);
    EXPECT_EQ(rook.color, Color::White);
}

TEST(PieceTest, rookCanBeMadeUsingFactory) 
{
    // Arrange
    Coord coord = Coord(1,2);

    // Act
    auto rook = PieceFactory::CreateRook(Color::White, coord);

    // Assert
    EXPECT_EQ(rook->position.x,  1);
    EXPECT_EQ(rook->position.y,  2);
    EXPECT_EQ(rook->color, Color::White);
}

TEST(PieceTest, queenCanBeMade) 
{
    // Arrange
    Coord coord = Coord(1,2);

    // Act
    Queen queen = Queen(Color::White, coord);

    // Assert
    EXPECT_EQ(queen.position.x,  1);
    EXPECT_EQ(queen.position.y,  2);
    EXPECT_EQ(queen.color, Color::White);
}

TEST(PieceTest, queenCanBeMadeUsingFactory) 
{
    // Arrange
    Coord coord = Coord(1,2);

    // Act
    auto queen = PieceFactory::CreateQueen(Color::White, coord);

    // Assert
    EXPECT_EQ(queen->position.x,  1);
    EXPECT_EQ(queen->position.y,  2);
    EXPECT_EQ(queen->color, Color::White);
}

TEST(PieceTest, kingCanBeMade) 
{
    // Arrange
    Coord coord = Coord(1,2);

    // Act
    King king = King(Color::White, coord);

    // Assert
    EXPECT_EQ(king.position.x,  1);
    EXPECT_EQ(king.position.y,  2);
    EXPECT_EQ(king.color, Color::White);
}

TEST(PieceTest, kingCanBeMadeUsingFactory) 
{
    // Arrange
    Coord coord = Coord(1,2);

    // Act
    auto king = PieceFactory::CreateKing(Color::White, coord);

    // Assert
    EXPECT_EQ(king->position.x,  1);
    EXPECT_EQ(king->position.y,  2);
    EXPECT_EQ(king->color, Color::White);
}