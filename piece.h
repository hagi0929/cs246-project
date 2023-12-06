#ifndef PIECE_H
#define PIECE_H
#include <iostream>
#include <memory>
#include <string>
#include <vector>

#include "eyes.h"
#include "move.h"

enum class Color
{
  White,
  Black
};

class Piece
{
protected:
  int player;
  int moveCount;
  std::shared_ptr<Eyes> eyes;
  std::pair<int, int> coor;

public:
  Piece(std::pair<int, int> coor, int player, std::shared_ptr<Eyes> eyes);
  virtual std::vector<std::shared_ptr<Move>> possibleMoves(bool checkSafety) const = 0;
  int getPlayer() const;
  std::pair<int, int> getCoor() const;
  void setCoor(std::pair<int, int> c);
  virtual char getType() const = 0;
  void addMove();
  void subtractMove();
  int getMoveCount() const;
  void setMoveCount(int count);
};

#endif
