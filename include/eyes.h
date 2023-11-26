#ifndef EYES_H
#define EYES_H
#include <iostream>
#include <memory>

class GameBoard;

class Eyes {
  std::shared_ptr<GameBoard> board;
 public:
  Eyes(std::shared_ptr<GameBoard> board);
  bool isOccupied() const;
  bool isOpponent() const;
};

#endif
