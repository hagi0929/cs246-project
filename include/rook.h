#ifndef ROOK_H
#define ROOK_H
#include "piece.h"

class Rook : public Piece {
 public:
  std::vector<std::shared_ptr<Move>> possibleMoves() const override;
  char getType() const override;
};

#endif
