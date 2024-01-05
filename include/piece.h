#ifndef PIECE_H
#define PIECE_H

#include <string>  // Add this line
#include <vector>

#include "coor.h"
#include "move.h"

class Snapshot;
class Piece {
 protected:
  Coor coor;
  int player;
  int moveCount = 0;

  // FIXME temporary solution for enpassant
  bool jumped = false;

 public:
  Piece(Coor coor, int player, int moveCount = 0);
  Piece(Coor coor, int player, int moveCount, bool jumped);
  Piece(Piece* other);

  virtual ~Piece() = default;
  virtual char getType() const = 0;
  virtual std::vector<Move> possibleMoves(Snapshot& snapshot,
                                          bool safetyCheck = true) const = 0;
  virtual std::shared_ptr<Piece> clone() = 0;
  virtual int getValue() const = 0;

  Coor getCoor() const;
  int getPlayer() const;
  int getMoveCount() const;
  virtual void setCoor(Coor newCoor);
  bool hasJumped();
};

#endif
