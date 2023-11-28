#ifndef EYES_H
#define EYES_H
#include <iostream>
#include <memory>
#include <utility>

class GameBoard;
class Cell;
enum class Color;

class Eyes {
  std::weak_ptr<GameBoard> board;

 public:
  Eyes(std::weak_ptr<GameBoard> board);
  bool isOccupied(std::pair<int, int> coor) const;
  bool isOpponent(std::pair<int, int> coor) const;
};

#endif
