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
    Move knightMove = Move(Coord(2, 1), Coord(3, 3));

    // Act
    bool isLegal = legalityChecker.CheckMoveLegality(knightMove);

    // Assert
    ASSERT_TRUE(isLegal);
}

TEST(LegalityCheckerTest, IllegalMovesArePossible)
{
    // Arrange
    Board board;
    LegalityChecker legalityChecker(board);
    // 1. Nc4
    Move knightMove = Move(Coord(2, 1), Coord(3, 4));

    // Act
    bool isLegal = legalityChecker.CheckMoveLegality(knightMove);

    // Assert
    ASSERT_FALSE(isLegal);
}