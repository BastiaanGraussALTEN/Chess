#include "gtest/gtest.h"
#include "../header/Board.h"

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

TEST(BoardTest, movedPieceCanBeAdded)
{
    // Arrange
    Board board;

    // Act
    auto rook = PieceFactory::CreateRook(Color::White, Square(4, 4));
    board.AddPiece(rook);
    board.GetPieceFromSquare(Square(4, 4))->hasMoved = true;


    // Assert
    EXPECT_TRUE(board.GetPieceFromSquare(Square(4, 4))->hasMoved);
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
    EXPECT_EQ(newSquare->pieceType, PieceType::Knight);
}

TEST(BoardTest, PawnRemembersThatItHasMoved)
{
    // Arrange
    Board board;
    board.MovePiece(Move(Square(5, 2), Square(5, 4)));

    // Act
    auto pawn = board.GetPieceFromSquare(Square(5, 4));

    // Assert
    ASSERT_TRUE(pawn->hasMoved);
}

TEST(BoardTest, LastMoveBeforeFirstMove)
{
    // Arrange
    Board board;
    Move expectedMove = Move(Square(1, 1), Square(1, 1));

    // Act
    Move lastMove = board.GetLastMove();

    // Assert
    EXPECT_EQ(lastMove, expectedMove);
}

TEST(BoardTest, LastMoveAfterFirstMove)
{
    // Arrange
    Board board;
    Move expectedMove = Move(Square(2, 1), Square(3, 3));
    board.MovePiece(expectedMove);

    // Act
    Move lastMove = board.GetLastMove();

    // Assert
    EXPECT_EQ(lastMove, expectedMove);
}

TEST(BoardTest, LastMoveAfterTwoMoves)
{
    // Arrange
    Board board;
    Move expectedMove = Move(Square(2, 1), Square(3, 3));
    board.MovePiece(Move(Square(7, 1), Square(6, 3)));
    board.MovePiece(expectedMove);

    // Act
    Move lastMove = board.GetLastMove();

    // Assert
    EXPECT_EQ(lastMove, expectedMove);
}

TEST(BoardTest, ThereIsAWhitePawnHere)
{
    // Arrange
    Board board;

    // Act
    bool isThere = board.IsThereAPieceOfThisColorHere(Color::White, Square(2, 2));
    bool isNotThere = board.IsThereAPieceOfThisColorHere(Color::White, Square(2, 3));

    // Assert
    ASSERT_TRUE(isThere);
    ASSERT_FALSE(isNotThere);
}

TEST(BoardTest, ThereIsABlackPawnHere)
{
    // Arrange
    Board board;

    // Act
    bool isThere = board.IsThereAPieceOfThisColorHere(Color::Black, Square(2, 7));
    bool isNotThere = board.IsThereAPieceOfThisColorHere(Color::Black, Square(2, 2));

    // Assert
    ASSERT_TRUE(isThere);
    ASSERT_FALSE(isNotThere);
}

TEST(BoardTest, WhiteCastleKingside)
{
    // Arrange
    Board board;
    board.RemovePieceFromSquare(Square(6,1));
    board.RemovePieceFromSquare(Square(7,1));
    
    // Act
    board.CastleKingside(Color::White);
    
    // Assert
    ASSERT_EQ(board.GetPieceFromSquare(Square(7,1))->pieceType, PieceType::King);
    ASSERT_EQ(board.GetPieceFromSquare(Square(6,1))->pieceType, PieceType::Rook);
}

TEST(BoardTest, WhiteCastleQueenide)
{
    // Arrange
    Board board;
    board.RemovePieceFromSquare(Square(2,1));
    board.RemovePieceFromSquare(Square(3,1));
    board.RemovePieceFromSquare(Square(4,1));
    
    // Act
    board.CastleQueenside(Color::White);
    
    // Assert
    ASSERT_EQ(board.GetPieceFromSquare(Square(3,1))->pieceType, PieceType::King);
    ASSERT_EQ(board.GetPieceFromSquare(Square(4,1))->pieceType, PieceType::Rook);
}

TEST(BoardTest, BlackCastleKingside)
{
    // Arrange
    Board board;
    board.RemovePieceFromSquare(Square(6,8));
    board.RemovePieceFromSquare(Square(7,8));
    
    // Act
    board.CastleKingside(Color::Black);
    
    // Assert
    ASSERT_EQ(board.GetPieceFromSquare(Square(7,8))->pieceType, PieceType::King);
    ASSERT_EQ(board.GetPieceFromSquare(Square(6,8))->pieceType, PieceType::Rook);
}

TEST(BoardTest, BlackCastleQueenide)
{
    // Arrange
    Board board;
    board.RemovePieceFromSquare(Square(2,8));
    board.RemovePieceFromSquare(Square(3,8));
    board.RemovePieceFromSquare(Square(4,8));
    
    // Act
    board.CastleQueenside(Color::Black);
    
    // Assert
    ASSERT_EQ(board.GetPieceFromSquare(Square(3,8))->pieceType, PieceType::King);
    ASSERT_EQ(board.GetPieceFromSquare(Square(4,8))->pieceType, PieceType::Rook);
}

TEST(BoardTest, HasEnpessant)
{
    // Arrange
    Board board;

    // Act
    board.MovePiece(Move(Square(2, 2), Square(2, 4)));

    // Assert
    ASSERT_EQ(board.EnPessantSquare, Square(2,3)); 
}

TEST(BoardTest, WhiteAndBlackHaveCastleRights)
{
    // Arrange
    Board board;

    // Act

    // Assert
    ASSERT_TRUE(board.WhiteHasKingsideCastleRights);
    ASSERT_TRUE(board.WhiteHasQueensideCastleRights);
    ASSERT_TRUE(board.BlackHasKingsideCastleRights);
    ASSERT_TRUE(board.BlackHasQueensideCastleRights);
}