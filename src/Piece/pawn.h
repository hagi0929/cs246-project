#ifndef PAWN_H
#define PAWN_H
#include "piece.h"
using namespace std;

class Pawn : public Piece {
 public:
  Pawn(int team, int moveCount);
  PieceType getType() const override;
  vector<Coor> possibleMoves(Coor c) const override;
};

#endif
