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
  bool isOccupied(int row, int col) const;
  bool isOpponent(int row, int col) const;
};

#endif
