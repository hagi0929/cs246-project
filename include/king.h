#ifndef KING_H
#define KING_H
#include "piece.h"

class King : public Piece {
 public:
  std::vector<std::shared_ptr<Move>> possibleMoves() const override;
  char getType() const override;
};

#endif
