#ifndef BISHOP_H
#define BISHOP_H
#include "piece.h"
#include <vector>

class Bishop : public Piece
{
public:
  Bishop(std::pair<int, int> coor, int player, std::shared_ptr<Eyes> eyes);
  std::vector<std::shared_ptr<Move>> possibleMoves(bool checkSafety) const override;
  char getType() const override;
};

#endif
