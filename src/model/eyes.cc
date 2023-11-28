#include "eyes.h"
#include "gameboard.h"
#include "cell.h"
using namespace std;

Eyes::Eyes(shared_ptr<GameBoard> board, Color callerColor) :
           board{board}, callerColor{callerColor} {
  cout << "Eyes ctor was called" << endl;
}

bool Eyes::isOccupied(int row, int col) const {
  cout << "isOccupied() was called" << endl;
  if (board->getCell(row, col)->isEmpty()) return false;
  return true;
}

bool Eyes::isOpponent(int row, int col) const {
  cout << "isOpponent() was called" << endl;
  if (isOccupied(row, col) && board->getCell(row, col)->getPiece()->getColor() == callerColor) return true;
  return false;
}
