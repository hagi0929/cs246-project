#ifndef BISHOP_H
#define BISHOP_H
#include "piece.h"
#include <vector>

class Bishop : public Piece {
 public:
  std::vector<std::shared_ptr<Move>> possibleMoves() const override;
  char getType() const override;
};

#endif
