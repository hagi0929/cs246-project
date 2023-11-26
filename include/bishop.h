#ifndef BISHOP_H
#define BISHOP_H
#include "piece.h"
#include <vector>

class Bishop : public Piece {
  std::vector<std::unique_ptr<Move>> possibleMoves() const override;
 public:
  char getType() const override;
  void movePiece(Move &m) override;
};

#endif
