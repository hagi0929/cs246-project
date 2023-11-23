#ifndef ROOK_H
#define ROOK_H
#include "piece.h"
using namespace std;
class Rook : public Piece {
 public:
  Rook(int team, int moveCount);
  PieceType getType() const override;
  vector<Coor> possibleMoves(Coor c) const override;
};
