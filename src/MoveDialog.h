#ifndef MOVEDIALOG_H
#define MOVEDIALOG_H

#include <iostream>

class MoveDialog
{
    private:
        int m_move_number;
    public:
        MoveDialog();
        void SetMove(std::string move);
        std::string GetDialog();
};

#endif