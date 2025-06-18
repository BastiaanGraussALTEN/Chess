#include "gtest/gtest.h"
#include "../src/MoveParser.h"

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