#ifndef PIECE_H
#define PIECE_H
#include <vector>
#include <iostream>
#include <memory>
#include <string>
#include "move.h"
#include "eyes.h"
#include "cell.h"

enum class Color { White, Black };

class InvalidMove {};

class Piece {
 protected:
  Color color;
  int row, col, moveCount;
  std::shared_ptr<Eyes> eyes;

 public:
  Piece(Color color, int row, int col, int moveCount, std::shared_ptr<Eyes> eyes);
  virtual std::vector<std::shared_ptr<Move>> possibleMoves() const = 0;
  Color getColor() const;
  virtual char getType() const = 0;
};

#endif
