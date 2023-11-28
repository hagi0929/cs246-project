#ifndef QUEEN_H
#define QUEEN_H
#include "piece.h"

class Queen : public Piece {
 public:
  Queen(std::pair<int, int> coor, int player, std::shared_ptr<Eyes> eyes);
  std::vector<std::shared_ptr<Move>> possibleMoves() const override;
  char getType() const override;
};

#endif
