#ifndef KING_H
#define KING_H
#include "piece.h"

using namespace std;
class King : public Piece {
 public:
  King(int team, int moveCount);
  PieceType getType() const override;
  vector<Coor> possibleMoves(Coor c) const override;
};

#endif
