#include "king.h"

using namespace std;

King::King(Coor coor, int player, int moveCount)
    : Piece{coor, player, moveCount} {}
King::King(Piece* other) : Piece{other} {}
King::King(King& other) : Piece{other.coor, other.player, other.moveCount} {}
vector<Move> King::possibleMoves(Snapshot& snapshot, bool safetyCheck) const {
  vector<Move> validMoves = vector<Move>{};
  for (int i = -1; i <= 1; i++) {
    for (int j = -1; j <= 1; j++) {
      if (!i && !j) continue;
      Coor c = getCoor() + Coor{i, j};
      if (!c.isInbound()) continue;
      if (snapshot.isEmpty(c) || snapshot.isEnemy(c, player)) {
        validMoves.emplace_back(Move{getCoor(), c, 0});
      }
    }
  }
  if (safetyCheck) {
    vector<Move> finalMoves = vector<Move>{};
    cout << "king valid moves: " << validMoves.size() << endl;

    for (Move m : validMoves) {
      cout << m << endl;
      if (!snapshot.simulateMove(m)->isChecked(player)) {
        finalMoves.emplace_back(m);
      }
    }
    return finalMoves;
  } else {
    return validMoves;
  }
}

shared_ptr<Piece> King::clone() {
  return make_shared<King>(this->coor, this->player, this->moveCount);
}

char King::getType() const { return player == 0 ? 'K' : 'k'; }

int King::getValue() const { return 1000; }