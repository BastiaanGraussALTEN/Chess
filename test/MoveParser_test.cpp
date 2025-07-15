#include "gtest/gtest.h"
#include "../header/MoveParser.h"

TEST(MoveParserTest, validStringIsValid)
{
    // Arrange
    MoveParser moveParser;
    std::string moveString = "e2e4";

    // Act
    bool isValid = moveParser.IsStringValid(moveString);

    // Assert
    EXPECT_TRUE(isValid);
}

TEST(MoveParserTest, validStringGivesMove)
{
    // Arrange
    MoveParser moveParser;
    std::string moveString = "e2e4";
    Move expectedMove = Move(Square(5,2),Square(5,4));

    // Act
    Move actualMove = moveParser.ParseString(moveString);

    // Assert
    EXPECT_EQ(actualMove, expectedMove);
}

TEST(MoveParserTest, wrongRankIsNotValid)
{
    // Arrange
    MoveParser moveParser;
    std::string moveString = "e9e4";

    // Act
    bool isValid = moveParser.IsStringValid(moveString);

    // Assert
    EXPECT_FALSE(isValid);
}

TEST(MoveParserTest, wrongFileIsNotValid)
{
    // Arrange
    MoveParser moveParser;
    std::string moveString = "i2e4";

    // Act
    bool isValid = moveParser.IsStringValid(moveString);

    // Assert
    EXPECT_FALSE(isValid);
}

TEST(MoveParserTest, TooLongIsNotValid)
{
    // Arrange
    MoveParser moveParser;
    std::string moveString = "e2e4e5";

    // Act
    bool isValid = moveParser.IsStringValid(moveString);

    // Assert
    EXPECT_FALSE(isValid);
}

TEST(MoveParserTest, castleSideIsValid)
{
    // Arrange
    MoveParser moveParser;

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
    MoveParser moveParser;
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
    MoveParser moveParser;

    // Act
    bool isValid = moveParser.IsStringValid("e7e8=R");

    // Assert
    EXPECT_TRUE(isValid);
}

TEST(MoveParserTest, promotionIsCorrect)
{
    // Arrange
    MoveParser moveParser;
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
    MoveParser moveParser;

    // Act
    bool isValid = moveParser.IsStringValid("e7e8=K");

    // Assert
    EXPECT_FALSE(isValid);
}