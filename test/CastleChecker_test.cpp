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

TEST(CastleCheckerTest, WhenWhiteKingWrongSquareNoCastleKingSide)
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

TEST(CastleCheckerTest, WhenBlackKingWrongSquareNoCastleKingSide)
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

TEST(CastleCheckerTest, WhenNoWhiteRookNoCastleKingSide)
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

TEST(CastleCheckerTest, WhenNoBlackRookNoCastleKingSide)
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

TEST(CastleCheckerTest, WhenWhiteRookIsOnWrongSquareNoCastleKingSide)
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

TEST(CastleCheckerTest, WhenBlackRookIsOnWrongSquareNoCastleKingSide)
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

TEST(CastleCheckerTest, WhenWhiteKingHasMovedNoCastleKingSide)
{
    // Arrange 
    Board board = CreateEmptyBoard();
    board.AddPiece(PieceFactory::CreateKing(Color::White, Square(5, 1)));
    board.GetPieceFromSquare(Square(5, 1))->hasMoved = true;
    board.AddPiece(PieceFactory::CreateRook(Color::White, Square(8, 1)));
    LegalityChecker legalityChecker = LegalityChecker(board);
    DangerChecker dangerChecker = DangerChecker(board, legalityChecker, Color::White);
    CastleChecker castleChecker = CastleChecker(board, legalityChecker, dangerChecker, Color::White);

    // Act
    bool canCastle = castleChecker.CanCastleKingSide();

    // Assert
    ASSERT_FALSE(canCastle);
}

TEST(CastleCheckerTest, WhenBlackKingHasMovedNoCastleKingSide)
{
    // Arrange 
    Board board = CreateEmptyBoard();
    board.AddPiece(PieceFactory::CreateKing(Color::Black, Square(5, 8)));
    board.GetPieceFromSquare(Square(5, 8))->hasMoved = true;
    board.AddPiece(PieceFactory::CreateRook(Color::Black, Square(8, 8)));
    LegalityChecker legalityChecker = LegalityChecker(board);
    DangerChecker dangerChecker = DangerChecker(board, legalityChecker, Color::Black);
    CastleChecker castleChecker = CastleChecker(board, legalityChecker, dangerChecker, Color::Black);

    // Act
    bool canCastle = castleChecker.CanCastleKingSide();

    // Assert
    ASSERT_FALSE(canCastle);
}

TEST(CastleCheckerTest, WhenWhiteRookHasMovedNoCastleKingSide)
{
    // Arrange 
    Board board = CreateEmptyBoard();
    board.AddPiece(PieceFactory::CreateRook(Color::White, Square(8, 1)));
    board.GetPieceFromSquare(Square(8, 1))->hasMoved = true;
    board.AddPiece(PieceFactory::CreateKing(Color::White, Square(5, 1)));
    LegalityChecker legalityChecker = LegalityChecker(board);
    DangerChecker dangerChecker = DangerChecker(board, legalityChecker, Color::White);
    CastleChecker castleChecker = CastleChecker(board, legalityChecker, dangerChecker, Color::White);

    // Act
    bool canCastle = castleChecker.CanCastleKingSide();

    // Assert
    ASSERT_FALSE(canCastle);
}

TEST(CastleCheckerTest, WhenBlackRookHasMovedNoCastleKingSide)
{
    // Arrange 
    Board board = CreateEmptyBoard();
    board.AddPiece(PieceFactory::CreateRook(Color::Black, Square(8, 8)));
    board.GetPieceFromSquare(Square(8, 8))->hasMoved = true;
    board.AddPiece(PieceFactory::CreateKing(Color::Black, Square(5, 8)));
    LegalityChecker legalityChecker = LegalityChecker(board);
    DangerChecker dangerChecker = DangerChecker(board, legalityChecker, Color::Black);
    CastleChecker castleChecker = CastleChecker(board, legalityChecker, dangerChecker, Color::Black);

    // Act
    bool canCastle = castleChecker.CanCastleKingSide();

    // Assert
    ASSERT_FALSE(canCastle);
}

