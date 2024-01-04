#include "piece.h"

using namespace std;

Piece::Piece(Coor coor, int player, int moveCount)
    : coor{coor}, player{player}, moveCount{moveCount} {}

Coor Piece::getCoor() const {
  return coor;
}

int Piece::getPlayer() const { return player; }

int Piece::getMoveCount() const { return moveCount; }

void Piece::setCoor(Coor newCoor) { coor = newCoor; }