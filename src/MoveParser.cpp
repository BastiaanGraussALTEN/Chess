#include "../header/MoveParser.h"
#include <map>

MoveParser::MoveParser(const Board &board, const Color& color) 
: m_board(board), m_legalityChecker(LegalityChecker(board)), m_color(color)
{
}

Move MoveParser::ParseString(const std::string& moveString) const
{
    Move move = Move(Square(1, 1),Square(1, 1));
    if (moveString.size() > 6)
    {
        move.isLegal = false;
        return move;
    }

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
    
    move.piece = CharToPieceType(moveString[0]);

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

    if (moveString.find('x') != std::string::npos 
    && m_board.GetPieceFromSquare(move.end) == nullptr)
    {
        move.isLegal = false;
        return move;
    }

    std::vector<Move> possibleMoves = GetPossibleMovesWithEndSquare(moveString, move);

    if (possibleMoves.size() == 0)
    {
        move.isLegal = false;
        return move;
    }
    if (possibleMoves.size() == 1)
    {
        move.start = possibleMoves[0].start;
        move.isLegal = true;
    }

    if (possibleMoves.size() > 1)
    {
        int position = moveString.find(endSquaresString);
        std::string moveStringBegin = moveString.substr(0, position);
        if (move.piece != PieceType::Pawn)
        {
            moveStringBegin = moveStringBegin.substr(1);
        }
        
        possibleMoves = ElimateMovesUsingStartSquareInfo(possibleMoves, moveStringBegin);
        if (possibleMoves.size() == 1)
        {
            move.start = possibleMoves[0].start;
            move.isLegal = true;
        }
        else
        {
            move.isLegal = false;
            return move;
        }
    }

    if (IsPromotion(move))
    {
        move.isPromotion = true;
        PieceType piece = CharToPieceType(moveString.substr(moveString.length() - 2 )[1]);
        if (piece == PieceType::Pawn || piece == PieceType::King)
        {
            move.isLegal = false;
            return move;
        }
        
        move.promotionPiece = piece;
        move.isLegal = true;
    }

    return move;
}

std::string MoveParser::MoveToString(const Move& move) const
{
    std::string moveString = "";
    if (move.isCastleKingside)
    {
        return "0-0";
    }
    if (move.isCastleQueenside)
    {
        return "0-0-0";
    }

    moveString += PieceTypeToString(move.piece);
    moveString += char(move.start.x) + 'a' - 1;
    moveString += std::to_string(move.start.y);
    moveString += "-";
    moveString += char(move.end.x) + 'a' - 1;
    moveString += std::to_string(move.end.y);
    
    if (move.isPromotion)
    {
        moveString += "=";
        moveString += PieceTypeToString(move.promotionPiece);
    }

    return moveString;
}

std::vector<Move> MoveParser::GetPossibleMovesWithEndSquare(const std::string& moveString, const Move& move) const
{
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

    return possibleMoves;
}

std::vector<Move> MoveParser::ElimateMovesUsingStartSquareInfo(std::vector<Move> possibleMoves, const std::string& moveStringBegin) const
{
    int file = 0;
    int rank = 0;
    for (int i = 0; i < moveStringBegin.size(); i++)
    {
        if (moveStringBegin[i] -'a' + 1 < 9 
            && moveStringBegin[i] -'a' + 1 > 0)
            {
                file = moveStringBegin[i] - 'a' + 1;
            }
        if (moveStringBegin[i] -'0' < 9 
            && moveStringBegin[i] -'0' >  0)
            {
                rank = moveStringBegin[i] -'0';
            }
    }
    for (int i = 0; i < possibleMoves.size(); i++)
    {
        if (file != 0 && possibleMoves[i].start.x != file)
        {
            possibleMoves.erase(possibleMoves.begin() + i);
        }
        if (rank != 0 && possibleMoves[i].start.y != rank)
        {
            possibleMoves.erase(possibleMoves.begin() + i);
        }
    }

    return possibleMoves;
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
    && (((move.end.y == 1) && (m_board.GetPieceFromSquare(move.start)->color == Color::Black)) 
    || ((move.end.y == 8) && (m_board.GetPieceFromSquare(move.start)->color == Color::White)));
}

std::string MoveParser::PieceTypeToString(const PieceType& pieceType) const
{
    std::string pieceString = "";
    if (pieceType == PieceType::Knight)
    {
        pieceString += "N";
    }
    if (pieceType == PieceType::Bishop)
    {
        pieceString += "B";
    }
    if (pieceType == PieceType::Rook)
    {
        pieceString += "R";
    }
    if (pieceType == PieceType::Queen)
    {
        pieceString += "Q";
    }
    if (pieceType == PieceType::King)
    {
        pieceString += "K";
    }

    return pieceString;
}