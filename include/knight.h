#ifndef KNIGHT_H
#define KNIGHT_H
#include "piece.h"
using namespace std;

class Knight : public Piece {
 public:
  Knight(int team, int moveCount);
  char getChar() const override;
  PieceType getType() const override;
  vector<Coor> possibleMoves(Coor c) const override;
};

#endif
