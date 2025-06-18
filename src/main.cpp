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
        LegalityChecker legalityChecker = LegalityChecker(board);
        while(!validMoveIsGiven)
        {
            moveDialog.ShowDialog();
            std::cin >> moveString;
            if (moveParser.IsStringValid(moveString))
            {
                Move move = moveParser.ParseString(moveString);
                if (legalityChecker.CheckMoveLegality(move))
                {
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