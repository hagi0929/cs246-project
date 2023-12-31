#ifndef BISHOP_H
#define BISHOP_H

#include "snapshot.h"
#include "piece.h"

class Bishop : public Piece {
 public:
  Bishop(Coor coor, int player, int moveCount = 0);
  Bishop(Piece* other);
  Bishop(Bishop& other);
  
  std::vector<Move> possibleMoves(Snapshot& eye,
                                  bool safetyCheck = true) const override;
  std::shared_ptr<Piece> clone() override;
  char getType() const override;
};

#endif