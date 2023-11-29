#include "eyes.h"

#include "cell.h"
#include "gameboard.h"
using namespace std;

Eyes::Eyes(weak_ptr<GameBoard> board) : board{board} {}

bool Eyes::isOccupied(pair<int, int> coor) const
{
  return !(board.lock()->getCell(coor)->isEmpty());
}

bool Eyes::isOpponent(pair<int, int> coor) const
{
  return board.lock()->getThisTurn() !=
         board.lock()->getCell(coor)->getPiece()->getPlayer();
}

