#include <iostream>
#include "MoveDialog.h"
#include "MoveParser.h"
#include "CastleChecker.h"
#include "CheckChecker.h"

int main()
{
    MoveDialog moveDialog;
    MoveParser moveParser;
    Board board;
    bool isCheckMate = false;
    while(!isCheckMate)
    {
        Color colorToMove = moveDialog.GetCurrentTurn();
        CheckChecker checkChecker = CheckChecker(board, colorToMove);
        if (checkChecker.IsCheckMate())
        {
            isCheckMate = true;
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
            LegalityChecker legalityChecker = LegalityChecker(board);
            if (move.promotionOrCastleside == PieceType::KingType) 
            {
                DangerChecker dangerChecker = DangerChecker(board, legalityChecker, colorToMove);
                CastleChecker castleChecker = CastleChecker(board, legalityChecker, dangerChecker, colorToMove);
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
                DangerChecker dangerChecker = DangerChecker(board, legalityChecker, colorToMove);
                CastleChecker castleChecker = CastleChecker(board, legalityChecker, dangerChecker, colorToMove);
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

            if ((board.GetPieceFromSquare(move.end)->pieceType == PieceType::PawnType) 
            && (((move.end.y == 1) && (board.GetPieceFromSquare(move.end)->color == Color::Black)) 
            || ((move.end.y == 8) && (board.GetPieceFromSquare(move.end)->color == Color::White))))
            {
                board.RemovePieceFromSquare(move.end);
                board.AddPiece(PieceFactory::CreateQueen(colorToMove, move.end));
            }
            moveDialog.SetMove(moveString);
            validMoveIsGiven = true;
            continue;
        }
    }

    moveDialog.ShowMoveHistory();
    moveDialog.ShowIsCheckMate();
    return 0;
}