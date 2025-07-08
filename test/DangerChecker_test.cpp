#include "gtest/gtest.h"
#include "../src/headerfiles/DangerChecker.h"

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

TEST(DangerCheckerTest, KingIsUnderAttackByPawn) 
{
    // Arrange
    Board board;
    board.RemovePieceFromSquare(Square(4, 2));
    board.AddPiece(PieceFactory::CreatePawn(Color::Black, Square(4, 2)));
    LegalityChecker legalityChecker(board);
    DangerChecker dangerChecker(board, legalityChecker, Color::White);

    // Act
    bool isUnderAttack = dangerChecker.IsKingUnderAttack();

    // Assert
    ASSERT_TRUE(isUnderAttack);
}

TEST(DangerCheckerTest, KingIsNotUnderNotUnderAttackInFrontOfPawn) 
{
    // Arrange
    Board board;
    board.RemovePieceFromSquare(Square(5, 2));
    board.AddPiece(PieceFactory::CreatePawn(Color::Black, Square(5, 2)));
    LegalityChecker legalityChecker(board);
    DangerChecker dangerChecker(board, legalityChecker, Color::White);

    // Act
    bool isUnderAttack = dangerChecker.IsKingUnderAttack();

    // Assert
    ASSERT_FALSE(isUnderAttack);
}

TEST(DangerCheckerTets, SquareIsNotUnderAttack)
{
    // Arrange 
    Board board;
    LegalityChecker legalityChecker(board);
    DangerChecker dangerChecker(board, legalityChecker, Color::White);
    
    // Act
    bool isUnderAttack = dangerChecker.IsSquareUnderAttack(Square(4, 1));

    // Assert
    ASSERT_FALSE(isUnderAttack);
}

TEST(DangerCheckerTets, SquareIsUnderAttackByKnight)
{
    // Arrange 
    Board board;
    LegalityChecker legalityChecker(board);
    DangerChecker dangerChecker(board, legalityChecker, Color::White);
    
    // Act
    bool isUnderAttack = dangerChecker.IsSquareUnderAttack(Square(3, 6));

    // Assert
    ASSERT_TRUE(isUnderAttack);
}

TEST(DangerCheckerTets, SquareIsUnderAttackByPawn)
{
    // Arrange 
    Board board;
    LegalityChecker legalityChecker(board);
    DangerChecker dangerChecker(board, legalityChecker, Color::White);
    
    // Act
    bool isUnderAttack = dangerChecker.IsSquareUnderAttack(Square(4, 6));

    // Assert
    ASSERT_TRUE(isUnderAttack);
}

TEST(DangerCheckerTets, SquareIsNotUnderAttackWhenInFrontOfPawn)
{
    // Arrange 
    Board board;
    LegalityChecker legalityChecker(board);
    DangerChecker dangerChecker(board, legalityChecker, Color::White);
    
    // Act
    bool isUnderAttack = dangerChecker.IsSquareUnderAttack(Square(4, 5));

    // Assert
    ASSERT_FALSE(isUnderAttack);
}