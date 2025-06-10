#include "gtest/gtest.h"
#include "../src/CastleChecker.h"

Board CreateEmptyBoard()
{
    Board board;
    for (int i = 1; i < 9; i++)
    {
        board.RemovePieceFromSquare(Square(i, 1));
        board.RemovePieceFromSquare(Square(i, 2));
        board.RemovePieceFromSquare(Square(i, 7));
        board.RemovePieceFromSquare(Square(i, 8));
    }
    return board;
}

TEST(CastleCheckerTest, WhiteCanCastleKingSide)
{
    // Arrange 
    Board board = CreateEmptyBoard();
    board.AddPiece(PieceFactory::CreateKing(Color::White, Square(5, 1)));
    board.AddPiece(PieceFactory::CreateRook(Color::White, Square(8, 1)));
    LegalityChecker legalityChecker = LegalityChecker(board);
    DangerChecker dangerChecker = DangerChecker(board, legalityChecker, Color::White);
    CastleChecker castleChecker = CastleChecker(board, legalityChecker, dangerChecker, Color::White);

    // Act
    bool canCastle = castleChecker.CanCastleKingSide();

    // Assert
    ASSERT_TRUE(canCastle);
}

TEST(CastleCheckerTest, BlackCanCastleKingSide)
{
    // Arrange 
    Board board = CreateEmptyBoard();
    board.AddPiece(PieceFactory::CreateKing(Color::Black, Square(5, 8)));
    board.AddPiece(PieceFactory::CreateRook(Color::Black, Square(8, 8)));
    LegalityChecker legalityChecker = LegalityChecker(board);
    DangerChecker dangerChecker = DangerChecker(board, legalityChecker, Color::Black);
    CastleChecker castleChecker = CastleChecker(board, legalityChecker, dangerChecker, Color::Black);

    // Act
    bool canCastle = castleChecker.CanCastleKingSide();

    // Assert
    ASSERT_TRUE(canCastle);
}

// TEST(DangerCheckerTest, WhenNoKingNoCastle){}

// TEST(DangerCheckerTest, WhenNoRookNoCastle){}

// TEST(DangerCheckerTest, WhenKingHasMovedNoCastle){}

// TEST(DangerCheckerTest, WhenRookHasMovedNoCastle){}

// TEST(DangerCheckerTest, WhenPieceInBetweenNoCastle){}

// TEST(DangerCheckerTest, WhenDestinationIsAttackedNoCastle){}

// TEST(DangerCheckerTest, WhenRookIsAttackedCanCastle){}

// TEST(DangerCheckerTest, WhenMovingOverAttackedSquareNoCastle){}
