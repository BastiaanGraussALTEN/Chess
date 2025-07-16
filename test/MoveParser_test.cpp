#include "gtest/gtest.h"
#include "../header/MoveParser.h"

TEST(MoveParseTest, pawnMoveIsLegal)
{
    // Arrange
    Board board;
    MoveParser moveParser = MoveParser(board, Color::White);
    std::string moveString = "e4";

    // Act
    Move move = moveParser.ParseString(moveString);

    // Assert
    EXPECT_TRUE(move.isLegal);
}

TEST(MoveParseTest, pawnMoveIsCorrect)
{
    // Arrange
    Board board;
    MoveParser moveParser = MoveParser(board, Color::White);
    std::string moveString = "e4";

    // Act
    Move move = moveParser.ParseString(moveString);

    // Assert
    EXPECT_EQ(move.start, Square(5,2));
    EXPECT_EQ(move.end, Square(5,4));
    EXPECT_EQ(move.piece, PieceType::Pawn);
}

TEST(MoveParseTest, KnightMoveIsLegal)
{
    // Arrange
    Board board;
    MoveParser moveParser = MoveParser(board, Color::White);
    std::string moveString = "Nc3";

    // Act
    Move move = moveParser.ParseString(moveString);

    // Assert
    EXPECT_TRUE(move.isLegal);
}

TEST(MoveParseTest, KnightMoveIsCorrect)
{
    // Arrange
    Board board;
    MoveParser moveParser = MoveParser(board, Color::White);
    std::string moveString = "Nc3";

    // Act
    Move move = moveParser.ParseString(moveString);

    // Assert
    EXPECT_EQ(move.start, Square(2,1));
    EXPECT_EQ(move.end, Square(3,3));
    EXPECT_EQ(move.piece, PieceType::Knight);
}

TEST(MoveParserTest, castleSideIsValid)
{
    // Arrange
    Board board;
    MoveParser moveParser = MoveParser(board, Color::White);

    // Act
    Move move1 = moveParser.ParseString("0-0");
    Move move2 = moveParser.ParseString("0-0-0");

    // Assert
    EXPECT_TRUE(move1.isLegal);
    EXPECT_TRUE(move2.isLegal);
}

TEST(MoveParserTest, castlingIsPossible)
{
    // Arrange
    Board board;
    MoveParser moveParser = MoveParser(board, Color::White);
    std::string moveCastleKingside = "0-0";
    std::string moveCastleQueenside = "0-0-0";

    // Act
    Move castleKingside = moveParser.ParseString(moveCastleKingside);
    Move castleQueenside = moveParser.ParseString(moveCastleQueenside);

    // Assert
    EXPECT_TRUE(castleKingside.isCastleKingside);
    EXPECT_TRUE(castleQueenside.isCastleQueenside);
}

TEST(MoveParserTest, promotionIsValid)
{
    // Arrange
    Board board;
    board.RemovePieceFromSquare(Square(5,7));
    board.RemovePieceFromSquare(Square(5,8));
    board.AddPiece(PieceFactory::CreatePawn(Color::White, Square(5,7)));
    MoveParser moveParser = MoveParser(board, Color::White);
    std::string moveString = "e7e8=R";

    // Act
    Move move = moveParser.ParseString(moveString);

    // Assert
    EXPECT_TRUE(move.isLegal);
}

TEST(MoveParserTest, promotionIsCorrect)
{
    // Arrange
    Board board;
    board.RemovePieceFromSquare(Square(5,7));
    board.RemovePieceFromSquare(Square(5,8));
    board.AddPiece(PieceFactory::CreatePawn(Color::White, Square(5,7)));
    MoveParser moveParser = MoveParser(board, Color::White);
    Move expectedMove = Move(Square(5,7), Square(5,8));
    expectedMove.promotionPiece == PieceType::Rook;

    // Act
    Move promotion = moveParser.ParseString("e7e8=R");

    // Assert
    EXPECT_TRUE(promotion.isPromotion);
    EXPECT_EQ(promotion.promotionPiece, PieceType::Rook);
    EXPECT_EQ(promotion, expectedMove);
}

TEST(MoveParserTest, promotionToKingNotAllowed)
{
    // Arrange
    Board board;
    MoveParser moveParser = MoveParser(board, Color::White);
    std::string moveString = "e7e8=K";

    // Act
    Move move = moveParser.ParseString(moveString);

    // Assert
    EXPECT_FALSE(move.isLegal);
}