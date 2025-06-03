#include "gtest/gtest.h"
#include "../src/LegalityChecker.h"

TEST(LegalityCheckerTest, LegalityCheckerCanBeMade)
{
    // Arrange
    Board board;

    // Act - no act

    // Assert
    EXPECT_NO_THROW(LegalityChecker legalityChecker(board));
}

TEST(LegalityCheckerTest, LegalMovesArePossible)
{
    // Arrange
    Board board;
    LegalityChecker legalityChecker(board);
    // 1. Nc3
    Move knightMove = Move(Square(2, 1), Square(3, 3));

    // Act
    bool isLegal = legalityChecker.CheckMoveLegality(knightMove);

    // Assert
    ASSERT_TRUE(isLegal);
}

TEST(LegalityCheckerTest, KnightCantMakeIllegalMove)
{
    // Arrange
    Board board;
    LegalityChecker legalityChecker(board);
    // 1. Nc4
    Move knightMove = Move(Square(2, 1), Square(3, 4));

    // Act
    bool isLegal = legalityChecker.CheckMoveLegality(knightMove);

    // Assert
    ASSERT_FALSE(isLegal);
}

TEST(LegalityCheckerTest, RookCantMoveThroughPawns)
{
    // Arrange
    Board board;
    LegalityChecker legalityChecker(board);
    // 1. Ra4
    Move rookMove = Move(Square(1, 1), Square(1, 4));

    // Act
    bool isLegal = legalityChecker.CheckMoveLegality(rookMove);

    // Assert
    ASSERT_FALSE(isLegal);
}

TEST(LegalityCheckerTest, BishopCantMoveThroughPawns)
{
    // Arrange
    Board board;
    LegalityChecker legalityChecker(board);
    // 1. Be3
    Move bishopMove = Move(Square(3, 1), Square(5, 3));

    // Act
    bool isLegal = legalityChecker.CheckMoveLegality(bishopMove);

    // Assert
    ASSERT_FALSE(isLegal);
}