TEST(CastleCheckerTest, WhenPieceInBetweenNoCastleKingSideForWhite)
{
    // Arrange 
    Board board = CreateEmptyBoard();
    board.AddPiece(PieceFactory::CreateKing(Color::White, Square(5, 1)));
    board.AddPiece(PieceFactory::CreateKnight(Color::White, Square(6, 1)));
    board.AddPiece(PieceFactory::CreateRook(Color::White, Square(8, 1)));
    LegalityChecker legalityChecker = LegalityChecker(board);
    DangerChecker dangerChecker = DangerChecker(board, legalityChecker, Color::White);
    CastleChecker castleChecker = CastleChecker(board, legalityChecker, dangerChecker, Color::White);

    // Act
    bool canCastle = castleChecker.CanCastleKingSide();

    // Assert
    ASSERT_FALSE(canCastle);
}

TEST(CastleCheckerTest, WhenPieceInBetweenNoCastleKingSideForBlack)
{
    // Arrange 
    Board board = CreateEmptyBoard();
    board.AddPiece(PieceFactory::CreateKing(Color::Black, Square(5, 8)));
    board.AddPiece(PieceFactory::CreateKnight(Color::Black, Square(6, 8)));
    board.AddPiece(PieceFactory::CreateRook(Color::Black, Square(8, 8)));
    LegalityChecker legalityChecker = LegalityChecker(board);
    DangerChecker dangerChecker = DangerChecker(board, legalityChecker, Color::Black);
    CastleChecker castleChecker = CastleChecker(board, legalityChecker, dangerChecker, Color::Black);

    // Act
    bool canCastle = castleChecker.CanCastleKingSide();

    // Assert
    ASSERT_FALSE(canCastle);
}

TEST(CastleCheckerTest, WhenInCheckNoCastleKingSideWhite)
{
    // Arrange 
    Board board = CreateEmptyBoard();
    board.AddPiece(PieceFactory::CreateKing(Color::White, Square(5, 1)));
    board.AddPiece(PieceFactory::CreateRook(Color::White, Square(8, 1)));
    board.AddPiece(PieceFactory::CreateRook(Color::Black, Square(5, 4)));
    LegalityChecker legalityChecker = LegalityChecker(board);
    DangerChecker dangerChecker = DangerChecker(board, legalityChecker, Color::White);
    CastleChecker castleChecker = CastleChecker(board, legalityChecker, dangerChecker, Color::White);

    // Act
    bool canCastle = castleChecker.CanCastleKingSide();

    // Assert
    ASSERT_FALSE(canCastle);
}

TEST(CastleCheckerTest, WhenInCheckNoCastleKingSideBlack)
{
    // Arrange 
    Board board = CreateEmptyBoard();
    board.AddPiece(PieceFactory::CreateKing(Color::Black, Square(5, 8)));
    board.AddPiece(PieceFactory::CreateRook(Color::Black, Square(8, 8)));
    board.AddPiece(PieceFactory::CreateRook(Color::White, Square(5, 4)));
    LegalityChecker legalityChecker = LegalityChecker(board);
    DangerChecker dangerChecker = DangerChecker(board, legalityChecker, Color::Black);
    CastleChecker castleChecker = CastleChecker(board, legalityChecker, dangerChecker, Color::Black);

    // Act
    bool canCastle = castleChecker.CanCastleKingSide();

    // Assert
    ASSERT_FALSE(canCastle);
}

TEST(CastleCheckerTest, WhenDestinationIsAttackedNoCastleKingSideWhite)
{
    // Arrange 
    Board board = CreateEmptyBoard();
    board.AddPiece(PieceFactory::CreateKing(Color::White, Square(5, 1)));
    board.AddPiece(PieceFactory::CreateRook(Color::White, Square(8, 1)));
    board.AddPiece(PieceFactory::CreateRook(Color::Black, Square(7, 4)));
    LegalityChecker legalityChecker = LegalityChecker(board);
    DangerChecker dangerChecker = DangerChecker(board, legalityChecker, Color::White);
    CastleChecker castleChecker = CastleChecker(board, legalityChecker, dangerChecker, Color::White);

    // Act
    bool canCastle = castleChecker.CanCastleKingSide();

    // Assert
    ASSERT_FALSE(canCastle);
}

