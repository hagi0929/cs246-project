#ifndef PAWN_H
#define PAWN_H
#include "piece.h"

class Pawn : public Piece {
  std::vector<std::unique_ptr<Move>> possibleMoves() const override;
 public:
  char getType() const override;
  void movePiece(Move &m) override;
};

#endif
