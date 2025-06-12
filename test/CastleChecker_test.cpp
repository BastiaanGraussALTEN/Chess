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

TEST(CastleCheckerTest, WhenWhiteKingWrongSquareNoCastle)
{
    // Arrange 
    Board board = CreateEmptyBoard();
    board.AddPiece(PieceFactory::CreateKing(Color::White, Square(6, 1)));
    board.AddPiece(PieceFactory::CreateRook(Color::White, Square(8, 1)));
    LegalityChecker legalityChecker = LegalityChecker(board);
    DangerChecker dangerChecker = DangerChecker(board, legalityChecker, Color::White);
    CastleChecker castleChecker = CastleChecker(board, legalityChecker, dangerChecker, Color::White);

    // Act
    bool canCastle = castleChecker.CanCastleKingSide();

    // Assert
    ASSERT_FALSE(canCastle);
}

TEST(CastleCheckerTest, WhenBlackKingWrongSquareNoCastle)
{
    // Arrange 
    Board board = CreateEmptyBoard();
    board.AddPiece(PieceFactory::CreateKing(Color::Black, Square(6, 8)));
    board.AddPiece(PieceFactory::CreateRook(Color::Black, Square(8, 8)));
    LegalityChecker legalityChecker = LegalityChecker(board);
    DangerChecker dangerChecker = DangerChecker(board, legalityChecker, Color::Black);
    CastleChecker castleChecker = CastleChecker(board, legalityChecker, dangerChecker, Color::Black);

    // Act
    bool canCastle = castleChecker.CanCastleKingSide();

    // Assert
    ASSERT_FALSE(canCastle);
}

TEST(CastleCheckerTest, WhenNoWhiteRookNoCastle)
{
    // Arrange 
    Board board = CreateEmptyBoard();
    board.AddPiece(PieceFactory::CreateKing(Color::White, Square(5, 1)));
    LegalityChecker legalityChecker = LegalityChecker(board);
    DangerChecker dangerChecker = DangerChecker(board, legalityChecker, Color::White);
    CastleChecker castleChecker = CastleChecker(board, legalityChecker, dangerChecker, Color::White);

    // Act
    bool canCastle = castleChecker.CanCastleKingSide();

    // Assert
    ASSERT_FALSE(canCastle);
}

TEST(CastleCheckerTest, WhenNoBlackRookNoCastle)
{
    // Arrange 
    Board board = CreateEmptyBoard();
    board.AddPiece(PieceFactory::CreateKing(Color::Black, Square(5, 8)));
    LegalityChecker legalityChecker = LegalityChecker(board);
    DangerChecker dangerChecker = DangerChecker(board, legalityChecker, Color::Black);
    CastleChecker castleChecker = CastleChecker(board, legalityChecker, dangerChecker, Color::Black);

    // Act
    bool canCastle = castleChecker.CanCastleKingSide();

    // Assert
    ASSERT_FALSE(canCastle);
}

TEST(CastleCheckerTest, WhenWhiteRookIsOnWrongSquareNoCastle)
{
    // Arrange 
    Board board = CreateEmptyBoard();
    board.AddPiece(PieceFactory::CreateKing(Color::White, Square(5, 1)));
    board.AddPiece(PieceFactory::CreateRook(Color::White, Square(7, 1)));
    LegalityChecker legalityChecker = LegalityChecker(board);
    DangerChecker dangerChecker = DangerChecker(board, legalityChecker, Color::White);
    CastleChecker castleChecker = CastleChecker(board, legalityChecker, dangerChecker, Color::White);

    // Act
    bool canCastle = castleChecker.CanCastleKingSide();

    // Assert
    ASSERT_FALSE(canCastle);
}