TEST(CastleCheckerTest, WhenDestinationIsAttackedNoCastleKingSideBlack)
{
    // Arrange 
    Board board = CreateEmptyBoard();
    board.AddPiece(PieceFactory::CreateKing(Color::Black, Square(5, 8)));
    board.AddPiece(PieceFactory::CreateRook(Color::Black, Square(8, 8)));
    board.AddPiece(PieceFactory::CreateRook(Color::White, Square(7, 4)));
    LegalityChecker legalityChecker = LegalityChecker(board);
    DangerChecker dangerChecker = DangerChecker(board, legalityChecker, Color::Black);
    CastleChecker castleChecker = CastleChecker(board, legalityChecker, dangerChecker, Color::Black);

    // Act
    bool canCastle = castleChecker.CanCastleKingSide();

    // Assert
    ASSERT_FALSE(canCastle);
}

TEST(CastleCheckerTest, WhenRookIsAttackedCanCastleKingSideWhite)
{
    // Arrange 
    Board board = CreateEmptyBoard();
    board.AddPiece(PieceFactory::CreateRook(Color::White, Square(8, 1)));
    board.AddPiece(PieceFactory::CreateKing(Color::White, Square(5, 1)));
    board.AddPiece(PieceFactory::CreateRook(Color::Black, Square(8, 4)));
    LegalityChecker legalityChecker = LegalityChecker(board);
    DangerChecker dangerChecker = DangerChecker(board, legalityChecker, Color::White);
    CastleChecker castleChecker = CastleChecker(board, legalityChecker, dangerChecker, Color::White);

    // Act
    bool canCastle = castleChecker.CanCastleKingSide();

    // Assert
    ASSERT_TRUE(canCastle);
}

TEST(CastleCheckerTest, WhenRookIsAttackedCanCastleKingSideBlack)
{
    // Arrange 
    Board board = CreateEmptyBoard();
    board.AddPiece(PieceFactory::CreateKing(Color::Black, Square(5, 8)));
    board.AddPiece(PieceFactory::CreateRook(Color::Black, Square(8, 8)));
    board.AddPiece(PieceFactory::CreateRook(Color::White, Square(8, 4)));
    LegalityChecker legalityChecker = LegalityChecker(board);
    DangerChecker dangerChecker = DangerChecker(board, legalityChecker, Color::Black);
    CastleChecker castleChecker = CastleChecker(board, legalityChecker, dangerChecker, Color::Black);

    // Act
    bool canCastle = castleChecker.CanCastleKingSide();

    // Assert
    ASSERT_TRUE(canCastle);
}

TEST(CastleCheckerTest, WhenMovingOverAttackedSquareNoCastleKingSideWhite)
{
    // Arrange 
    Board board = CreateEmptyBoard();
    board.AddPiece(PieceFactory::CreateKing(Color::White, Square(5, 1)));
    board.AddPiece(PieceFactory::CreateRook(Color::White, Square(8, 1)));
    board.AddPiece(PieceFactory::CreateRook(Color::Black, Square(6, 4)));
    LegalityChecker legalityChecker = LegalityChecker(board);
    DangerChecker dangerChecker = DangerChecker(board, legalityChecker, Color::White);
    CastleChecker castleChecker = CastleChecker(board, legalityChecker, dangerChecker, Color::White);

    // Act
    bool canCastle = castleChecker.CanCastleKingSide();

    // Assert
    ASSERT_FALSE(canCastle);
}

TEST(CastleCheckerTest, WhenMovingOverAttackedSquareNoCastleKingSideBlack)
{
    // Arrange 
    Board board = CreateEmptyBoard();
    board.AddPiece(PieceFactory::CreateKing(Color::Black, Square(5, 8)));
    board.AddPiece(PieceFactory::CreateRook(Color::Black, Square(8, 8)));
    board.AddPiece(PieceFactory::CreateRook(Color::White, Square(6, 4)));
    LegalityChecker legalityChecker = LegalityChecker(board);
    DangerChecker dangerChecker = DangerChecker(board, legalityChecker, Color::Black);
    CastleChecker castleChecker = CastleChecker(board, legalityChecker, dangerChecker, Color::Black);

    // Act
    bool canCastle = castleChecker.CanCastleKingSide();

    // Assert
    ASSERT_FALSE(canCastle);
}

TEST(CastleCheckerTest, WhiteCanCastleQueenSide)
{
    // Arrange 
    Board board = CreateEmptyBoard();
    board.AddPiece(PieceFactory::CreateKing(Color::White, Square(5, 1)));
    board.AddPiece(PieceFactory::CreateRook(Color::White, Square(1, 1)));
    LegalityChecker legalityChecker = LegalityChecker(board);
    DangerChecker dangerChecker = DangerChecker(board, legalityChecker, Color::White);
    CastleChecker castleChecker = CastleChecker(board, legalityChecker, dangerChecker, Color::White);

    // Act
    bool canCastle = castleChecker.CanCastleQueenSide();

    // Assert
    ASSERT_TRUE(canCastle);
}

