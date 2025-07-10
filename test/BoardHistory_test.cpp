#include "gtest/gtest.h"
#include "../header/BoardHistory.h"

TEST(BoardHistoryTest, NoThreeFoldRepetition)
{
    // Arrange
    BoardHistory boardHistory;

    // Act
    bool isThreeFoldRepetition = boardHistory.IsThreeFoldRepetition();

    // Assert
    ASSERT_FALSE(isThreeFoldRepetition);
}

TEST(BoardHistoryTest, OneFoldRepetition)
{
    // Arrange
    BoardHistory boardHistory;
    Board board;
    board.MovePiece(Move(Square(2,1), Square(3,3)));
    boardHistory.AddBoard(board);
    board.MovePiece(Move(Square(3,3), Square(2,1)));
    boardHistory.AddBoard(board);

    // Act
    bool isThreeFoldRepetition = boardHistory.IsThreeFoldRepetition();

    // Assert
    ASSERT_FALSE(isThreeFoldRepetition);
}

TEST(BoardHistoryTest, TwoFoldRepetition)
{
    // Arrange
    BoardHistory boardHistory;
    Board board;
    board.MovePiece(Move(Square(2,1), Square(3,3)));
    boardHistory.AddBoard(board);
    board.MovePiece(Move(Square(3,3), Square(2,1)));
    boardHistory.AddBoard(board);
    board.MovePiece(Move(Square(2,1), Square(3,3)));
    boardHistory.AddBoard(board);
    board.MovePiece(Move(Square(3,3), Square(2,1)));
    boardHistory.AddBoard(board);

    // Act
    bool isThreeFoldRepetition = boardHistory.IsThreeFoldRepetition();

    // Assert
    ASSERT_FALSE(isThreeFoldRepetition);
}

TEST(BoardHistoryTest, ThreeFoldRepetition)
{
    // Arrange
    BoardHistory boardHistory;
    Board board;
    board.MovePiece(Move(Square(2,1), Square(3,3)));
    boardHistory.AddBoard(board);
    board.MovePiece(Move(Square(3,3), Square(2,1)));
    boardHistory.AddBoard(board);
    board.MovePiece(Move(Square(2,1), Square(3,3)));
    boardHistory.AddBoard(board);
    board.MovePiece(Move(Square(3,3), Square(2,1)));
    boardHistory.AddBoard(board);
    board.MovePiece(Move(Square(2,1), Square(3,3)));
    boardHistory.AddBoard(board);
    board.MovePiece(Move(Square(3,3), Square(2,1)));
    boardHistory.AddBoard(board);

    // Act
    bool isThreeFoldRepetition = boardHistory.IsThreeFoldRepetition();

    // Assert
    ASSERT_TRUE(isThreeFoldRepetition);
}