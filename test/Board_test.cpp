#include "gtest/gtest.h"
#include "../src/Board.h"

TEST(BoardTest, pieceCanBeAdded)
{
    // Arrange
    Board board;

    // Act
    board.AddPiece(PieceFactory::CreatePawn(Color::White, Square(4, 4)));
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
    EXPECT_THROW(board.AddPiece(PieceFactory::CreatePawn(Color::White, Square(1, 1)));, std::invalid_argument);
}

TEST(BoardTest, pieceCanBeRemoved)
{
    // Arrange
    Board board;
    board.RemovePieceFromSquare(Square(1, 2));

    // Act
    std::vector<std::shared_ptr<Piece>> pieces = board.GetPieces();

    // Assert
    EXPECT_EQ(pieces.size(), 31);
}

TEST(BoardTest, pieceWontBeRemovedWrongCoord)
{
    // Arrange
    Board board;
    board.AddPiece(PieceFactory::CreatePawn(Color::White, Square(4, 4)));
    board.RemovePieceFromSquare(Square(4, 5));

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

TEST(BoardTest, pieceHasMovedCanBeSet)
{
    // Arrange
    Board board;

    // Act
    auto rook = board.GetPieceFromSquare(Square(1, 1));
    rook->hasMoved = true;

    // Assert
    EXPECT_TRUE(board.GetPieceFromSquare(Square(1, 1))->hasMoved);
}

TEST(BoardTest, GetPieceFromCoordWhenNoPiecesOnBoard)
{
    // Arrange
    Board board;
    board.RemovePieceFromSquare(Square(1, 1));

    // Act
    std::shared_ptr<Piece> ptr = board.GetPieceFromSquare(Square(1, 1));

    // Assert
    EXPECT_TRUE(ptr == nullptr);
}

TEST(BoardTest, GetPieceFromCoordWrongCoord)
{
    // Arrange
    Board board;

    // Act
    std::shared_ptr<Piece> ptr = board.GetPieceFromSquare(Square(4, 4));

    // Assert
    EXPECT_TRUE(ptr == nullptr);
}

TEST(BoardTest, GetPieceFromCoord)
{
    // Arrange
    Board board;

    // Act
    std::shared_ptr<Piece> ptr = board.GetPieceFromSquare(Square(1, 1));

    // Assert
    EXPECT_EQ(ptr->color, Color::White);
    EXPECT_EQ(ptr->position.x, 1);
    EXPECT_EQ(ptr->position.y, 1);
}

TEST(BoardTest, PieceCanNotBeMovedIfNoPieceThere)
{
    // Arrange
    Board board;

    // Act
    Move move = Move(Square(4,4), Square(5,5));

    // Assert
    EXPECT_THROW(board.MovePiece(move), std::invalid_argument);
}

TEST(BoardTest, PieceCanBeMoved)
{
    // Arrange
    Board board;
    // 1.Nc3
    Move move = Move(Square(2,1), Square(3,3));
    
    // Act
    board.MovePiece(move);
    auto oldSquare = board.GetPieceFromSquare(Square(2,1));
    auto newSquare = board.GetPieceFromSquare(Square(3,3));
    
    // Assert
    EXPECT_EQ(oldSquare, nullptr);
    EXPECT_EQ(newSquare->pieceType, PieceType::KnightType);
}