#include "rook.h"
#include "piece.h"
#include "snapshot.h"

using namespace std;

Rook::Rook(Coor coor, int player, int moveCount)
    : Piece(coor, player, moveCount) {}

Rook::Rook(Piece* other) : Piece(other) {}

Rook::Rook(Rook& other)
    : Piece(other.getCoor(), other.getPlayer(), other.getMoveCount()) {}

vector<Move> Rook::possibleMoves(Snapshot& snapshot, bool safetyCheck) const {
  vector<Move> validMoves;
  vector<Coor> directions = {Coor(0, 1), Coor(0, -1), Coor(1, 0), Coor(-1, 0)};
  for (Coor direction : directions) {
    for (Coor nextCoor = this->coor + direction;
         snapshot.isEmpty(nextCoor) || snapshot.isEnemy(nextCoor, player);
         nextCoor = nextCoor + direction) {
      validMoves.emplace_back(Move{getCoor(), nextCoor});
    }
  }
  if (safetyCheck) {
    vector<Move> finalMoves = vector<Move>{};
    cout << "king valid moves: " << validMoves.size() << endl;

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

shared_ptr<Piece> Rook::clone() {
  return make_shared<Rook>(this->coor, this->player, this->moveCount);
}

char Rook::getType() const {
  return 'R';  // 'R' for Rook
}