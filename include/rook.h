#ifndef ROOK_H
#define ROOK_H
#include "piece.h"

class Rook : public Piece
{
public:
  Rook(std::pair<int, int> coor, int player, std::shared_ptr<Eyes> eyes);
  std::vector<std::shared_ptr<Move>> possibleMoves() const override;
  char getType() const override;
};

#endif
