#ifndef KNIGHT_H
#define KNIGHT_H

#include "snapshot.h"
#include "piece.h"

class Knight : public Piece {
 public:
  Knight(Coor coor, int player, int moveCount = 0);
  Knight(Piece* other);
  Knight(Knight& other);
  
  std::vector<Move> possibleMoves(Snapshot& eye,
                                  bool safetyCheck = true) const override;
  std::shared_ptr<Piece> clone() override;
  char getType() const override;
  int getValue() const override;
};

#endif