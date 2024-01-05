#include "snapshot.h"

using namespace std;

Snapshot::Snapshot(vector<shared_ptr<Piece>> rcvPieces, int turn)
    : pieces{vector<shared_ptr<Piece>>{}}, checked{false, false}, turn{turn} {
  for (auto& piece : rcvPieces) {
    pieces.emplace_back(piece->clone());
  }
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
    newPieces.back()->getCoor();
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

bool Snapshot::isEmpty(Coor coor) {
  if (!coor.isInbound()) return false;
  for (auto& piece : pieces) {
    if (piece->getCoor() == coor) {
      return false;
    }
  }
  return true;
}

bool Snapshot::isEnemy(Coor coor, int player) {
  for (auto& piece : getPieces((player + 1) % 2)) {
    if (piece->getCoor() == coor) {
      return true;
    }
  }
  return false;
}

bool Snapshot::isAlley(Coor coor, int player) {
  for (auto& piece : getPieces(player)) {
    if (piece->getCoor() == coor) {
      return true;
    }
  }
  return false;
}

bool Snapshot::canEnPassent(Coor coor) {
  if (!coor.isInbound()) return false;
  auto piece = getPiece(coor);
  if (piece.get() && tolower(piece->getType()) == 'p' &&
      piece->getMoveCount() == 1 && piece->hasJumped()) {
    return true;
  }
  return false;
}

ostream& operator<<(ostream& out, const Snapshot& s) {
  out << "Snapshot: " << endl;
  for (auto& piece : s.pieces) {
    out << piece->getCoor() << " " << piece->getType() << " "
        << piece->getPlayer() << " " << piece->hasJumped() << endl;
  }
  return out;
}

bool Snapshot::isDraw() {
  if (isStalemate()) {
    return true;
  }
  if (pieces.size() == 2) {
    return true;
  }
  if (pieces.size() == 3) {
    for (auto& piece : pieces) {
      if (piece->getType() == 'B' || piece->getType() == 'b' ||
          piece->getType() == 'N' || piece->getType() == 'n') {
        return true;
      }
    }
  }
  return false;
}

int Snapshot::calculateScore(Move move, bool considerAll) {
  int score = 0;
  if (move.getPromotion() != ' ') {
    score += 9;
  }
  if (move.getFrom().isInbound() && move.getTo().isInbound()) {
    auto piece = getPiece(move.getTo());
    if (piece.get()) {
      score += piece->getValue();
    }
    if (considerAll) {
      piece = getPiece(move.getFrom());
      if (piece.get()) {
        score -= piece->getValue();
      }
    }
  }
  return score;
}