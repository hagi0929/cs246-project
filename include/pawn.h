#ifndef PAWN_H
#define PAWN_H
#include "piece.h"

class Pawn : public Piece {
 public:
  Pawn(std::pair<int, int> coor, int player, std::shared_ptr<Eyes> eyes);
  std::vector<std::shared_ptr<Move>> possibleMoves() const override;
  char getType() const override;
};

#endif
