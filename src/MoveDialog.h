#ifndef MOVEDIALOG_H
#define MOVEDIALOG_H

#include <iostream>
#include <vector>

class MoveDialog
{
    private:
        int m_moveNumber;
        std::vector<std::string> m_moveHistory;
    public:
        MoveDialog();
        void SetMove(std::string move);
        std::string GetDialog();
        std::string GetMoveHistory();
};

#endif