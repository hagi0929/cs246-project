#ifndef QUEEN_H
#define QUEEN_H
#include "piece.h"

class Queen : public Piece {
 public:
  std::vector<std::shared_ptr<Move>> possibleMoves() const override;
  char getType() const override;
};

#endif
