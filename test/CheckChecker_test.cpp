#include "gtest/gtest.h"
#include "../src/CheckChecker.h"

TEST(CheckCheckerTest, MovePreventsCheck)
{
    // Arrange
    Board board;
    board.AddPiece(PieceFactory::CreateKnight(Color::Black, Square(6, 3)));
    CheckChecker checkChecker = CheckChecker(board, Color::White);
    Move preventMove = Move(Square(5, 2), Square(6, 3));

    // Act
    bool doesPrevent = checkChecker.DoesMovePreventCheck(preventMove);

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
    bool doesPrevent = checkChecker.DoesMovePreventCheck(preventMove);

    // Assert
    ASSERT_FALSE(doesPrevent);
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