#include "gtest/gtest.h"
#include "../src/PieceFactory.h"

TEST(PieceTest, pawnCanBeMade) 
{
    // Arrange
    Square coord = Square(1,2);

    // Act
    Pawn pawn = Pawn(Color::White, coord);

    // Assert
    EXPECT_EQ(pawn.position,  coord);
    EXPECT_EQ(pawn.color, Color::White);
}

TEST(PieceTest, pawnCanBeMadeUsingFactory) 
{
    // Arrange
    Square coord = Square(1,2);

    // Act
    auto pawn = PieceFactory::CreatePawn(Color::White, coord);

    // Assert
    EXPECT_EQ(pawn->position,  coord);
    EXPECT_EQ(pawn->color, Color::White);
}

TEST(PieceTest, pawnGivesCorrectPossibleMoves) 
{
    // Arrange
    Square coord = Square(2, 2);
    auto pawn = PieceFactory::CreatePawn(Color::White, coord);

    // Act
    std::vector<Square> possibleMoves = pawn->GetPossibleMoves();

    // Assert
    EXPECT_EQ(possibleMoves.size(),  4);
}

TEST(PieceTest, pawnGivesCorrectPossibleMovesInCorner) 
{
    // Arrange
    Square coord = Square(1, 2);
    auto pawn = PieceFactory::CreatePawn(Color::White, coord);

    // Act
    std::vector<Square> possibleMoves = pawn->GetPossibleMoves();

    // Assert
    EXPECT_EQ(possibleMoves.size(),  3);
}

TEST(PieceTest, pawnGivesCorrectPossibleMovesAfterMove) 
{
    // Arrange
    Square coord = Square(6, 2);
    auto piece = PieceFactory::CreatePawn(Color::White, coord);
    auto pawnPtr = std::dynamic_pointer_cast<Pawn>(piece);
    pawnPtr->hasMoved = true;

    // Act
    std::vector<Square> possibleMoves = pawnPtr->GetPossibleMoves();

    // Assert
    EXPECT_EQ(possibleMoves.size(),  3);
}

TEST(PieceTest, blackPawnGivesCorrectPossibleMoves) 
{
    // Arrange
    Square coord = Square(6, 1);
    auto pawn = PieceFactory::CreatePawn(Color::Black, coord);

    // Act
    std::vector<Square> possibleMoves = pawn->GetPossibleMoves();

    // Assert
    EXPECT_EQ(possibleMoves.size(),  0);
}

TEST(PieceTest, bishopCanBeMade) 
{
    // Arrange
    Square coord = Square(1,2);

    // Act
    Bishop bishop = Bishop(Color::White, coord);

    // Assert
    EXPECT_EQ(bishop.position,  coord);
    EXPECT_EQ(bishop.color, Color::White);
}

TEST(PieceTest, bishopCanBeMadeUsingFactory) 
{
    // Arrange
    Square coord = Square(1,2);

    // Act
    auto bishop = PieceFactory::CreateBishop(Color::White, coord);

    // Assert
    EXPECT_EQ(bishop->position,  coord);
    EXPECT_EQ(bishop->color, Color::White);
}

TEST(PieceTest, bishopGivesCorrectPossibleMoves) 
{
    // Arrange
    Square coord = Square(2,3);
    auto bishop = PieceFactory::CreateBishop(Color::White, coord);

    // Act
    std::vector<Square> possibleMoves = bishop->GetPossibleMoves();

    // Assert
    EXPECT_EQ(possibleMoves.size(),  9);
}

TEST(PieceTest, bishopGivesCorrectPossibleMovesWhenPlacedMiddle) 
{
    // Arrange
    Square coord = Square(4,5);
    auto bishop = PieceFactory::CreateBishop(Color::White, coord);

    // Act
    std::vector<Square> possibleMoves = bishop->GetPossibleMoves();

    // Assert
    EXPECT_EQ(possibleMoves.size(),  13);
}

TEST(PieceTest, bishopGivesCorrectPossibleMovesWhenPlacedCorner) 
{
    // Arrange
    Square coord = Square(1,1);
    auto bishop = PieceFactory::CreateBishop(Color::White, coord);

    // Act
    std::vector<Square> possibleMoves = bishop->GetPossibleMoves();

    // Assert
    EXPECT_EQ(possibleMoves.size(),  7);
}

TEST(PieceTest, knightCanBeMade) 
{
    // Arrange
    Square coord = Square(1,2);

    // Act
    Knight knight = Knight(Color::White, coord);

    // Assert
    EXPECT_EQ(knight.position,  coord);
    EXPECT_EQ(knight.color, Color::White);
}

