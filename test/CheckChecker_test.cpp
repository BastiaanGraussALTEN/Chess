#include "gtest/gtest.h"
#include "../header/CheckChecker.h"
#include "../header/TestFunctions.h"

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

TEST(CheckCheckerTest, KingMovePutsKingInCheck)
{
    // Arrange
    Board board = TestFunctions::CreateEmptyBoard();
    board.AddPiece(PieceFactory::CreateKing(Color::White, Square(1, 1)));
    board.AddPiece(PieceFactory::CreateRook(Color::Black, Square(2, 2)));
    CheckChecker checkChecker = CheckChecker(board, Color::White);

    // Act
    bool isSafe = checkChecker.IsKingSafeAfterMove(Move(Square(1,1), Square(1,2)));

    // Assert
    ASSERT_FALSE(isSafe);
}

TEST(CheckCheckerTest, KingMovePutsKingInCheckByPawn)
{
    // Arrange
    Board board = TestFunctions::CreateEmptyBoard();
    board.AddPiece(PieceFactory::CreateKing(Color::White, Square(1, 1)));
    board.AddPiece(PieceFactory::CreatePawn(Color::Black, Square(2, 3)));
    CheckChecker checkChecker = CheckChecker(board, Color::White);

    // Act
    bool isSafe = checkChecker.IsKingSafeAfterMove(Move(Square(1,1), Square(1,2)));

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
    bool everyMoveChecksSelf = checkChecker.EveryMoveChecksSelf();

    // Assert
    ASSERT_FALSE(everyMoveChecksSelf);
}

TEST(CheckCheckerTest, IsCheckMate)
{
    // Arrange
    Board board;
    board.AddPiece(PieceFactory::CreateKnight(Color::Black, Square(6, 3)));
    board.AddPiece(PieceFactory::CreateKnight(Color::Black, Square(4, 3)));
    CheckChecker checkChecker = CheckChecker(board, Color::White);

    // Act
    bool everyMoveChecksSelf = checkChecker.EveryMoveChecksSelf();

    // Assert
    ASSERT_TRUE(everyMoveChecksSelf);
}

TEST(CheckCheckerTest, IsNotStaleMate)
{
    // Arrange
    Board board = TestFunctions::CreateEmptyBoard();
    board.AddPiece(PieceFactory::CreateKing(Color::White, Square(1, 1)));
    board.AddPiece(PieceFactory::CreateQueen(Color::Black, Square(3, 3)));
    CheckChecker checkChecker = CheckChecker(board, Color::White);

    // Act
    bool everyMoveChecksSelf = checkChecker.EveryMoveChecksSelf();

    // Assert
    ASSERT_FALSE(everyMoveChecksSelf);
}

TEST(CheckCheckerTest, IsStaleMate)
{
    // Arrange
    Board board = TestFunctions::CreateEmptyBoard();
    board.AddPiece(PieceFactory::CreateKing(Color::White, Square(1, 1)));
    board.AddPiece(PieceFactory::CreateQueen(Color::Black, Square(3, 2)));
    CheckChecker checkChecker = CheckChecker(board, Color::White);

    // Act
    bool everyMoveChecksSelf = checkChecker.EveryMoveChecksSelf();

    // Assert
    ASSERT_TRUE(everyMoveChecksSelf);
}

TEST(CheckCheckerTest, SufficientMaterial)
{
    // Arrange
    Board board;
    CheckChecker checkChecker = CheckChecker(board, Color::White);

    // Act
    bool sufficientMaterial = checkChecker.SufficientMaterialForCheckmate();

    // Assert
    ASSERT_TRUE(sufficientMaterial);
}

TEST(CheckCheckerTest, InSufficientMaterialTwoKings)
{
    // Arrange
    Board board = TestFunctions::CreateEmptyBoard();
    board.AddPiece(PieceFactory::CreateKing(Color::White, Square(1,1)));
    board.AddPiece(PieceFactory::CreateKing(Color::Black, Square(8,8)));
    CheckChecker checkChecker = CheckChecker(board, Color::White);

    // Act
    bool sufficientMaterial = checkChecker.SufficientMaterialForCheckmate();

    // Assert
    ASSERT_FALSE(sufficientMaterial);
}

