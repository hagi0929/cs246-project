#ifndef ROOK_H
#define ROOK_H
#include "piece.h"
using namespace std;
class Rook : public Piece {
 public:
  Rook(int team, int moveCount);
  char getChar() const override;
  PieceType getType() const override;
  vector<Coor> possibleMoves(Coor c) const override;
};
