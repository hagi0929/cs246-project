#ifndef KNIGHT_H
#define KNIGHT_H
#include "piece.h"
using namespace std;

class Knight : public Piece {
  std::vector<std::unique_ptr<Move>> possibleMoves() const override;
 public:
  char getType() const override;
  void movePiece(Move &m) override;
};

#endif
