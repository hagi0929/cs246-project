#include "piece.h"

using namespace std;

Piece::Piece(Coor coor, int player, int moveCount)
    : coor{coor}, player{player}, moveCount{moveCount} {}
Piece::Piece(Coor coor, int player, int moveCount, bool jumped)
    : coor{coor}, player{player}, moveCount{moveCount}, jumped{jumped} {}
Piece::Piece(Piece* other)
    : coor{other->coor},
      player{other->player},
      moveCount{other->moveCount},
      jumped{other->jumped} {}
Coor Piece::getCoor() const { return coor; }

int Piece::getPlayer() const { return player; }

int Piece::getMoveCount() const { return moveCount; }

void Piece::setCoor(Coor newCoor) {
  moveCount++;
  coor = newCoor;
}

bool Piece::hasJumped() {
  if (tolower(getType()) == 'p') {
    return jumped;
  } else {
    return false;
  }
}