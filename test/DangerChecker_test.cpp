#include "gtest/gtest.h"
#include "../src/DangerChecker.h"

TEST(DangerCheckerTest, ThereIsNoKingThrowsException) 
{
    // Arrange
    Board board;
    board.RemovePieceFromSquare(Square(5, 1));
    LegalityChecker legalityChecker(board);
    DangerChecker dangerChecker(board, legalityChecker, Color::White);
    
    // Act

    // Assert
    EXPECT_THROW(dangerChecker.IsKingUnderAttack(), std::domain_error);
}

TEST(DangerCheckerTest, KingIsNotUnderAttack) 
{
    // Arrange
    Board board;
    LegalityChecker legalityChecker(board);
    DangerChecker dangerChecker(board, legalityChecker, Color::White);

    // Act
    bool isUnderAttack = dangerChecker.IsKingUnderAttack();

    // Assert
    ASSERT_FALSE(isUnderAttack);
}

TEST(DangerCheckerTest, KingIsUnderAttack) 
{
    // Arrange
    Board board;
    // Nd3
    board.AddPiece(PieceFactory::CreateKnight(Color::Black, Square(4, 3)));
    LegalityChecker legalityChecker(board);
    DangerChecker dangerChecker(board, legalityChecker, Color::White);

    // Act
    bool isUnderAttack = dangerChecker.IsKingUnderAttack();

    // Assert
    ASSERT_TRUE(isUnderAttack);
}