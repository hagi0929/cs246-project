#include "piece.h"

#include "eye.h"

using namespace std;

Piece::Piece(Coor coor, int player)
    : coor{coor}, player{player}, moveCount{0} {}

Piece::Piece(Piece &&other)
    : coor{move(other.coor)},
      player{other.player},
      moveCount{other.moveCount} {}

Coor Piece::getCoor() const { return coor; }

int Piece::getPlayer() const { return player; }

int Piece::getMoveCount() const { return moveCount; }
