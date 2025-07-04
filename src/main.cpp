#include <iostream>
#include "MoveDialog.h"
#include "MoveParser.h"
#include "CastleChecker.h"
#include "CheckChecker.h"

bool IsPromotion(const Board& board, const Move& move)
{
    if ((board.GetPieceFromSquare(move.end)->pieceType == PieceType::PawnType) 
    && (((move.end.y == 1) && (board.GetPieceFromSquare(move.end)->color == Color::Black)) 
    || ((move.end.y == 8) && (board.GetPieceFromSquare(move.end)->color == Color::White))))
    {
        return true;
    }

    return false;
}

int main()
{
    MoveDialog moveDialog;
    MoveParser moveParser;
    Board board;
    bool isGameEnded = false;
    while(!isGameEnded)
    {
        Color colorToMove = moveDialog.GetCurrentTurn();
        LegalityChecker legalityChecker = LegalityChecker(board);
        CheckChecker checkChecker = CheckChecker(board, colorToMove);
        DangerChecker dangerChecker = DangerChecker(board, legalityChecker, colorToMove);
        CastleChecker castleChecker = CastleChecker(board, legalityChecker, dangerChecker, colorToMove);

        if (checkChecker.EveryMoveChecksSelf())
        {
            isGameEnded = true;
            moveDialog.ShowMoveHistory();
            if (dangerChecker.IsKingUnderAttack())
            {
                moveDialog.ShowCheckMate();
            }
            else
            {
                moveDialog.ShowStaleMate();
            }
            continue;
        }

        if (board.IsFiftyMoveRule())
        {
            isGameEnded = true;
            moveDialog.ShowMoveHistory();
            moveDialog.Show50MoveDraw();
            continue;
        }
        
        std::string moveString;
        bool validMoveIsGiven = false;

        while(!validMoveIsGiven)
        {
            moveDialog.ShowDialog();
            std::cin >> moveString;
            if (!moveParser.IsStringValid(moveString))
            {
                moveDialog.ShowStringNotValid();
                continue;
            }
            
            Move move = moveParser.ParseString(moveString);
            if (move.promotionOrCastleside == PieceType::KingType) 
            {
                if (!castleChecker.CanCastleKingSide())
                {
                    moveDialog.ShowIllegalCastling();
                    continue;
                }

                board.CastleKingside(colorToMove);
                moveDialog.SetMove(moveString);
                validMoveIsGiven = true;
                continue;
            }
            if (move.promotionOrCastleside == PieceType::PawnType) 
            {
                if (!castleChecker.CanCastleQueenSide())
                {
                    moveDialog.ShowIllegalCastling();
                    continue;
                }
                
                board.CastleQueenside(colorToMove);
                moveDialog.SetMove(moveString);
                validMoveIsGiven = true;
                continue;
            }

            if (!legalityChecker.CheckMoveLegality(move))
            {
                moveDialog.ShowMoveNotLegal();
                continue;
            }

            if ((!board.IsThereAPieceOfThisColorHere(colorToMove, move.start))
                && (board.GetPieceFromSquare(move.start) != nullptr))
            {
                moveDialog.ShowPieceWrongColor();
                continue;
            }

            if (!checkChecker.IsKingSafeAfterMove(move))
            {
                moveDialog.ShowMovePutsKingInCheck();
                continue;
            }

            if (legalityChecker.DoesMoveCapturePiece(move))
            {
                board.RemovePieceFromSquare(move.end);
            }

            board.MovePiece(move);

            if (IsPromotion(board, move))
            {
                board.RemovePieceFromSquare(move.end);
                switch (move.promotionOrCastleside)
                {
                    case PieceType::KnightType:
                        board.AddPiece(PieceFactory::CreateKnight(colorToMove, move.end));
                        break;
                    case PieceType::BishopType:
                        board.AddPiece(PieceFactory::CreateBishop(colorToMove, move.end));
                        break;
                    case PieceType::RookType:
                        board.AddPiece(PieceFactory::CreateRook(colorToMove, move.end));
                        break;
                    case PieceType::QueenType:
                        board.AddPiece(PieceFactory::CreateQueen(colorToMove, move.end));
                        break;
                }
            }
            moveDialog.SetMove(moveString);
            validMoveIsGiven = true;
            continue;
        }
    }

    return 0;
}