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
        std::string moveString;
        bool validMoveIsGiven = false;
        Color colorToMove = moveDialog.GetCurrentTurn();
        CheckChecker checkChecker = CheckChecker(board, colorToMove);
        if (checkChecker.IsCheckMate())
        {
            isCheckMate = true;
            continue;
        }

        while(!validMoveIsGiven)
        {
            LegalityChecker legalityChecker = LegalityChecker(board);
            moveDialog.ShowDialog();
            std::cin >> moveString;
            if (!moveParser.IsStringValid(moveString))
            {
                moveDialog.ShowStringNotValid();
                continue;
            }

            Move move = moveParser.ParseString(moveString);
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

            DangerChecker dangerChecker = DangerChecker(board, legalityChecker, colorToMove);
            if (dangerChecker.IsKingUnderAttack())
            {
                if (!checkChecker.DoesMovePreventCheck(move))
                {
                    moveDialog.ShowDoesNotPreventCheck();
                    continue;
                }
            }
                
            if (legalityChecker.DoesMoveCapturePiece(move))
            {
                board.RemovePieceFromSquare(move.end);
            }

            board.MovePiece(move);
            moveDialog.SetMove(moveString);
            validMoveIsGiven = true;
            continue;
        }
    }

    moveDialog.ShowMoveHistory();
    moveDialog.ShowIsCheckMate();
    return 0;
}