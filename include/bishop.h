#ifndef BISHOP_H
#define BISHOP_H
#include "piece.h"
#include <vector>
using namespace std;

class Bishop : public Piece {
 public:
  Bishop(int team, int moveCount);
  PieceType getType() const override;
  vector<Coor> possibleMoves(Coor c) const override;
};

#endif
