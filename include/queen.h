#ifndef QUEEN_H
#define QUEEN_H
#include "piece.h"
using namespace std;

class Queen : public Piece {
 public:
  Queen(int team, int moveCount);
  PieceType getType() const override;
  vector<Coor> possibleMoves(Coor c) const override;
};

#endif
