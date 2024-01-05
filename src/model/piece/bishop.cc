#include "bishop.h"

#include "piece.h"
#include "snapshot.h"

using namespace std;

Bishop::Bishop(Coor coor, int player, int moveCount)
    : Piece(coor, player, moveCount) {}

Bishop::Bishop(Piece* other) : Piece(other) {}

Bishop::Bishop(Bishop& other)
    : Piece(other.getCoor(), other.getPlayer(), other.getMoveCount()) {}

vector<Move> Bishop::possibleMoves(Snapshot& snapshot, bool safetyCheck) const {
  vector<Move> validMoves;
  vector<Coor> directions = {Coor(1, 1), Coor(1, -1), Coor(-1, 1),
                             Coor(-1, -1)};
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

shared_ptr<Piece> Bishop::clone() {
  return make_shared<Bishop>(this->coor, this->player, this->moveCount);
}

char Bishop::getType() const {
  return 'B';  // 'B' for Bishop
}

int Bishop::getValue() const {
  return 3;
}