TEST(PieceTest, knightCanBeMadeUsingFactory) 
{
    // Arrange
    Square coord = Square(1,2);

    // Act
    auto knight = PieceFactory::CreateKnight(Color::White, coord);

    // Assert
    EXPECT_EQ(knight->position,  coord);
    EXPECT_EQ(knight->color, Color::White);
}

TEST(PieceTest, knightGivesCorrectPossibleMoves) 
{
    // Arrange
    Square coord = Square(4,4);
    auto knight = PieceFactory::CreateKnight(Color::White, coord);

    // Act
    std::vector<Square> possibleMoves = knight->GetPossibleMoves();

    // Assert
    EXPECT_EQ(possibleMoves.size(),  8);
}

TEST(PieceTest, knightGivesCorrectPossibleMovesInCorner) 
{
    // Arrange
    Square coord = Square(1,1);
    auto knight = PieceFactory::CreateKnight(Color::White, coord);

    // Act
    std::vector<Square> possibleMoves = knight->GetPossibleMoves();

    // Assert
    EXPECT_EQ(possibleMoves.size(),  2);
}

TEST(PieceTest, rookCanBeMade) 
{
    // Arrange
    Square coord = Square(1,2);

    // Act
    Rook rook = Rook(Color::White, coord);

    // Assert
    EXPECT_EQ(rook.position,  coord);
    EXPECT_EQ(rook.color, Color::White);
}

TEST(PieceTest, rookCanBeMadeUsingFactory) 
{
    // Arrange
    Square coord = Square(1,2);

    // Act
    auto rook = PieceFactory::CreateRook(Color::White, coord);

    // Assert
    EXPECT_EQ(rook->position,  coord);
    EXPECT_EQ(rook->color, Color::White);
}

TEST(PieceTest, rookGivesCorrectPossibleMoves) 
{
    // Arrange
    Square coord = Square(1,2);
    auto rook = PieceFactory::CreateRook(Color::White, coord);

    // Act
    std::vector<Square> possibleMoves = rook->GetPossibleMoves();

    // Assert
    EXPECT_EQ(possibleMoves.size(),  14);
}

TEST(PieceTest, queenCanBeMade) 
{
    // Arrange
    Square coord = Square(1,2);

    // Act
    Queen queen = Queen(Color::White, coord);

    // Assert
    EXPECT_EQ(queen.position,  coord);
    EXPECT_EQ(queen.color, Color::White);
}

TEST(PieceTest, queenCanBeMadeUsingFactory) 
{
    // Arrange
    Square coord = Square(1,2);

    // Act
    auto queen = PieceFactory::CreateQueen(Color::White, coord);

    // Assert
    EXPECT_EQ(queen->position,  coord);
    EXPECT_EQ(queen->color, Color::White);
}

TEST(PieceTest, queenGivesCorrectPossibleMoves) 
{
    // Arrange
    Square coord = Square(4,5);
    auto queen = PieceFactory::CreateQueen(Color::White, coord);

    // Act
    std::vector<Square> possibleMoves = queen->GetPossibleMoves();

    // Assert
    EXPECT_EQ(possibleMoves.size(),  27);
}

TEST(PieceTest, queenGivesCorrectPossibleMovesInCorner) 
{
    // Arrange
    Square coord = Square(1,1);
    auto queen = PieceFactory::CreateQueen(Color::White, coord);

    // Act
    std::vector<Square> possibleMoves = queen->GetPossibleMoves();

    // Assert
    EXPECT_EQ(possibleMoves.size(),  21);
}

TEST(PieceTest, kingCanBeMade) 
{
    // Arrange
    Square coord = Square(1,2);

    // Act
    King king = King(Color::White, coord);

    // Assert
    EXPECT_EQ(king.position,  coord);
    EXPECT_EQ(king.color, Color::White);
}

TEST(PieceTest, kingCanBeMadeUsingFactory) 
{
    // Arrange
    Square coord = Square(1,2);

    // Act
    auto king = PieceFactory::CreateKing(Color::White, coord);

    // Assert
    EXPECT_EQ(king->position,  coord);
    EXPECT_EQ(king->color, Color::White);
}

TEST(PieceTest, kingGivesCorrectPossibleMoves) 
{
    // Arrange
    Square coord = Square(2,2);
    auto king = PieceFactory::CreateKing(Color::White, coord);

    // Act
    std::vector<Square> possibleMoves = king->GetPossibleMoves();

    // Assert
    EXPECT_EQ(possibleMoves.size(),  8);
}

TEST(PieceTest, kingGivesCorrectPossibleMovesInCorner) 
{
    // Arrange
    Square coord = Square(1,1);
    auto king = PieceFactory::CreateKing(Color::White, coord);

    // Act
    std::vector<Square> possibleMoves = king->GetPossibleMoves();

    // Assert
    EXPECT_EQ(possibleMoves.size(),  3);
}