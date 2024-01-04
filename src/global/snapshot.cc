#include "snapshot.h"

using namespace std;

Snapshot::Snapshot(vector<shared_ptr<Piece>> rcvPieces, int turn)
    : pieces{vector<shared_ptr<Piece>>{}}, checked{false, false}, turn{turn} {
  for (auto& piece : rcvPieces) {
    pieces.emplace_back(piece->clone());
  }
  cout << "Snapshot created" << endl;
  checked[0] = calculateCheck(0);
  checked[1] = calculateCheck(1);
}

bool Snapshot::calculateCheck(int playerNum) {
  std::shared_ptr<Piece> king = getKing(playerNum);
  for (auto piece : getPieces((1 + playerNum) % 2)) {
    for (auto move : piece->possibleMoves(*this, false)) {
      if (move.getTo() == king->getCoor()) {
        return true;
      }
    }
  }
  return false;
}

std::shared_ptr<Piece> Snapshot::getKing(int playerNum) {
  for (auto piece : pieces) {
    if ((piece->getType() == 'k' || piece->getType() == 'K') &&
        piece->getPlayer() == playerNum) {
      return piece;
    }
  }
}

bool Snapshot::isStalemate() {
  for (auto& piece : getPieces(turn)) {
    for (auto& move : piece->possibleMoves(*this)) {
      if (!simulateMove(move)->isChecked(turn)) {
        return false;
      }
    }
  }
  return true;
}

vector<shared_ptr<Piece>> Snapshot::getPieces(int playerNum) {
  vector<std::shared_ptr<Piece>> playerPieces;
  for (auto& piece : pieces) {
    if (piece->getPlayer() == playerNum) {
      playerPieces.emplace_back(piece);
    }
  }
  return playerPieces;
}

shared_ptr<Piece> Snapshot::getPiece(Coor coor) {
  for (auto& piece : pieces) {
    if (piece->getCoor() == coor) {
      return piece;
    }
  }
  return nullptr;
}

bool Snapshot::isChecked(int playerNum) { return checked[playerNum]; }

shared_ptr<Snapshot> Snapshot::simulateMove(Move move) const {
  vector<shared_ptr<Piece>> newPieces;
  for (auto& piece : pieces) {
    newPieces.emplace_back(piece->clone());
  }
  move.execute(newPieces);
  return make_shared<Snapshot>(newPieces, (turn + 1) % 2);
}

bool Snapshot::isCheckmate(int playerNum) {
  if (!checked[playerNum]) {
    return false;
  }
  for (auto& piece : getPieces(playerNum)) {
    for (auto& move : piece->possibleMoves(*this)) {
      if (!simulateMove(move)->isChecked(playerNum)) {
        return false;
      }
    }
  }
  return true;
}