#ifndef KING_H
#define KING_H
#include "piece.h"

class King : public Piece
{
public:
  King(std::pair<int, int> coor, int player, std::shared_ptr<Eyes> eyes);
  std::vector<std::shared_ptr<Move>> possibleMoves() const override;
  char getType() const override;
};

#endif