TEST(CastleCheckerTest, BlackCanCastleQueenSide)
{
    // Arrange 
    Board board = CreateEmptyBoard();
    board.AddPiece(PieceFactory::CreateKing(Color::Black, Square(5, 8)));
    board.AddPiece(PieceFactory::CreateRook(Color::Black, Square(1, 8)));
    LegalityChecker legalityChecker = LegalityChecker(board);
    DangerChecker dangerChecker = DangerChecker(board, legalityChecker, Color::Black);
    CastleChecker castleChecker = CastleChecker(board, legalityChecker, dangerChecker, Color::Black);

    // Act
    bool canCastle = castleChecker.CanCastleQueenSide();

    // Assert
    ASSERT_TRUE(canCastle);
}

TEST(CastleCheckerTest, WhenWhiteKingWrongSquareNoCastleQueenSide)
{
    // Arrange 
    Board board = CreateEmptyBoard();
    board.AddPiece(PieceFactory::CreateKing(Color::White, Square(6, 1)));
    board.AddPiece(PieceFactory::CreateRook(Color::White, Square(1, 1)));
    LegalityChecker legalityChecker = LegalityChecker(board);
    DangerChecker dangerChecker = DangerChecker(board, legalityChecker, Color::White);
    CastleChecker castleChecker = CastleChecker(board, legalityChecker, dangerChecker, Color::White);

    // Act
    bool canCastle = castleChecker.CanCastleQueenSide();

    // Assert
    ASSERT_FALSE(canCastle);
}

TEST(CastleCheckerTest, WhenBlackKingWrongSquareNoCastleQueenSide)
{
    // Arrange 
    Board board = CreateEmptyBoard();
    board.AddPiece(PieceFactory::CreateKing(Color::Black, Square(6, 8)));
    board.AddPiece(PieceFactory::CreateRook(Color::Black, Square(1, 8)));
    LegalityChecker legalityChecker = LegalityChecker(board);
    DangerChecker dangerChecker = DangerChecker(board, legalityChecker, Color::Black);
    CastleChecker castleChecker = CastleChecker(board, legalityChecker, dangerChecker, Color::Black);

    // Act
    bool canCastle = castleChecker.CanCastleQueenSide();

    // Assert
    ASSERT_FALSE(canCastle);
}

TEST(CastleCheckerTest, WhenNoWhiteRookNoCastleQueenSide)
{
    // Arrange 
    Board board = CreateEmptyBoard();
    board.AddPiece(PieceFactory::CreateKing(Color::White, Square(5, 1)));
    LegalityChecker legalityChecker = LegalityChecker(board);
    DangerChecker dangerChecker = DangerChecker(board, legalityChecker, Color::White);
    CastleChecker castleChecker = CastleChecker(board, legalityChecker, dangerChecker, Color::White);

    // Act
    bool canCastle = castleChecker.CanCastleQueenSide();

    // Assert
    ASSERT_FALSE(canCastle);
}

TEST(CastleCheckerTest, WhenNoBlackRookNoCastleQueenSide)
{
    // Arrange 
    Board board = CreateEmptyBoard();
    board.AddPiece(PieceFactory::CreateKing(Color::Black, Square(5, 8)));
    LegalityChecker legalityChecker = LegalityChecker(board);
    DangerChecker dangerChecker = DangerChecker(board, legalityChecker, Color::Black);
    CastleChecker castleChecker = CastleChecker(board, legalityChecker, dangerChecker, Color::Black);

    // Act
    bool canCastle = castleChecker.CanCastleQueenSide();

    // Assert
    ASSERT_FALSE(canCastle);
}

TEST(CastleCheckerTest, WhenWhiteRookIsOnWrongSquareNoCastleQueenSide)
{
    // Arrange 
    Board board = CreateEmptyBoard();
    board.AddPiece(PieceFactory::CreateKing(Color::White, Square(5, 1)));
    board.AddPiece(PieceFactory::CreateRook(Color::White, Square(7, 1)));
    LegalityChecker legalityChecker = LegalityChecker(board);
    DangerChecker dangerChecker = DangerChecker(board, legalityChecker, Color::White);
    CastleChecker castleChecker = CastleChecker(board, legalityChecker, dangerChecker, Color::White);

    // Act
    bool canCastle = castleChecker.CanCastleQueenSide();

    // Assert
    ASSERT_FALSE(canCastle);
}

