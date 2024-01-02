#include "eye.h"

using namespace std;
Eye::Eye(Gameboard& gameboard)
    : pieces{vector<shared_ptr<Piece>>{}},
      captured{vector<shared_ptr<Piece>>{}} {
  for (auto& piece : gameboard.getPieces()) {
    pieces.emplace_back(piece->clone());
  }
  for (auto& piece : gameboard.getCapturedPieces()) {
    pieces.emplace_back(piece->clone());
  }
  checked[0] = calculateCheck(0);
  checked[1] = calculateCheck(1);
  Stalemated = calculateStalemate();
}

Eye::Eye(vector<shared_ptr<Piece>> pieces, vector<shared_ptr<Piece>> captured)
    : pieces{vector<shared_ptr<Piece>>{}},
      captured{vector<shared_ptr<Piece>>{}},
{
  for (auto& piece : pieces) {
    pieces.emplace_back(piece->clone());
  }
  for (auto& piece : captured) {
    captured.emplace_back(piece->clone());
  }
  checked[0] = calculateCheck(0);
  checked[1] = calculateCheck(1);
  gameStatus = checkGamestatus();
}

GameStatus Eye::checkGamestatus() {
  if (checked[turn]) {
    for (auto& piece : getPieces(turn)) {
      for (auto& move : piece->possibleMoves()) {
        if (move.getFrom() != move.getTo()) {
          return GameStatus::Ongoing;
        }
      }
    }
    return GameStatus::Checkmate;
  } else if (calculateStalemate()) {
    return GameStatus::Stalemate;
  } else {
    return GameStatus::Ongoing;
  }
}

bool Eye::calculateCheck(int playerNum) {
  std::shared_ptr<Piece> king = getKing(playerNum);
  for (auto& piece : getPieces(1 - playerNum)) {
    for (auto& move : piece->possibleMoves(*this, false)) {
      if (move.getTo() == king->getCoor()) {
        return true;
      }
    }
  }
  return false;
}

std::shared_ptr<Piece> Eye::getKing(int playerNum) {
  for (auto& piece : pieces) {
    if (piece->getType() == 'k' && piece->getPlayer() == playerNum) {
      return piece;
    }
  }
  throw std::runtime_error("No king found");
}

bool Eye::calculateStalemate() {
  for (auto& piece : getPieces(turn)) {
    for (auto& move : piece->possibleMoves(*this)) {
      if (move.getFrom() != move.getTo()) {
        return false;
      }
    }
  }
  return true;
}

vector<shared_ptr<Piece>> Eye::getPieces(int playerNum) {
  vector<std::shared_ptr<Piece>> playerPieces;
  for (auto& piece : pieces) {
    if (piece->getPlayer() == playerNum) {
      playerPieces.emplace_back(piece);
    }
  }
  return playerPieces;
}

shared_ptr<Piece> Eye::getPiece(Coor coor) {
  for (auto& piece : pieces) {
    if (piece->getCoor() == coor) {
      return piece;
    }
  }
  return nullptr;
}

bool Eye::isChecked(int playerNum) { return checked[playerNum]; }

shared_ptr<Eye> Eye::simulateMove(Move move) const {
  newPieces = vector<shared_ptr<Piece>>{};
  newCaptured = vector<shared_ptr<Piece>>{};
  for (auto& piece : pieces) {
    if (piece->Coor == move.getFrom()) {
      shared_ptr<Piece> newPiece = piece->clone();
      newPiece.setCoor(move.getFrom());
      newPieces.emplace_back(newPiece);
    } else if (piece->Coor == move.getTo()) {
      newCaptured.emplace_back(piece.clone());
    } else {
      newPieces.emplace_back(piece.clone());
    }
  }
  for (auto& piece : captured) {
    newPieces.emplace_back(piece.clone());
  }
}