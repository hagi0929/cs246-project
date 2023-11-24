#ifndef QUEEN_H
#define QUEEN_H
#include "piece.h"
using namespace std;

class Queen : public Piece {
 public:
  Queen(int team, int moveCount);
  char getChar() const override;
  PieceType getType() const override;
  vector<Coor> possibleMoves(Coor c) const override;
};

#endif
