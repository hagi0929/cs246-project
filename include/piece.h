#ifndef PIECE_H
#define PIECE_H

#include <string>  // Add this line
#include <vector>

#include "coor.h"
#include "move.h"

class Eye;
class Piece {
 protected:
  Coor coor;
  int player;
  int moveCount;

 public:
  Piece(Coor coor, int player);
  Piece(Piece&& other);
  Piece(Piece& other);

  virtual char getType() const = 0;
  virtual std::vector<Move> possibleMoves(Eye& eye,
                                          bool safetyCheck = true) const = 0;
  virtual std::shared_ptr<Piece> clone() const = 0;
  Coor getCoor() const;
  int getPlayer() const;
  int getMoveCount() const;
  void setCoor(Coor newCoor);
};

#endif
