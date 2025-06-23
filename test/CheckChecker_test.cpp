#include "gtest/gtest.h"
#include "../src/CheckChecker.h"
#include "../src/TestFunctions.h"

TEST(CheckCheckerTest, MovePreventsCheck)
{
    // Arrange
    Board board;
    board.AddPiece(PieceFactory::CreateKnight(Color::Black, Square(6, 3)));
    CheckChecker checkChecker = CheckChecker(board, Color::White);
    Move preventMove = Move(Square(5, 2), Square(6, 3));

    // Act
    bool doesPrevent = checkChecker.IsKingSafeAfterMove(preventMove);

    // Assert
    ASSERT_TRUE(doesPrevent);
}

TEST(CheckCheckerTest, MoveDoesNotPreventsCheck)
{
    // Arrange
    Board board;
    board.AddPiece(PieceFactory::CreateKnight(Color::Black, Square(6, 3)));
    CheckChecker checkChecker = CheckChecker(board, Color::White);
    Move preventMove = Move(Square(5, 2), Square(5, 3));

    // Act
    bool doesPrevent = checkChecker.IsKingSafeAfterMove(preventMove);

    // Assert
    ASSERT_FALSE(doesPrevent);
}

TEST(CheckCheckerTest, MovePutsKingInCheck)
{
    // Arrange
    Board board = TestFunctions::CreateEmptyBoard();
    board.AddPiece(PieceFactory::CreateKing(Color::White, Square(1, 1)));
    board.AddPiece(PieceFactory::CreateKnight(Color::White, Square(1, 2)));
    board.AddPiece(PieceFactory::CreateRook(Color::Black, Square(1, 3)));
    CheckChecker checkChecker = CheckChecker(board, Color::White);

    // Act
    bool isSafe = checkChecker.IsKingSafeAfterMove(Move(Square(1,2), Square(2,4)));

    // Assert
    ASSERT_FALSE(isSafe);
}

TEST(CheckCheckerTest, IsNotCheckMate)
{
    // Arrange
    Board board;
    board.AddPiece(PieceFactory::CreateKnight(Color::Black, Square(6, 3)));
    CheckChecker checkChecker = CheckChecker(board, Color::White);

    // Act
    bool isCheckMate = checkChecker.IsCheckMate();

    // Assert
    ASSERT_FALSE(isCheckMate);
}

TEST(CheckCheckerTest, IsCheckMate)
{
    // Arrange
    Board board;
    board.AddPiece(PieceFactory::CreateKnight(Color::Black, Square(6, 3)));
    board.AddPiece(PieceFactory::CreateKnight(Color::Black, Square(4, 3)));
    CheckChecker checkChecker = CheckChecker(board, Color::White);

    // Act
    bool isCheckMate = checkChecker.IsCheckMate();

    // Assert
    ASSERT_TRUE(isCheckMate);
}