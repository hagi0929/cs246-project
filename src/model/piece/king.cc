#include "king.h"

#include "snapshot.h"
using namespace std;

King::King(Coor coor, int player) : Piece{coor, player} {}
King::King(Piece* other) : Piece{other} {}
vector<Move> King::possibleMoves(Snapshot& snapshot, bool safetyCheck) const {
  vector<Move> validMoves = vector<Move>{};
  for (int i = -1; i <= 1; ++i) {
    for (int j = -1; j <= 1; ++j) {
      Coor to = getCoor() + Coor{i, j};
      if (to.isInbound()) {
        if (safetyCheck) {
          Move moveCandidate = Move{getCoor(), to, 0};
          auto simulation = snapshot.simulateMove(moveCandidate);
          simulation->isChecked(player);
        } else {
          validMoves.emplace_back(getCoor(), to, 0);
        }
      }
    }
  }
  return validMoves;
}

shared_ptr<Piece> King::clone() const { return make_shared<King>(*this); }

char King::getType() const { return player == 0 ? 'K' : 'k'; }
