#include "gtest/gtest.h"
#include "../header/BoardHistory.h"

TEST(BoardHistoryTest, NoThreeFoldRepetition)
{
    // Arrange
    Board board;
    BoardHistory boardHistory;
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

TEST(BoardHistoryTest, ThreeFoldRepetitionFromStart)
{
    // Arrange
    BoardHistory boardHistory;
    Board board;
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

TEST(BoardHistoryTest, ThreeFoldRepetition)
{
    // Arrange
    BoardHistory boardHistory;
    Board board;
    boardHistory.AddBoard(board);
    board.MovePiece(Move(Square(5,2), Square(5,3)));
    boardHistory.AddBoard(board);
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