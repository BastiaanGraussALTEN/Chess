#include "gtest/gtest.h"
#include "../header/MoveParser.h"

TEST(MoveParseTest, pawnMove)
{
    // Arrange

    // Act

    // Assert
}

TEST(MoveParseTest, KnightMove)
{
    // Arrange

    // Act

    // Assert
}

TEST(MoveParserTest, wrongRankIsNotValid)
{
    // Arrange
    Board board;
    MoveParser moveParser = MoveParser(board);
    std::string moveString = "e9e4";

    // Act
    bool isValid = moveParser.IsStringValid(moveString);

    // Assert
    EXPECT_FALSE(isValid);
}

TEST(MoveParserTest, wrongFileIsNotValid)
{
    // Arrange
    Board board;
    MoveParser moveParser = MoveParser(board);
    std::string moveString = "i2e4";

    // Act
    bool isValid = moveParser.IsStringValid(moveString);

    // Assert
    EXPECT_FALSE(isValid);
}

TEST(MoveParserTest, castleSideIsValid)
{
    // Arrange
    Board board;
    MoveParser moveParser = MoveParser(board);

    // Act
    bool isValidKingSide = moveParser.IsStringValid("0-0");
    bool isValidQueenSide = moveParser.IsStringValid("0-0-0");

    // Assert
    EXPECT_TRUE(isValidKingSide);
    EXPECT_TRUE(isValidQueenSide);
}

TEST(MoveParserTest, castlingIsPossible)
{
    // Arrange
    Board board;
    MoveParser moveParser = MoveParser(board);
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
    MoveParser moveParser = MoveParser(board);

    // Act
    bool isValid = moveParser.IsStringValid("e7e8=R");

    // Assert
    EXPECT_TRUE(isValid);
}

TEST(MoveParserTest, promotionIsCorrect)
{
    // Arrange
    Board board;
    MoveParser moveParser = MoveParser(board);
    Move expectedMove = Move(Square(5,7), Square(5,8));
    expectedMove.promotionPiece == PieceType::Rook;

    // Act
    Move promotion = moveParser.ParseString("e7e8=R");

    // Assert
    EXPECT_EQ(promotion.promotionPiece, PieceType::Rook);
    EXPECT_EQ(promotion, expectedMove);
}

TEST(MoveParserTest, promotionToKingNotAllowed)
{
    // Arrange
    Board board;
    MoveParser moveParser = MoveParser(board);

    // Act
    bool isValid = moveParser.IsStringValid("e7e8=K");

    // Assert
    EXPECT_FALSE(isValid);
}