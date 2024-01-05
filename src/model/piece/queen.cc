#include "queen.h"
#include "piece.h"
#include "snapshot.h"

using namespace std;

Queen::Queen(Coor coor, int player, int moveCount)
    : Piece(coor, player, moveCount) {}

Queen::Queen(Piece* other) : Piece(other) {}

Queen::Queen(Queen& other)
    : Piece(other.getCoor(), other.getPlayer(), other.getMoveCount()) {}

vector<Move> Queen::possibleMoves(Snapshot& snapshot, bool safetyCheck) const {
  vector<Move> validMoves;
  vector<Coor> directions = {Coor(0, 1),  Coor(0, -1), Coor(1, 0),
                             Coor(-1, 0), Coor(1, 1),  Coor(1, -1),
                             Coor(-1, 1), Coor(-1, -1)};
  for (Coor direction : directions) {
    for (Coor nextCoor = this->coor + direction;
         snapshot.isEmpty(nextCoor) || snapshot.isEnemy(nextCoor, player);
         nextCoor = nextCoor + direction) {
      validMoves.emplace_back(Move{getCoor(), nextCoor});
    }
  }
  if (safetyCheck) {
    vector<Move> finalMoves = vector<Move>{};
    for (Move m : validMoves) {
      if (!snapshot.simulateMove(m)->isChecked(player)) {
        finalMoves.emplace_back(m);
      }
    }
    return finalMoves;
  } else {
    return validMoves;
  }
}

shared_ptr<Piece> Queen::clone() {
  return make_shared<Queen>(this->coor, this->player, this->moveCount);
}

char Queen::getType() const {
  return 'Q';  // 'Q' for Queen
}

int Queen::getValue() const {
  return 9;
}