#ifndef PIECE_H
#define PIECE_H
#include <vector>
#include <iostream>
#include <memory>
#include <string>
#include "move.h"
#include "eyes.h"

enum class Color { White, Black };

class Piece {
 protected:
  Color color;
  int row, col, moveCount;
  std::shared_ptr<Eyes> eyes;

 private:
  Color getColor() const;
  virtual std::vector<std::unique_ptr<Move>> possibleMoves() const = 0;

 public:
  Piece(Color color, int row, int col, int moveCount, std::shared_ptr<Eyes> eyes);
  virtual void movePiece(Move &m) = 0;
  virtual char getType() const = 0;
};

#endif
