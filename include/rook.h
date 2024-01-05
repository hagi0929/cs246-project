#ifndef ROOK_H
#define ROOK_H

#include "snapshot.h"
#include "piece.h"

class Rook : public Piece {
 public:
  Rook(Coor coor, int player, int moveCount = 0);
  Rook(Piece* other);
  Rook(Rook& other);
  
  std::vector<Move> possibleMoves(Snapshot& eye,
                                  bool safetyCheck = true) const override;
  std::shared_ptr<Piece> clone() override;
  char getType() const override;
};

#endif