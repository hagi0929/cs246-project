#include "king.h"

#include "eye.h"
using namespace std;

King::King(Coor coor, int player) : Piece{coor, player} {}
King::King(Piece&& other) : Piece{move(other)} {}
King::King(Piece& other) : Piece{other} {}

vector<Move> King::possibleMoves(Eye& eye, bool safetyCheck) const {
  vector<Move> validMoves;
  shared_ptr<Piece> capturedPiece = nullptr;
  for (int i = -1; i <= 1; ++i) {
    for (int j = -1; j <= 1; ++j) {
      Coor to = getCoor() + Coor{i, j};
      if (to.isInbound()) {
        if (safetyCheck) {
          capturedPiece = eye.getPiece(to);
          Move moveCandidate = Move{getCoor(), to, capturedPiece};
          if (safetyCheck) {
            auto simulation = eye.simulateMove(moveCandidate);
            simulation->isChecked(player);
          }
        }
      }
    }
    return validMoves;
  }
}

shared_ptr<Piece> King::clone() const { return make_shared<King>(*this); }

char King::getType() const { return 'k'; }
