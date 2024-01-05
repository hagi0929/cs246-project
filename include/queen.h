#ifndef QUEEN_H
#define QUEEN_H

#include "snapshot.h"
#include "piece.h"

class Queen : public Piece {
 public:
  Queen(Coor coor, int player, int moveCount = 0);
  Queen(Piece* other);
  Queen(Queen& other);
  
  std::vector<Move> possibleMoves(Snapshot& eye,
                                  bool safetyCheck = true) const override;
  std::shared_ptr<Piece> clone() override;
  char getType() const override;
  int getValue() const override;
};

#endif