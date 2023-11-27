#ifndef EYES_H
#define EYES_H
#include <iostream>
#include <memory>

class GameBoard;
class Cell;
enum class Color;

class Eyes {
  std::shared_ptr<GameBoard> board;
  Color callerColor;
 public:
  Eyes(std::shared_ptr<GameBoard> board, Color callerColor);
  bool isOccupied(Cell &c) const;
  bool isOpponent(Cell &c) const;
};

#endif
