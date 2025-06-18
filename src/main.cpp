#include <iostream>
#include "MoveDialog.h"
#include "MoveParser.h"
#include "CastleChecker.h"
#include "CheckChecker.h"

int main()
{
    std::string moveString;
    MoveDialog moveDialog;
    MoveParser moveParser;
    Board board;
    while(true)
    {
        bool validMoveIsGiven = false;
        while(!validMoveIsGiven)
        {

            moveDialog.ShowDialog();
            std::cin >> moveString;
            if (moveParser.IsStringValid(moveString))
            {
                Move move = moveParser.ParseString(moveString);
                board.MovePiece(move);
                moveDialog.SetMove(moveString);
                validMoveIsGiven = true;
            }
            else if(!moveParser.IsStringValid(moveString))
            {
                moveDialog.ShowErrorText();
            }
        }
    }

    return 0;
}