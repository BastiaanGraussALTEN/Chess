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
            if (moveParser.IsStringValid(moveString))
            {
                Move move = moveParser.ParseString(moveString);
                if (legalityChecker.CheckMoveLegality(move))
                {
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

            moveDialog.ShowErrorText();
        }
    }

    return 0;
}