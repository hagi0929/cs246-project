#include "eyes.h"

#include "cell.h"
#include "gameboard.h"
#include "piece.h"
using namespace std;

const int NUM_PLAYERS = 2;

Eyes::Eyes(weak_ptr<GameBoard> board) : board{board}, isChecked{false}, isCheckmated{false}, isStalemate{false} {
  for (int i = 0; i < NUM_PLAYERS; ++i) {
    pieces.emplace_back();
  }
  for (int i = 0; i < BOARD_SIZE; ++i) {
    for (int j = 0; j < BOARD_SIZE; ++j) {
      if (board.lock()->getCell(make_pair(i, j))->getPiece()) {
        pieces[board.lock()->getCell(make_pair(i, j))->getPiece()->getPlayer()].emplace_back(board.lock()->getCell(make_pair(i, j))->getPiece());
      }
    }
  }
}

bool Eyes::isOccupied(pair<int, int> coor) const {
  return !(board.lock()->getCell(coor)->isEmpty());
}

bool Eyes::isOpponent(pair<int, int> coor) const {
  return board.lock()->getThisTurn() !=
         board.lock()->getCell(coor)->getPiece()->getPlayer();
}

bool Eyes::getIsChecked(int player) const {
  return isChecked[player];
}

bool Eyes::getIsCheckmated(int player) const {
  return isCheckmated[player];
}

bool Eyes::getIsStalemate() const {
  return isStalemate;
}

bool Eyes::checked(pair<int, int> kingCoor, int attacker) const {
  for (auto piece : pieces[attacker]) {
    vector<shared_ptr<Move>> attackerValidMoves = piece->possibleMoves();
    for (auto move : attackerValidMoves) {
      if (move->getDest() == kingCoor) {
        return true;
      }
    }
  }
  return false;
}

// *****IMPLEMENT UNDO THEN THIS*****
void Eyes::updateIsCheckmated(pair<int, int> kingCoor, int defender) {
  for (auto piece : pieces[defender]) {
    vector<shared_ptr<Move>> defenderValidMoves = piece->possibleMoves();
    for (auto move : defenderValidMoves) {
      
    }
  }
}

void Eyes::updateIsChecked(int attacker, int defender) {
  pair<int, int> kingCoor;
  for (auto piece : pieces[defender]) {
    if (piece->getType() == 'K' || piece->getType() == 'k') {
      kingCoor = piece->getCoor();
      break;
    }
  }

  if (checked(kingCoor, attacker)) {
    isChecked[defender] = true;
    updateIsCheckmated(kingCoor, defender);
  } else {
    isChecked[defender] = false;
  }
}

void Eyes::updateIsStalemate(int defender) {
  for (auto piece : pieces[defender]) {
    if (!piece->possibleMoves().empty()) {
      isStalemate = false;
      return;
    }
  }
  isStalemate = true;
}

void Eyes::updateState(int attacker, int defender) {
  updateIsChecked(attacker, defender);
  updateIsStalemate(defender);
}

void Eyes::removePiece(std::shared_ptr<Piece> p) {
  int player = p->getPlayer();
  for (auto it = pieces[player].begin(); it != pieces[player].end(); ++it) {
    if (*it == p) {
      pieces[player].erase(it);
      break;
    }
  }
}

