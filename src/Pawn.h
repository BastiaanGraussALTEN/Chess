#ifndef PAWN_H
#define PAWN_H

#include "Piece.h"

class Pawn : public Piece
{
    public:
    explicit Pawn(Color color, Square position);
    ~Pawn() override;
    std::shared_ptr<Piece> clone() const override {return std::make_shared<Pawn>(*this);}
    std::vector<Square> GetPossibleMoves() const;
};
    
#endif