TEST(CastleCheckerTest, WhenBlackRookIsOnWrongSquareNoCastleQueenSide)
{
    // Arrange 
    Board board = CreateEmptyBoard();
    board.AddPiece(PieceFactory::CreateKing(Color::Black, Square(5, 8)));
    board.AddPiece(PieceFactory::CreateRook(Color::Black, Square(7, 8)));
    LegalityChecker legalityChecker = LegalityChecker(board);
    DangerChecker dangerChecker = DangerChecker(board, legalityChecker, Color::Black);
    CastleChecker castleChecker = CastleChecker(board, legalityChecker, dangerChecker, Color::Black);

    // Act
    bool canCastle = castleChecker.CanCastleQueenSide();

    // Assert
    ASSERT_FALSE(canCastle);
}

TEST(CastleCheckerTest, WhenWhiteKingHasMovedNoCastleQueenSide)
{
    // Arrange 
    Board board = CreateEmptyBoard();
    board.AddPiece(PieceFactory::CreateKing(Color::White, Square(5, 1)));
    board.GetPieceFromSquare(Square(5, 1))->hasMoved = true;
    board.AddPiece(PieceFactory::CreateRook(Color::White, Square(1, 1)));
    LegalityChecker legalityChecker = LegalityChecker(board);
    DangerChecker dangerChecker = DangerChecker(board, legalityChecker, Color::White);
    CastleChecker castleChecker = CastleChecker(board, legalityChecker, dangerChecker, Color::White);

    // Act
    bool canCastle = castleChecker.CanCastleQueenSide();

    // Assert
    ASSERT_FALSE(canCastle);
}

TEST(CastleCheckerTest, WhenBlackKingHasMovedNoCastleQueenSide)
{
    // Arrange 
    Board board = CreateEmptyBoard();
    board.AddPiece(PieceFactory::CreateKing(Color::Black, Square(5, 8)));
    board.GetPieceFromSquare(Square(5, 8))->hasMoved = true;
    board.AddPiece(PieceFactory::CreateRook(Color::Black, Square(1, 8)));
    LegalityChecker legalityChecker = LegalityChecker(board);
    DangerChecker dangerChecker = DangerChecker(board, legalityChecker, Color::Black);
    CastleChecker castleChecker = CastleChecker(board, legalityChecker, dangerChecker, Color::Black);

    // Act
    bool canCastle = castleChecker.CanCastleQueenSide();

    // Assert
    ASSERT_FALSE(canCastle);
}

TEST(CastleCheckerTest, WhenWhiteRookHasMovedNoCastleQueenSide)
{
    // Arrange 
    Board board = CreateEmptyBoard();
    board.AddPiece(PieceFactory::CreateRook(Color::White, Square(1, 1)));
    board.GetPieceFromSquare(Square(1, 1))->hasMoved = true;
    board.AddPiece(PieceFactory::CreateKing(Color::White, Square(5, 1)));
    LegalityChecker legalityChecker = LegalityChecker(board);
    DangerChecker dangerChecker = DangerChecker(board, legalityChecker, Color::White);
    CastleChecker castleChecker = CastleChecker(board, legalityChecker, dangerChecker, Color::White);

    // Act
    bool canCastle = castleChecker.CanCastleQueenSide();

    // Assert
    ASSERT_FALSE(canCastle);
}

TEST(CastleCheckerTest, WhenBlackRookHasMovedNoCastleQueenSide)
{
    // Arrange 
    Board board = CreateEmptyBoard();
    board.AddPiece(PieceFactory::CreateRook(Color::Black, Square(1, 8)));
    board.GetPieceFromSquare(Square(1, 8))->hasMoved = true;
    board.AddPiece(PieceFactory::CreateKing(Color::Black, Square(5, 8)));
    LegalityChecker legalityChecker = LegalityChecker(board);
    DangerChecker dangerChecker = DangerChecker(board, legalityChecker, Color::Black);
    CastleChecker castleChecker = CastleChecker(board, legalityChecker, dangerChecker, Color::Black);

    // Act
    bool canCastle = castleChecker.CanCastleQueenSide();

    // Assert
    ASSERT_FALSE(canCastle);
}

