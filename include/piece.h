#ifndef PIECE_H
#define PIECE_H
#include <iostream>
#include <memory>
#include <string>
#include <vector>

#include "eyes.h"
#include "move.h"

enum class Color { White, Black };

class InvalidMove {};

class Piece {
 protected:
  int player;
  int moveCount;
  std::shared_ptr<Eyes> eyes;
  std::pair<int, int> coor;

 public:
  Piece(std::pair<int, int> coor, int player, std::shared_ptr<Eyes> eyes);
  virtual std::vector<std::shared_ptr<Move>> possibleMoves() const = 0;
  int getPlayer() const;
  virtual char getType() const = 0;
};

#endif
