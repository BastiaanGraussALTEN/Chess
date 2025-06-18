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
    while(true)
    {
        std::string moveString;
        bool validMoveIsGiven = false;
        Color colorToMove = moveDialog.GetCurrentTurn();
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

    return 0;
}