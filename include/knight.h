#ifndef KNIGHT_H
#define KNIGHT_H
#include "piece.h"
using namespace std;

class Knight : public Piece {
 public:
  std::vector<std::shared_ptr<Move>> possibleMoves() const override;
  char getType() const override;
};

#endif
