#ifndef ROOK_H
#define ROOK_H
#include "piece.h"

class Rook : public Piece {
  std::vector<std::unique_ptr<Move>> possibleMoves() const override;
 public:
  char getType() const override;
  void movePiece(Move &m) override;
};

#endif
