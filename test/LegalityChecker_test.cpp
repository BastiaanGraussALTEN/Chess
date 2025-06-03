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