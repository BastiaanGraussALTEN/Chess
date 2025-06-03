#include "gtest/gtest.h"
#include "../src/PieceFactory.h"

TEST(PieceTest, pawnCanBeMade) 
{
    // Arrange
    Coord coord = Coord(1,2);

    // Act
    Pawn pawn = Pawn(Color::White, coord);

    // Assert
    EXPECT_EQ(pawn.position,  coord);
    EXPECT_EQ(pawn.color, Color::White);
}

TEST(PieceTest, pawnCanBeMadeUsingFactory) 
{
    // Arrange
    Coord coord = Coord(1,2);

    // Act
    auto pawn = PieceFactory::CreatePawn(Color::White, coord);

    // Assert
    EXPECT_EQ(pawn->position,  coord);
    EXPECT_EQ(pawn->color, Color::White);
}

TEST(PieceTest, bishopCanBeMade) 
{
    // Arrange
    Coord coord = Coord(1,2);

    // Act
    Bishop bishop = Bishop(Color::White, coord);

    // Assert
    EXPECT_EQ(bishop.position,  coord);
    EXPECT_EQ(bishop.color, Color::White);
}

TEST(PieceTest, bishopCanBeMadeUsingFactory) 
{
    // Arrange
    Coord coord = Coord(1,2);

    // Act
    auto bishop = PieceFactory::CreateBishop(Color::White, coord);

    // Assert
    EXPECT_EQ(bishop->position,  coord);
    EXPECT_EQ(bishop->color, Color::White);
}

TEST(PieceTest, bishopGivesCorrectPossibleMoves) 
{
    // Arrange
    Coord coord = Coord(2,3);
    auto bishop = PieceFactory::CreateBishop(Color::White, coord);

    // Act
    std::vector<Coord> possibleMoves = bishop->GetPossibleMoves();

    // Assert
    EXPECT_EQ(possibleMoves.size(),  9);
}

TEST(PieceTest, bishopGivesCorrectPossibleMovesWhenPlacedMiddle) 
{
    // Arrange
    Coord coord = Coord(4,5);
    auto bishop = PieceFactory::CreateBishop(Color::White, coord);

    // Act
    std::vector<Coord> possibleMoves = bishop->GetPossibleMoves();

    // Assert
    EXPECT_EQ(possibleMoves.size(),  13);
}

TEST(PieceTest, bishopGivesCorrectPossibleMovesWhenPlacedCorner) 
{
    // Arrange
    Coord coord = Coord(1,1);
    auto bishop = PieceFactory::CreateBishop(Color::White, coord);

    // Act
    std::vector<Coord> possibleMoves = bishop->GetPossibleMoves();

    // Assert
    EXPECT_EQ(possibleMoves.size(),  7);
}

TEST(PieceTest, knightCanBeMade) 
{
    // Arrange
    Coord coord = Coord(1,2);

    // Act
    Knight knight = Knight(Color::White, coord);

    // Assert
    EXPECT_EQ(knight.position,  coord);
    EXPECT_EQ(knight.color, Color::White);
}

TEST(PieceTest, knightCanBeMadeUsingFactory) 
{
    // Arrange
    Coord coord = Coord(1,2);

    // Act
    auto knight = PieceFactory::CreateKnight(Color::White, coord);

    // Assert
    EXPECT_EQ(knight->position,  coord);
    EXPECT_EQ(knight->color, Color::White);
}

TEST(PieceTest, rookCanBeMade) 
{
    // Arrange
    Coord coord = Coord(1,2);

    // Act
    Rook rook = Rook(Color::White, coord);

    // Assert
    EXPECT_EQ(rook.position,  coord);
    EXPECT_EQ(rook.color, Color::White);
}

TEST(PieceTest, rookCanBeMadeUsingFactory) 
{
    // Arrange
    Coord coord = Coord(1,2);

    // Act
    auto rook = PieceFactory::CreateRook(Color::White, coord);

    // Assert
    EXPECT_EQ(rook->position,  coord);
    EXPECT_EQ(rook->color, Color::White);
}

TEST(PieceTest, rookGivesCorrectPossibleMoves) 
{
    // Arrange
    Coord coord = Coord(1,2);
    auto rook = PieceFactory::CreateRook(Color::White, coord);

    // Act
    std::vector<Coord> possibleMoves = rook->GetPossibleMoves();

    // Assert
    EXPECT_EQ(possibleMoves.size(),  14);
}

TEST(PieceTest, queenCanBeMade) 
{
    // Arrange
    Coord coord = Coord(1,2);

    // Act
    Queen queen = Queen(Color::White, coord);

    // Assert
    EXPECT_EQ(queen.position,  coord);
    EXPECT_EQ(queen.color, Color::White);
}

TEST(PieceTest, queenCanBeMadeUsingFactory) 
{
    // Arrange
    Coord coord = Coord(1,2);

    // Act
    auto queen = PieceFactory::CreateQueen(Color::White, coord);

    // Assert
    EXPECT_EQ(queen->position,  coord);
    EXPECT_EQ(queen->color, Color::White);
}

TEST(PieceTest, queenGivesCorrectPossibleMoves) 
{
    // Arrange
    Coord coord = Coord(4,5);
    auto queen = PieceFactory::CreateQueen(Color::White, coord);

    // Act
    std::vector<Coord> possibleMoves = queen->GetPossibleMoves();

    // Assert
    EXPECT_EQ(possibleMoves.size(),  27);
}

TEST(PieceTest, queenGivesCorrectPossibleMovesInCorner) 
{
    // Arrange
    Coord coord = Coord(1,1);
    auto queen = PieceFactory::CreateQueen(Color::White, coord);

    // Act
    std::vector<Coord> possibleMoves = queen->GetPossibleMoves();

    // Assert
    EXPECT_EQ(possibleMoves.size(),  21);
}

TEST(PieceTest, kingCanBeMade) 
{
    // Arrange
    Coord coord = Coord(1,2);

    // Act
    King king = King(Color::White, coord);

    // Assert
    EXPECT_EQ(king.position,  coord);
    EXPECT_EQ(king.color, Color::White);
}

TEST(PieceTest, kingCanBeMadeUsingFactory) 
{
    // Arrange
    Coord coord = Coord(1,2);

    // Act
    auto king = PieceFactory::CreateKing(Color::White, coord);

    // Assert
    EXPECT_EQ(king->position,  coord);
    EXPECT_EQ(king->color, Color::White);
}

TEST(PieceTest, kingGivesCorrectPossibleMoves) 
{
    // Arrange
    Coord coord = Coord(2,2);
    auto king = PieceFactory::CreateKing(Color::White, coord);

    // Act
    std::vector<Coord> possibleMoves = king->GetPossibleMoves();

    // Assert
    EXPECT_EQ(possibleMoves.size(),  8);
}

TEST(PieceTest, kingGivesCorrectPossibleMovesInCorner) 
{
    // Arrange
    Coord coord = Coord(1,1);
    auto king = PieceFactory::CreateKing(Color::White, coord);

    // Act
    std::vector<Coord> possibleMoves = king->GetPossibleMoves();

    // Assert
    EXPECT_EQ(possibleMoves.size(),  3);
}