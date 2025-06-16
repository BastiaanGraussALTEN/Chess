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

TEST(LegalityCheckerTest, IllegalToCaptureOwnPiece)
{
    // Arrange
    Board board;
    board.AddPiece(PieceFactory::CreatePawn(Color::White, Square(3,3)));
    LegalityChecker legalityChecker(board);
    Move knightMove = Move(Square(2,1), Square(3,3));

    // Act
    bool isLegal = legalityChecker.CheckMoveLegality(knightMove);

    // Assert
    ASSERT_FALSE(isLegal);
}

TEST(LegalityCheckerTest, LegalToCaptureOtherPiece)
{
    // Arrange
    Board board;
    board.AddPiece(PieceFactory::CreatePawn(Color::Black, Square(3,3)));
    LegalityChecker legalityChecker(board);
    Move knightMove = Move(Square(2,1), Square(3,3));

    // Act
    bool isLegal = legalityChecker.CheckMoveLegality(knightMove);

    // Assert
    ASSERT_TRUE(isLegal);
}

TEST(LegalityCheckerTest, PawnCanNotMoveDiagonally)
{
    // Arrange
    Board board;
    LegalityChecker legalityChecker(board);
    Move pawnMove = Move(Square(2,2), Square(3,3));

    // Act
    bool isLegal = legalityChecker.CheckMoveLegality(pawnMove);

    // Assert
    ASSERT_FALSE(isLegal);
}

TEST(LegalityCheckerTest, PawnCanCaptureDiagonally)
{
    // Arrange
    Board board;
    board.AddPiece(PieceFactory::CreatePawn(Color::Black, Square(3,3)));
    LegalityChecker legalityChecker(board);
    Move knightMove = Move(Square(2,2), Square(3,3));

    // Act
    bool isLegal = legalityChecker.CheckMoveLegality(knightMove);

    // Assert
    ASSERT_TRUE(isLegal);
}

TEST(LegalityCheckerTest, PawnCanNotCaptureStraight)
{
    // Arrange
    Board board;
    board.AddPiece(PieceFactory::CreatePawn(Color::Black, Square(2,3)));
    LegalityChecker legalityChecker(board);
    Move knightMove = Move(Square(2,2), Square(2,3));

    // Act
    bool isLegal = legalityChecker.CheckMoveLegality(knightMove);

    // Assert
    ASSERT_FALSE(isLegal);
}

TEST(LegalityCheckerTest, PawnCanNotMove2ForwardsIfItHasAlreadyMoved)
{
    // Arrange
    Board board;
    auto piece = board.GetPieceFromSquare(Square(2,2));
    auto pawn = std::dynamic_pointer_cast<Pawn>(piece);
    pawn->hasMoved = true;
    LegalityChecker legalityChecker(board);
    Move pawnMove = Move(Square(2,2), Square(2,4));

    // Act
    bool isLegal = legalityChecker.CheckMoveLegality(pawnMove);

    // Assert
    ASSERT_FALSE(isLegal);
}

TEST(LegalityCheckerTest, PawnCapturingPieceIsRecognized)
{
    // Arrange
    Board board;
    board.AddPiece(PieceFactory::CreatePawn(Color::Black, Square(3,3)));
    LegalityChecker legalityChecker(board);
    Move pawnMove = Move(Square(2,2), Square(3,3));

    // Act
    bool doesCapture = legalityChecker.DoesMoveCapturePiece(pawnMove);

    // Assert
    ASSERT_TRUE(doesCapture);
}

TEST(LegalityCheckerTest, PawnNotCapturingPieceIsRecognized)
{
    // Arrange
    Board board;
    board.AddPiece(PieceFactory::CreatePawn(Color::Black, Square(3,3)));
    LegalityChecker legalityChecker(board);
    Move pawnMove = Move(Square(2,2), Square(2,3));

    // Act
    bool doesCapture = legalityChecker.DoesMoveCapturePiece(pawnMove);

    // Assert
    ASSERT_FALSE(doesCapture);
}

TEST(LegalityCheckerTest, KnightCapturingPieceIsRecognized)
{
    // Arrange
    Board board;
    board.AddPiece(PieceFactory::CreatePawn(Color::Black, Square(3,3)));
    LegalityChecker legalityChecker(board);
    Move knightMove = Move(Square(2,1), Square(3,3));

    // Act
    bool doesCapture = legalityChecker.DoesMoveCapturePiece(knightMove);

    // Assert
    ASSERT_TRUE(doesCapture);
}

