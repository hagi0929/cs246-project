#ifndef KING_H
#define KING_H
#include "piece.h"

class King : public Piece {
  std::vector<std::unique_ptr<Move>> possibleMoves() const override;
 public:
  char getType() const override;
  void movePiece(Move &m) override;
};

#endif