TEST(CastleCheckerTest, WhenPieceInBetweenNoCastleQueenSideForWhite)
{
    // Arrange 
    Board board = CreateEmptyBoard();
    board.AddPiece(PieceFactory::CreateKing(Color::White, Square(5, 1)));
    board.AddPiece(PieceFactory::CreateKnight(Color::White, Square(2, 1)));
    board.AddPiece(PieceFactory::CreateRook(Color::White, Square(1, 1)));
    LegalityChecker legalityChecker = LegalityChecker(board);
    DangerChecker dangerChecker = DangerChecker(board, legalityChecker, Color::White);
    CastleChecker castleChecker = CastleChecker(board, legalityChecker, dangerChecker, Color::White);

    // Act
    bool canCastle = castleChecker.CanCastleQueenSide();

    // Assert
    ASSERT_FALSE(canCastle);
}

TEST(CastleCheckerTest, WhenPieceInBetweenNoCastleQueenSideForBlack)
{
    // Arrange 
    Board board = CreateEmptyBoard();
    board.AddPiece(PieceFactory::CreateKing(Color::Black, Square(5, 8)));
    board.AddPiece(PieceFactory::CreateKnight(Color::Black, Square(2, 8)));
    board.AddPiece(PieceFactory::CreateRook(Color::Black, Square(1, 8)));
    LegalityChecker legalityChecker = LegalityChecker(board);
    DangerChecker dangerChecker = DangerChecker(board, legalityChecker, Color::Black);
    CastleChecker castleChecker = CastleChecker(board, legalityChecker, dangerChecker, Color::Black);

    // Act
    bool canCastle = castleChecker.CanCastleQueenSide();

    // Assert
    ASSERT_FALSE(canCastle);
}

TEST(CastleCheckerTest, WhenInCheckNoCastleQueenSideWhite)
{
    // Arrange 
    Board board = CreateEmptyBoard();
    board.AddPiece(PieceFactory::CreateKing(Color::White, Square(5, 1)));
    board.AddPiece(PieceFactory::CreateRook(Color::White, Square(1, 1)));
    board.AddPiece(PieceFactory::CreateRook(Color::Black, Square(5, 4)));
    LegalityChecker legalityChecker = LegalityChecker(board);
    DangerChecker dangerChecker = DangerChecker(board, legalityChecker, Color::White);
    CastleChecker castleChecker = CastleChecker(board, legalityChecker, dangerChecker, Color::White);

    // Act
    bool canCastle = castleChecker.CanCastleQueenSide();

    // Assert
    ASSERT_FALSE(canCastle);
}

TEST(CastleCheckerTest, WhenInCheckNoCastleQueenSideBlack)
{
    // Arrange 
    Board board = CreateEmptyBoard();
    board.AddPiece(PieceFactory::CreateKing(Color::Black, Square(5, 8)));
    board.AddPiece(PieceFactory::CreateRook(Color::Black, Square(1, 8)));
    board.AddPiece(PieceFactory::CreateRook(Color::White, Square(5, 4)));
    LegalityChecker legalityChecker = LegalityChecker(board);
    DangerChecker dangerChecker = DangerChecker(board, legalityChecker, Color::Black);
    CastleChecker castleChecker = CastleChecker(board, legalityChecker, dangerChecker, Color::Black);

    // Act
    bool canCastle = castleChecker.CanCastleQueenSide();

    // Assert
    ASSERT_FALSE(canCastle);
}

TEST(CastleCheckerTest, WhenDestinationIsAttackedNoCastleQueenSideWhite)
{
    // Arrange 
    Board board = CreateEmptyBoard();
    board.AddPiece(PieceFactory::CreateKing(Color::White, Square(5, 1)));
    board.AddPiece(PieceFactory::CreateRook(Color::White, Square(1, 1)));
    board.AddPiece(PieceFactory::CreateRook(Color::Black, Square(3, 4)));
    LegalityChecker legalityChecker = LegalityChecker(board);
    DangerChecker dangerChecker = DangerChecker(board, legalityChecker, Color::White);
    CastleChecker castleChecker = CastleChecker(board, legalityChecker, dangerChecker, Color::White);

    // Act
    bool canCastle = castleChecker.CanCastleQueenSide();

    // Assert
    ASSERT_FALSE(canCastle);
}

