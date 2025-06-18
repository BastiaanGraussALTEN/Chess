#include "Move.h"

class MoveParser
{
    public: 
        bool IsStringValid(const std::string& moveString) const;
        Move ParseString(const std::string& moveString) const;
};