#ifndef PAWN_H
#define PAWN_H
#include "piece.h"
using namespace std;

class Pawn : public Piece {
 public:
  Pawn(int team, int moveCount);
  char getChar() const override;
  PieceType getType() const override;
  vector<Coor> possibleMoves(Coor c) const override;
};

#endif