TEST(CastleCheckerTest, WhenBlackRookIsOnWrongSquareNoCastle)
{
    // Arrange 
    Board board = CreateEmptyBoard();
    board.AddPiece(PieceFactory::CreateKing(Color::Black, Square(5, 8)));
    board.AddPiece(PieceFactory::CreateRook(Color::Black, Square(7, 8)));
    LegalityChecker legalityChecker = LegalityChecker(board);
    DangerChecker dangerChecker = DangerChecker(board, legalityChecker, Color::Black);
    CastleChecker castleChecker = CastleChecker(board, legalityChecker, dangerChecker, Color::Black);

    // Act
    bool canCastle = castleChecker.CanCastleKingSide();

    // Assert
    ASSERT_FALSE(canCastle);
}

TEST(CastleCheckerTest, WhenWhiteKingHasMovedNoCastle)
{
    // Arrange 
    Board board = CreateEmptyBoard();
    auto king = PieceFactory::CreateKing(Color::White, Square(5, 1));
    king->hasMoved = true;
    board.AddPiece(king);
    board.AddPiece(PieceFactory::CreateRook(Color::White, Square(8, 1)));
    LegalityChecker legalityChecker = LegalityChecker(board);
    DangerChecker dangerChecker = DangerChecker(board, legalityChecker, Color::White);
    CastleChecker castleChecker = CastleChecker(board, legalityChecker, dangerChecker, Color::White);

    // Act
    bool canCastle = castleChecker.CanCastleKingSide();

    // Assert
    ASSERT_FALSE(canCastle);
}

TEST(CastleCheckerTest, WhenBlackKingHasMovedNoCastle)
{
    // Arrange 
    Board board = CreateEmptyBoard();
    auto king = PieceFactory::CreateKing(Color::Black, Square(5, 8));
    king->hasMoved = true;
    board.AddPiece(king);
    board.AddPiece(PieceFactory::CreateRook(Color::Black, Square(8, 8)));
    LegalityChecker legalityChecker = LegalityChecker(board);
    DangerChecker dangerChecker = DangerChecker(board, legalityChecker, Color::Black);
    CastleChecker castleChecker = CastleChecker(board, legalityChecker, dangerChecker, Color::Black);

    // Act
    bool canCastle = castleChecker.CanCastleKingSide();

    // Assert
    ASSERT_FALSE(canCastle);
}

TEST(CastleCheckerTest, WhenWhiteRookHasMovedNoCastle)
{
    // Arrange 
    Board board = CreateEmptyBoard();
    auto rook = PieceFactory::CreateRook(Color::White, Square(8, 1));
    rook->hasMoved = true;
    board.AddPiece(rook);
    board.AddPiece(PieceFactory::CreateKing(Color::White, Square(5, 1)));
    LegalityChecker legalityChecker = LegalityChecker(board);
    DangerChecker dangerChecker = DangerChecker(board, legalityChecker, Color::White);
    CastleChecker castleChecker = CastleChecker(board, legalityChecker, dangerChecker, Color::White);

    // Act
    bool canCastle = castleChecker.CanCastleKingSide();

    // Assert
    ASSERT_FALSE(canCastle);
}

TEST(CastleCheckerTest, WhenBlackRookHasMovedNoCastle)
{
    // Arrange 
    Board board = CreateEmptyBoard();
    auto rook = PieceFactory::CreateRook(Color::Black, Square(8, 8));
    rook->hasMoved = true;
    board.AddPiece(rook);
    board.AddPiece(PieceFactory::CreateKing(Color::Black, Square(5, 8)));
    LegalityChecker legalityChecker = LegalityChecker(board);
    DangerChecker dangerChecker = DangerChecker(board, legalityChecker, Color::Black);
    CastleChecker castleChecker = CastleChecker(board, legalityChecker, dangerChecker, Color::Black);

    // Act
    bool canCastle = castleChecker.CanCastleKingSide();

    // Assert
    ASSERT_FALSE(canCastle);
}

// TEST(CastleCheckerTest, WhenPieceInBetweenNoCastle){}

// TEST(CastleCheckerTest, WhenDestinationIsAttackedNoCastle){}

// TEST(CastleCheckerTest, WhenRookIsAttackedCanCastle){}

// TEST(CastleCheckerTest, WhenMovingOverAttackedSquareNoCastle){}
