#include "gtest/gtest.h"
#include "../src/Board.h"

TEST(BoardTest, pieceCanBeAdded)
{
    // Arrange
    Board board;

    // Act
    board.AddPiece(PieceFactory::CreatePawn(true, Coord(4, 4)));
    std::vector<std::shared_ptr<Piece>> pieces = board.GetPieces();

    // Assert
    EXPECT_EQ(pieces.size(), 33);
}

TEST(BoardTest, pieceCantBeAddedIfOtherPieceAlreadyThere)
{
    // Arrange
    Board board;

    // Act - no act

    // Assert
    EXPECT_THROW(board.AddPiece(PieceFactory::CreatePawn(true, Coord(1, 1)));, std::out_of_range);
}

TEST(BoardTest, pieceCanBeRemoved)
{
    // Arrange
    Board board;
    board.RemovePiece(Coord(1, 2));

    // Act
    std::vector<std::shared_ptr<Piece>> pieces = board.GetPieces();

    // Assert
    EXPECT_EQ(pieces.size(), 31);
}

TEST(BoardTest, pieceWontBeRemovedWrongCoord)
{
    // Arrange
    Board board;
    board.AddPiece(PieceFactory::CreatePawn(true, Coord(4, 4)));
    board.RemovePiece(Coord(4, 5));

    // Act
    std::vector<std::shared_ptr<Piece>> pieces = board.GetPieces();

    // Assert
    EXPECT_EQ(pieces.size(), 33);
}

TEST(BoardTest, boardIsInitializedCorrectly)
{
    // Arrange
    Board board;

    // Act
    std::vector<std::shared_ptr<Piece>> pieces = board.GetPieces();

    // Assert
    EXPECT_EQ(pieces.size(), 32);
}