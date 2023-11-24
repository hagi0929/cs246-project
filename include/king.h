#ifndef KING_H
#define KING_H
#include "piece.h"

using namespace std;
class King : public Piece {
 public:
  King(int team, int moveCount);
  char getChar() const override;
  PieceType getType() const override;
  vector<Coor> possibleMoves(Coor c) const override;
};

#endif
