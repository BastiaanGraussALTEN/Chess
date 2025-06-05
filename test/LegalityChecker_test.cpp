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

TEST(LegalityCheckerTest, MoveIsIllegalIfNoPieceOnSquare)
{
    // Arrange
    Board board;
    LegalityChecker legalityChecker(board);
    // 1. Nc3
    Move knightMove = Move(Square(4, 4), Square(3, 3));

    // Act
    bool isLegal = legalityChecker.CheckMoveLegality(knightMove);

    // Assert
    ASSERT_FALSE(isLegal);
}

TEST(LegalityCheckerTest, LegalKnightMoveIsPossible)
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

TEST(LegalityCheckerTest, LegalPawnMoveIsPossible)
{
    // Arrange
    Board board;
    LegalityChecker legalityChecker(board);
    // 1. b3
    Move pawnMove = Move(Square(2, 2), Square(2, 3));

    // Act
    bool isLegal = legalityChecker.CheckMoveLegality(pawnMove);

    // Assert
    ASSERT_TRUE(isLegal);
}

TEST(LegalityCheckerTest, IllegalPawnMoveIsNotPossible)
{
    // Arrange
    Board board;
    LegalityChecker legalityChecker(board);
    // 1. b3
    Move pawnMove = Move(Square(2, 2), Square(2, 5));

    // Act
    bool isLegal = legalityChecker.CheckMoveLegality(pawnMove);

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

TEST(LegalityCheckerTest, RookCantMoveThroughOwnPieceFarAway)
{
    // Arrange
    Board board;
    board.AddPiece(PieceFactory::CreatePawn(Color::White, Square(4, 3)));
    board.AddPiece(PieceFactory::CreateRook(Color::White, Square(8, 3)));
    LegalityChecker legalityChecker(board);
    // 1. Ra3
    Move rookMove = Move(Square(8, 3), Square(1, 3));

    // Act
    bool isLegal = legalityChecker.CheckMoveLegality(rookMove);

    // Assert
    ASSERT_FALSE(isLegal);
}

TEST(LegalityCheckerTest, RookCantMoveThroughOtherPieceFarAway)
{
    // Arrange
    Board board;
    board.AddPiece(PieceFactory::CreatePawn(Color::Black, Square(4, 3)));
    board.AddPiece(PieceFactory::CreateRook(Color::White, Square(8, 3)));
    LegalityChecker legalityChecker(board);
    // 1. Ra3
    Move rookMove = Move(Square(8, 3), Square(1, 3));

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

TEST(LegalityCheckerTest, QueenCantMoveThroughPawns)
{
    // Arrange
    Board board;
    LegalityChecker legalityChecker(board);
    // 1. Be3
    Move queenMove = Move(Square(4, 1), Square(4, 3));

    // Act
    bool isLegal = legalityChecker.CheckMoveLegality(queenMove);

    // Assert
    ASSERT_FALSE(isLegal);
}

TEST(LegalityCheckerTest, PawnCantMoveThroughPawns)
{
    // Arrange
    Board board;
    board.AddPiece(PieceFactory::CreatePawn(Color::White, Square(4, 3)));
    LegalityChecker legalityChecker(board);
    // 1. d4
    Move pawnMove = Move(Square(4, 2), Square(4, 4));

    // Act
    bool isLegal = legalityChecker.CheckMoveLegality(pawnMove);

    // Assert
    ASSERT_FALSE(isLegal);
}