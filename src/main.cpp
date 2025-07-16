#include "../header/MoveDialog.h"
#include "../header/MoveParser.h"
#include "../header/CastleChecker.h"
#include "../header/CheckChecker.h"
#include "../header/BoardHistory.h"

int main()
{

    // debugging
    Board boardx;
    boardx.RemovePieceFromSquare(Square(5,7));
    boardx.AddPiece(PieceFactory::CreatePawn(Color::White, Square(5,7)));
    MoveParser moveParserx = MoveParser(boardx, Color::White);
    std::string moveString = "e7e8=R";
    Move movex = moveParserx.ParseString(moveString);
    // dedugging

    MoveDialog moveDialog;
    Board board;
    BoardHistory boardHistory;
    bool isGameEnded = false;
    while(!isGameEnded)
    {
        boardHistory.AddBoard(board);
        Color colorToMove = moveDialog.GetCurrentTurn();
        MoveParser moveParser(board, colorToMove);
        LegalityChecker legalityChecker = LegalityChecker(board);
        DangerChecker dangerChecker = DangerChecker(board, colorToMove);
        CastleChecker castleChecker = CastleChecker(board, colorToMove);
        CheckChecker checkChecker = CheckChecker(board, colorToMove);

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

        if (boardHistory.IsThreeFoldRepetition())
        {
            isGameEnded = true;
            moveDialog.ShowMoveHistory();
            moveDialog.ShowThreeFoldRepetition();
            continue;
        }

        if (!checkChecker.SufficientMaterialForCheckmate())
        {
            isGameEnded = true;
            moveDialog.ShowMoveHistory();
            moveDialog.ShowInsufficientMaterial();
            continue;
        }
        
        std::string moveString;
        bool validMoveIsGiven = false;

        while(!validMoveIsGiven)
        {
            moveDialog.ShowDialog();
            std::cin >> moveString;
            Move move = moveParser.ParseString(moveString);
            if (!move.isLegal)
            {
                moveDialog.ShowStringNotValid();
                continue;
            }
            
            if (move.isCastleKingside) 
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
            if (move.isCastleQueenside) 
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
                boardHistory.ClearHistory();
            }

            if (board.GetPieceFromSquare(move.start)->pieceType == PieceType::Pawn)
            {
                boardHistory.ClearHistory();
            }

            board.MovePiece(move);

            if (move.isPromotion)
            {
                board.RemovePieceFromSquare(move.end);
                switch (move.promotionPiece)
                {
                    case PieceType::Knight:
                        board.AddPiece(PieceFactory::CreateKnight(colorToMove, move.end));
                        break;
                    case PieceType::Bishop:
                        board.AddPiece(PieceFactory::CreateBishop(colorToMove, move.end));
                        break;
                    case PieceType::Rook:
                        board.AddPiece(PieceFactory::CreateRook(colorToMove, move.end));
                        break;
                    case PieceType::Queen:
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