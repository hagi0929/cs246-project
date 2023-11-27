#ifndef PAWN_H
#define PAWN_H
#include "piece.h"

class Pawn : public Piece {
 public:
  std::vector<std::shared_ptr<Move>> possibleMoves() const override;
  char getType() const override;
};

#endif