TEST(CheckCheckerTest, InSufficientMaterialOneBishop)
{
    // Arrange
    Board board = TestFunctions::CreateEmptyBoard();
    board.AddPiece(PieceFactory::CreateKing(Color::White, Square(1,1)));
    board.AddPiece(PieceFactory::CreateKing(Color::Black, Square(8,8)));
    board.AddPiece(PieceFactory::CreateBishop(Color::White, Square(2,1)));
    CheckChecker checkChecker = CheckChecker(board, Color::White);

    // Act
    bool sufficientMaterial = checkChecker.SufficientMaterialForCheckmate();

    // Assert
    ASSERT_FALSE(sufficientMaterial);
}

TEST(CheckCheckerTest, SufficientMaterialTwoBishop)
{
    // Arrange
    Board board = TestFunctions::CreateEmptyBoard();
    board.AddPiece(PieceFactory::CreateKing(Color::White, Square(1,1)));
    board.AddPiece(PieceFactory::CreateKing(Color::Black, Square(8,8)));
    board.AddPiece(PieceFactory::CreateBishop(Color::White, Square(2,1)));
    board.AddPiece(PieceFactory::CreateBishop(Color::White, Square(2,2)));
    CheckChecker checkChecker = CheckChecker(board, Color::White);

    // Act
    bool sufficientMaterial = checkChecker.SufficientMaterialForCheckmate();

    // Assert
    ASSERT_TRUE(sufficientMaterial);
}

TEST(CheckCheckerTest, SufficientMaterialTwoBishopDifferentColor)
{
    // Arrange
    Board board = TestFunctions::CreateEmptyBoard();
    board.AddPiece(PieceFactory::CreateKing(Color::White, Square(1,1)));
    board.AddPiece(PieceFactory::CreateKing(Color::Black, Square(8,8)));
    board.AddPiece(PieceFactory::CreateBishop(Color::White, Square(2,1)));
    board.AddPiece(PieceFactory::CreateBishop(Color::Black, Square(2,2)));
    CheckChecker checkChecker = CheckChecker(board, Color::White);

    // Act
    bool sufficientMaterial = checkChecker.SufficientMaterialForCheckmate();

    // Assert
    ASSERT_TRUE(sufficientMaterial);
}

TEST(CheckCheckerTest, InSufficientMaterialTwoBishopsSameColor)
{
    // Arrange
    Board board = TestFunctions::CreateEmptyBoard();
    board.AddPiece(PieceFactory::CreateKing(Color::White, Square(1,1)));
    board.AddPiece(PieceFactory::CreateKing(Color::Black, Square(8,8)));
    board.AddPiece(PieceFactory::CreateBishop(Color::White, Square(2,4)));
    board.AddPiece(PieceFactory::CreateBishop(Color::Black, Square(4,6)));
    CheckChecker checkChecker = CheckChecker(board, Color::White);
    
    // Act
    bool sufficientMaterial = checkChecker.SufficientMaterialForCheckmate();
    
    // Assert
    ASSERT_FALSE(sufficientMaterial);
}

TEST(CheckCheckerTest, InSufficientMaterialOneKnight)
{
    // Arrange
    Board board = TestFunctions::CreateEmptyBoard();
    board.AddPiece(PieceFactory::CreateKing(Color::White, Square(1,1)));
    board.AddPiece(PieceFactory::CreateKing(Color::Black, Square(8,8)));
    board.AddPiece(PieceFactory::CreateKnight(Color::White, Square(2,1)));
    CheckChecker checkChecker = CheckChecker(board, Color::White);

    // Act
    bool sufficientMaterial = checkChecker.SufficientMaterialForCheckmate();

    // Assert
    ASSERT_FALSE(sufficientMaterial);
}

TEST(CheckCheckerTest, SufficientMaterialTwoKnights)
{
    // Arrange
    Board board = TestFunctions::CreateEmptyBoard();
    board.AddPiece(PieceFactory::CreateKing(Color::White, Square(1,1)));
    board.AddPiece(PieceFactory::CreateKing(Color::Black, Square(8,8)));
    board.AddPiece(PieceFactory::CreateKnight(Color::White, Square(2,1)));
    board.AddPiece(PieceFactory::CreateKnight(Color::Black, Square(2,2)));
    CheckChecker checkChecker = CheckChecker(board, Color::White);

    // Act
    bool sufficientMaterial = checkChecker.SufficientMaterialForCheckmate();

    // Assert
    ASSERT_TRUE(sufficientMaterial);
}