TEST(CastleCheckerTest, WhenDestinationIsAttackedNoCastleQueenSideBlack)
{
    // Arrange 
    Board board = CreateEmptyBoard();
    board.AddPiece(PieceFactory::CreateKing(Color::Black, Square(5, 8)));
    board.AddPiece(PieceFactory::CreateRook(Color::Black, Square(1, 8)));
    board.AddPiece(PieceFactory::CreateRook(Color::White, Square(3, 4)));
    LegalityChecker legalityChecker = LegalityChecker(board);
    DangerChecker dangerChecker = DangerChecker(board, legalityChecker, Color::Black);
    CastleChecker castleChecker = CastleChecker(board, legalityChecker, dangerChecker, Color::Black);

    // Act
    bool canCastle = castleChecker.CanCastleQueenSide();

    // Assert
    ASSERT_FALSE(canCastle);
}

TEST(CastleCheckerTest, WhenRookIsAttackedCanCastleQueenSideWhite)
{
    // Arrange 
    Board board = CreateEmptyBoard();
    board.AddPiece(PieceFactory::CreateKing(Color::White, Square(5, 1)));
    board.AddPiece(PieceFactory::CreateRook(Color::White, Square(1, 1)));
    board.AddPiece(PieceFactory::CreateRook(Color::Black, Square(1, 4)));
    LegalityChecker legalityChecker = LegalityChecker(board);
    DangerChecker dangerChecker = DangerChecker(board, legalityChecker, Color::White);
    CastleChecker castleChecker = CastleChecker(board, legalityChecker, dangerChecker, Color::White);

    // Act
    bool canCastle = castleChecker.CanCastleQueenSide();

    // Assert
    ASSERT_TRUE(canCastle);
}

TEST(CastleCheckerTest, WhenRookIsAttackedCanCastleQueenSideBlack)
{
    // Arrange 
    Board board = CreateEmptyBoard();
    board.AddPiece(PieceFactory::CreateKing(Color::Black, Square(5, 8)));
    board.AddPiece(PieceFactory::CreateRook(Color::Black, Square(1, 8)));
    board.AddPiece(PieceFactory::CreateRook(Color::White, Square(1, 4)));
    LegalityChecker legalityChecker = LegalityChecker(board);
    DangerChecker dangerChecker = DangerChecker(board, legalityChecker, Color::Black);
    CastleChecker castleChecker = CastleChecker(board, legalityChecker, dangerChecker, Color::Black);

    // Act
    bool canCastle = castleChecker.CanCastleQueenSide();

    // Assert
    ASSERT_TRUE(canCastle);
}

TEST(CastleCheckerTest, WhenMovingOverAttackedSquareNoCastleQueenSideWhite)
{
    // Arrange 
    Board board = CreateEmptyBoard();
    board.AddPiece(PieceFactory::CreateKing(Color::White, Square(5, 1)));
    board.AddPiece(PieceFactory::CreateRook(Color::White, Square(1, 1)));
    board.AddPiece(PieceFactory::CreateRook(Color::Black, Square(4, 4)));
    LegalityChecker legalityChecker = LegalityChecker(board);
    DangerChecker dangerChecker = DangerChecker(board, legalityChecker, Color::White);
    CastleChecker castleChecker = CastleChecker(board, legalityChecker, dangerChecker, Color::White);

    // Act
    bool canCastle = castleChecker.CanCastleQueenSide();

    // Assert
    ASSERT_FALSE(canCastle);
}

TEST(CastleCheckerTest, WhenMovingOverAttackedSquareNoCastleQueenSideBlack)
{
    // Arrange 
    Board board = CreateEmptyBoard();
    board.AddPiece(PieceFactory::CreateKing(Color::Black, Square(5, 8)));
    board.AddPiece(PieceFactory::CreateRook(Color::Black, Square(1, 8)));
    board.AddPiece(PieceFactory::CreateRook(Color::White, Square(4, 4)));
    LegalityChecker legalityChecker = LegalityChecker(board);
    DangerChecker dangerChecker = DangerChecker(board, legalityChecker, Color::Black);
    CastleChecker castleChecker = CastleChecker(board, legalityChecker, dangerChecker, Color::Black);

    // Act
    bool canCastle = castleChecker.CanCastleQueenSide();

    // Assert
    ASSERT_FALSE(canCastle);
}
