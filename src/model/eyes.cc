#include "eyes.h"
#include "gameboard.h"
#include "cell.h"
using namespace std;

Eyes::Eyes(shared_ptr<GameBoard> board, Color callerColor) :
           board{board}, callerColor{callerColor} {
  cout << "Eyes ctor was called" << endl;
}

bool Eyes::isOccupied(Cell &c) const {
  cout << "isOccupied() was called" << endl;
  if (board->getCell(c.getRow(), c.getCol())->isEmpty()) return false;
  return true;
}

bool Eyes::isOpponent(Cell &c) const {
  cout << "isOpponent() was called" << endl;
  if (isOccupied(c) && c.getPiece()->getColor() == callerColor) return true;
  return false;
}