TEST(LegalityCheckerTest, KnightCantCaptureOwnPiece)
{
    // Arrange
    Board board;
    board.AddPiece(PieceFactory::CreatePawn(Color::White, Square(3,3)));
    LegalityChecker legalityChecker(board);
    Move knightMove = Move(Square(2,1), Square(3,3));

    // Act
    bool doesCapture = legalityChecker.DoesMoveCapturePiece(knightMove);

    // Assert
    ASSERT_FALSE(doesCapture);
}

TEST(LegalityCheckerTest, KnightNotCapturingPieceIsRecognized)
{
    // Arrange
    Board board;
    LegalityChecker legalityChecker(board);
    Move pawnMove = Move(Square(2,1), Square(2,3));

    // Act
    bool doesCapture = legalityChecker.DoesMoveCapturePiece(pawnMove);

    // Assert
    ASSERT_FALSE(doesCapture);
}

TEST(LegalityCheckerTest, WhiteCanCaptureEnPessantToTheRight)
{
    // Arrange
    Board board;
    board.AddPiece(PieceFactory::CreatePawn(Color::White, Square(3, 5)));
    board.MovePiece(Move(Square(4, 7), Square(4, 5)));
    LegalityChecker legalityChecker(board);
    
    // Act
    bool isLegal = legalityChecker.CheckMoveLegality(Move(Square(3, 5), Square(4, 6)));

    // Assert
    ASSERT_TRUE(isLegal);
}

TEST(LegalityCheckerTest, WhiteCanCaptureEnPessantToTheLeft)
{
    // Arrange
    Board board;
    board.AddPiece(PieceFactory::CreatePawn(Color::White, Square(3, 5)));
    board.MovePiece(Move(Square(2, 7), Square(2, 5)));
    LegalityChecker legalityChecker(board);
    
    // Act
    bool isLegal = legalityChecker.CheckMoveLegality(Move(Square(3, 5), Square(2, 6)));

    // Assert
    ASSERT_TRUE(isLegal);
}

TEST(LegalityCheckerTest, WhiteCannotCaptureEnPessantWithoutLastMove)
{
    // Arrange
    Board board;
    board.AddPiece(PieceFactory::CreatePawn(Color::White, Square(3, 5)));
    LegalityChecker legalityChecker(board);
    
    // Act
    bool isLegal = legalityChecker.CheckMoveLegality(Move(Square(3, 5), Square(4, 6)));

    // Assert
    ASSERT_FALSE(isLegal);
}

TEST(LegalityCheckerTest, WhiteCannotCaptureEnPessantLater)
{
    // Arrange
    Board board;
    board.AddPiece(PieceFactory::CreatePawn(Color::White, Square(3, 5)));
    board.MovePiece(Move(Square(2, 7), Square(2, 5)));
    board.MovePiece(Move(Square(2, 1), Square(3, 3)));
    LegalityChecker legalityChecker(board);
    
    // Act
    bool isLegal = legalityChecker.CheckMoveLegality(Move(Square(3, 5), Square(4, 6)));

    // Assert
    ASSERT_FALSE(isLegal);
}

TEST(LegalityCheckerTest, BlackCanCaptureEnPessantToTheRight)
{
    // Arrange
    Board board;
    board.AddPiece(PieceFactory::CreatePawn(Color::Black, Square(3, 4)));
    board.MovePiece(Move(Square(4, 2), Square(4, 4)));
    LegalityChecker legalityChecker(board);
    
    // Act
    bool isLegal = legalityChecker.CheckMoveLegality(Move(Square(3, 4), Square(4, 3)));

    // Assert
    ASSERT_TRUE(isLegal);
}

TEST(LegalityCheckerTest, BlackCanCaptureEnPessantToTheLeft)
{
    // Arrange
    Board board;
    board.AddPiece(PieceFactory::CreatePawn(Color::Black, Square(3, 4)));
    board.MovePiece(Move(Square(2, 2), Square(2, 4)));
    LegalityChecker legalityChecker(board);
    
    // Act
    bool isLegal = legalityChecker.CheckMoveLegality(Move(Square(3, 4), Square(2, 3)));

    // Assert
    ASSERT_TRUE(isLegal);
}