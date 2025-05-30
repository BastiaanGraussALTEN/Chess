#include "gtest/gtest.h"
#include "../src/Board.h"

TEST(BoardTest, pieceCanBeAdded)
{
    // Arrange
    Board board;

    // Act
    board.AddPiece(PieceFactory::CreatePawn(true, Coord(1, 2)));
    std::vector<std::shared_ptr<Piece>> pieces = board.GetPieces();

    // Assert
    EXPECT_EQ(pieces.size(), 1);
}

TEST(BoardTest, pieceCanBeRemoved)
{
    // Arrange
    Board board;
    board.AddPiece(PieceFactory::CreatePawn(true, Coord(1, 2)));
    board.RemovePiece(Coord(1, 2));

    // Act
    std::vector<std::shared_ptr<Piece>> pieces = board.GetPieces();

    // Assert
    EXPECT_EQ(pieces.size(), 0);
}

TEST(BoardTest, pieceWontBeRemovedWrongCoord)
{
    // Arrange
    Board board;
    board.AddPiece(PieceFactory::CreatePawn(true, Coord(1, 2)));
    board.RemovePiece(Coord(2, 2));

    // Act
    std::vector<std::shared_ptr<Piece>> pieces = board.GetPieces();

    // Assert
    EXPECT_EQ(pieces.size(), 1);
}