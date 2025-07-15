#include "../header/MoveParser.h"
#include <map>

MoveParser::MoveParser(const Board &board, const Color& color) 
: m_board(board), m_legalityChecker(LegalityChecker(board)), m_color(color)
{
}

Move MoveParser::ParseString(const std::string& moveString) const
{
    Move move = Move(Square(1, 1),Square(1, 1));
    //check if castle
    if (moveString == "0-0")
    {
        move.isCastleKingside = true;
        move.isLegal = true;
        return move;
    }
    if (moveString == "0-0-0")
    {
        move.isCastleQueenside = true;
        move.isLegal = true;
        return move;
    }
    
    // set piece
    move.piece = CharToPieceType(moveString[0]);

    //find end square
    std::string endSquaresString = moveString.substr(moveString.length() - 2);
    if (IsStringPromotion(moveString))
    {
        endSquaresString = moveString.substr(moveString.length() - 4, moveString.length() - 2);
    }
    if (!IsStringSquare(endSquaresString))
    {
        move.isLegal = false;
        return move;
    }
    move.end = stringToSquare(endSquaresString);

    // check if capture is intended and possible
    if (moveString.find('x') != std::string::npos 
    && m_board.GetPieceFromSquare(move.end) == nullptr)
    {
        move.isLegal = false;
        return move;
    }

    // check how many pieces can end at this square
    std::vector<Move> allMoves = m_legalityChecker.GetAllPossibleMoves(m_color);
    std::vector<Move> possibleMoves;
    for (const auto& pontentialMove : allMoves)
    {
        if (pontentialMove.end == move.end 
            && m_board.GetPieceFromSquare(pontentialMove.start)->pieceType == move.piece)
        {
            possibleMoves.push_back(pontentialMove);
        }
    }
    if (possibleMoves.size() == 0)
    {
        move.isLegal = false;
        return move;
    }
    if (possibleMoves.size() == 1)
    {
        move.start == possibleMoves[0].start;
        move.isLegal = true;
    }
    // check for file or rank
    if (possibleMoves.size() > 1)
    {

    }

    if (IsPromotion(move))
    {
        move.isPromotion = true;
        char piece = moveString.substr(moveString.length() - 2 )[1];
        move.promotionPiece = CharToPieceType(piece);
        move.isLegal = true;
    }

    return move;
}

bool MoveParser::IsStringPromotion(const std::string &moveString) const
{
    std::string lastTwoChars = moveString.substr(moveString.length() - 2);
    return ((lastTwoChars[0] == '=')
        &&(CharIsValidPromotionPiece(lastTwoChars[1]))
        &&(moveString[0] - 'a' + 1 > 0)
        &&(moveString[0] - 'a' + 1 < 9)
        &&(moveString[1] - '0' > 0)
        &&(moveString[1] - '0' < 9)
        &&(moveString[2] - 'a' + 1 > 0)
        &&(moveString[2] - 'a' + 1 < 9)
        &&((moveString[3] - '0' == 1) ||(moveString[3] - '0' == 8)));
}

Square MoveParser::stringToSquare(const std::string& moveString) const
{
    Square square = Square(1,1);
    square.x = moveString[0] - 'a' + 1;
    square.y = moveString[1] - '0';
    return square;
}

bool MoveParser::IsStringSquare(const std::string& moveString) const
{
    return (moveString[0] - 'a' + 1 > 0)
        && (moveString[0] - 'a' + 1 < 9)
        && (moveString[1] - '0' > 0)
        && (moveString[1] - '0' < 9);
}

bool MoveParser::CharIsValidPromotionPiece(const char &piece) const
{
    return (piece == 'N') 
    || (piece == 'B')
    || (piece == 'R')
    || (piece == 'Q');
}

PieceType MoveParser::CharToPieceType(const char &piece) const
{
    if (piece == 'N')
    {
        return PieceType::Knight;
    }
    if (piece == 'B')
    {
        return PieceType::Bishop;
    }
    if (piece == 'R')
    {
        return PieceType::Rook;
    }
    if (piece == 'Q')
    {
        return PieceType::Queen;
    }
    if (piece == 'K')
    {
        return PieceType::King;
    }
    
    return PieceType::Pawn;
}

bool MoveParser::IsPromotion(const Move& move) const
{
    return (move.piece == PieceType::Pawn) 
    && (((move.end.y == 1) && (m_board.GetPieceFromSquare(move.end)->color == Color::Black)) 
    || ((move.end.y == 8) && (m_board.GetPieceFromSquare(move.end)->color == Color::White)));
}