#include "../GameBoard/gameboard.h"

class Player {
 GameBoard gameBoard;
 int score;
 public:
  virtual Turn getNextTurn() = 0;
  virtual int getScore() const = 0;
}