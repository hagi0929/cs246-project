#include "pawn.h"

using namespace std;

Pawn::Pawn(Coor coor, int player, int moveCount)
    : Piece{coor, player, moveCount} {}
Pawn::Pawn(Piece* other) : Piece{other} {}
Pawn::Pawn(Pawn& other)
    : Piece{other.coor, other.player, other.moveCount, other.jumped} {}
vector<Move> Pawn::possibleMoves(Snapshot& snapshot, bool safetyCheck) const {
  vector<Move> validMoves = vector<Move>{};
  int direction = player == 0 ? -1 : 1;
  // normal move
  vector<Coor> coorCandidates = vector<Coor>{};
  if (snapshot.isEmpty(getCoor() + Coor{direction, 0})) {
    coorCandidates.emplace_back(getCoor() + Coor{direction, 0});
    if (moveCount == 0 &&
        snapshot.isEmpty(getCoor() + Coor{direction * 2, 0})) {
      coorCandidates.emplace_back(getCoor() + Coor{direction * 2, 0});
    }
  }
  // attack move
  for (int i = -1; i <= 1; i += 2) {
    if (snapshot.isEnemy(getCoor() + Coor{direction, i}, player)) {
      coorCandidates.emplace_back(getCoor() + Coor{direction, i});
    }
  }
  for (auto c : coorCandidates) {
    if (!c.isInbound()) continue;
    if (c.getRow() == (player == 0 ? 7 : 0)) {
      validMoves.emplace_back(Move{getCoor(), c, player == 0 ? 'Q' : 'q'});
      validMoves.emplace_back(Move{getCoor(), c, player == 0 ? 'R' : 'r'});
      validMoves.emplace_back(Move{getCoor(), c, player == 0 ? 'B' : 'b'});
      validMoves.emplace_back(Move{getCoor(), c, player == 0 ? 'K' : 'k'});
    } else {
      validMoves.emplace_back(Move{getCoor(), c, 0});
    }
  }
  // en passant
  for (int i = -1; i <= 1; i += 2) {
    Coor side = getCoor() + Coor{0, i};
    if (snapshot.isEnemy(side, player) && snapshot.canEnPassent(side) &&
        snapshot.isEmpty(getCoor() + Coor{direction, i})) {
      validMoves.emplace_back(
          Move{getCoor(), getCoor() + Coor{direction, i}, side});
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

shared_ptr<Piece> Pawn::clone() { return make_shared<Pawn>(this); }

char Pawn::getType() const { return player == 0 ? 'P' : 'p'; }

void Pawn::setCoor(Coor newCoor) {
  if (getCoor() + Coor{player == 0 ? -2 : 2, 0} == newCoor) {
    jumped = true;
  }
  Piece::setCoor(newCoor);
}

int Pawn::getValue() const { return 1; }