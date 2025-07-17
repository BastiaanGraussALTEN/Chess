#include "gtest/gtest.h"
#include "../header/MoveParser.h"

TEST(MoveParserTest, StringIsTooLong)
{
    // Arrange
    Board board;
    MoveParser moveParser = MoveParser(board, Color::White);
    std::string moveString = "testteste4";

    // Act
    Move move = moveParser.ParseString(moveString);

    // Assert
    EXPECT_FALSE(move.isLegal);
}

TEST(MoveParserTest, pawnMoveIsLegal)
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

TEST(MoveParserTest, pawnMoveIsCorrect)
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

TEST(MoveParserTest, KnightMoveIsLegal)
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

TEST(MoveParserTest, KnightMoveIsCorrect)
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

TEST(MoveParserTest, AmbigiousMoveDifferentFile)
{
    // Arrange
    Board board;
    board.AddPiece(PieceFactory::CreateKnight(Color::White, Square(3,5)));
    board.AddPiece(PieceFactory::CreateKnight(Color::White, Square(5,5)));
    MoveParser moveParser = MoveParser(board, Color::White);
    std::string moveString = "Ncd3";

    // Act
    Move move = moveParser.ParseString(moveString);

    // Assert
    EXPECT_TRUE(move.isLegal);
}

TEST(MoveParserTest, AmbigiousMoveDifferentRank)
{
    // Arrange
    Board board;
    board.AddPiece(PieceFactory::CreateKnight(Color::White, Square(2,5)));
    MoveParser moveParser = MoveParser(board, Color::White);
    std::string moveString = "N5c3";

    // Act
    Move move = moveParser.ParseString(moveString);

    // Assert
    EXPECT_TRUE(move.isLegal);
}

TEST(MoveParserTest, AmbigiousMoveDifferentSquare)
{
    // Arrange
    Board board;
    board.AddPiece(PieceFactory::CreateKnight(Color::White, Square(2,5)));
    board.AddPiece(PieceFactory::CreateKnight(Color::White, Square(4,5)));
    MoveParser moveParser = MoveParser(board, Color::White);
    std::string moveString = "Nb5c3";

    // Act
    Move move = moveParser.ParseString(moveString);

    // Assert
    EXPECT_TRUE(move.isLegal);
}

TEST(MoveParserTest, AmbigiousPawnMove)
{
    // Arrange
    Board board;
    board.AddPiece(PieceFactory::CreatePawn(Color::Black, Square(5,3)));
    MoveParser moveParser = MoveParser(board, Color::White);
    std::string moveString = "dxe3";

    // Act
    Move move = moveParser.ParseString(moveString);

    // Assert
    EXPECT_TRUE(move.isLegal);
}

TEST(MoveParserTest, AmbigiousMoveIsNotAllowed)
{
    // Arrange
    Board board;
    board.AddPiece(PieceFactory::CreateKnight(Color::White, Square(2,5)));
    board.AddPiece(PieceFactory::CreateKnight(Color::White, Square(4,5)));
    MoveParser moveParser = MoveParser(board, Color::White);
    std::string moveString = "Nbc3";

    // Act
    Move move = moveParser.ParseString(moveString);

    // Assert
    EXPECT_FALSE(move.isLegal);
}

TEST(MoveParserTest, PawnMoveGivesString)
{
    // Arrange
    Board board;
    MoveParser moveParser = MoveParser(board, Color::White);
    Move move = Move(Square(5,2),Square(5,4));

    // Act
    std::string moveString = moveParser.MoveToString(move);

    // Assert
    ASSERT_EQ(moveString, "e2-e4");
}

TEST(MoveParserTest, KnightMoveGivesString)
{
    // Arrange
    Board board;
    MoveParser moveParser = MoveParser(board, Color::White);
    Move move = Move(Square(2,1),Square(3,3));
    move.piece = PieceType::Knight;

    // Act
    std::string moveString = moveParser.MoveToString(move);

    // Assert
    ASSERT_EQ(moveString, "Nb1-c3");
}

TEST(MoveParserTest, CastleGivesMoveString)
{
    // Arrange
    Board board;
    MoveParser moveParser = MoveParser(board, Color::White);
    Move castleKingside = Move(Square(1,1),Square(1,1));
    castleKingside.isCastleKingside = true;
    Move castleQueenside = Move(Square(1,1),Square(1,1));
    castleQueenside.isCastleQueenside = true;

    // Act
    std::string castleKingsideString = moveParser.MoveToString(castleKingside);
    std::string castleQueensideString = moveParser.MoveToString(castleQueenside);

    // Assert
    ASSERT_EQ(castleKingsideString, "0-0");
    ASSERT_EQ(castleQueensideString, "0-0-0");
}

TEST(MoveParserTest, PromotionGivesMoveString)
{
    // Arrange
    Board board;
    MoveParser moveParser = MoveParser(board, Color::White);
    Move move = Move(Square(5,2),Square(5,4));
    move.isPromotion = true;
    move.promotionPiece = PieceType::Knight;

    // Act
    std::string moveString = moveParser.MoveToString(move);

    // Assert
    ASSERT_EQ(moveString, "e2-e4=N");
}
