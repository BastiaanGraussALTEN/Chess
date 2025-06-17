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
        moveDialog.ShowDialog();
        std::cin >> moveString;
        Move move = moveParser.ParseString(moveString);
        board.MovePiece(move);
        moveDialog.SetMove(moveString);
    }

    return 0;
}