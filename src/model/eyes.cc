#include "eyes.h"

#include "cell.h"
#include "gameboard.h"
using namespace std;

Eyes::Eyes(weak_ptr<GameBoard> board) : board{board} {
  cout << "Eyes ctor was called" << endl;
}

bool Eyes::isOccupied(pair<int, int> coor) const {
  cout << "isOccupied() was called" << endl;
  return !(board.lock()->getCell(coor)->isEmpty());
}

bool Eyes::isOpponent(pair<int, int> coor) const {
  cout << "isOpponent() was called" << endl;
  return board.lock()->getThisTurn() !=
         board.lock()->getCell(coor)->getPiece()->getPlayer();
}
