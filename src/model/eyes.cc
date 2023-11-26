#include "eyes.h"
#include "gameboard.h"
using namespace std;

Eyes::Eyes(shared_ptr<GameBoard> board) : board{board} {
  cout << "Eyes ctor was called" << endl;
}

bool Eyes::isOccupied() const {
  cout << "isOccupied() was called" << endl;
  return true;
}

bool Eyes::isOpponent() const {
  cout << "isOpponent() was called" << endl;
  return true;
}
