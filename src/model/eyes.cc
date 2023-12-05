#include "eyes.h"

#include "cell.h"
#include "gameboard.h"
#include "move.h"
#include "piece.h"
using namespace std;

const int NUM_PLAYERS = 2;

Eyes::Eyes(shared_ptr<GameBoard> board) : board{board}, isStalemate{false} {
  for (int i = 0; i < NUM_PLAYERS; ++i) {
    isChecked.emplace_back(false);
    isCheckmated.emplace_back(false);
  }
  pieces.resize(NUM_PLAYERS);
}

bool Eyes::isOccupied(pair<int, int> coor) const {
  return !(board->getCell(coor)->isEmpty());
}

bool Eyes::isOpponent(pair<int, int> coor) const {
  return board->getThisTurn() != board->getCell(coor)->getPiece()->getPlayer();
}

bool Eyes::getIsChecked(int player) const { return isChecked[player]; }

bool Eyes::getIsCheckmated(int player) const { return isCheckmated[player]; }

bool Eyes::getIsStalemate() const { return isStalemate; }

bool Eyes::checked(int attacker, int defender) const {
  // cout << "checked called " << board->getThisTurn() << endl;
  pair<int, int> kingCoor;

  for (auto piece : pieces[defender]) {
    if (piece->getType() == 'K' || piece->getType() == 'k') {
      kingCoor = piece->getCoor();
      // cout << "found king " << kingCoor.first << "," << kingCoor.second <<
      // endl;
      break;
    }
  }

  for (auto piece : pieces[attacker]) {
    // cout << "checking piece " << piece->getType() << endl;
    board->setTurn(attacker);
    vector<shared_ptr<Move>> attackerValidMoves = piece->possibleMoves(false);
    board->setTurn(defender);
    // cout << "found " << attackerValidMoves.size() << endl;
    for (auto move : attackerValidMoves) {
      // cout << "checking a move " << *move << endl;
      if (move->getDest() == kingCoor) {
        // cout << "found king in move" << endl;
        // cout << board->getThisTurn() << "'s turn returning true" <<endl;
        return true;
      }
    }
  }

  // cout << board->getThisTurn() << "'s turn returning false" <<endl;
  return false;
}

void Eyes::updateIsCheckmated(int attacker, int defender) {
  // cout << "checkmate called" << endl;
  for (auto piece : pieces[defender]) {
    vector<shared_ptr<Move>> defenderValidMoves = piece->possibleMoves(true);
    for (auto move : defenderValidMoves) {
      // cout << "updateIsCheckmated " << endl;

      board->doValidMove(move);
      // cout << "tried move " << *move << endl;
      // cout << board->getThisTurn() << "'s turn" <<endl;

      if (!checked(attacker, defender)) {
        isCheckmated[defender] = false;
        board->undo(false);
        board->setTurn(defender);
        // cout << board->getThisTurn() << "'s turn, boutta return" <<endl;
        return;
      }
      board->undo(false);
      board->setTurn(defender);
      // cout << board->getThisTurn() << "'s turn, didnt" <<endl;
    }
  }
  isCheckmated[defender] = true;
}

void Eyes::updateIsChecked(int attacker, int defender) {
  if (checked(attacker, defender)) {
    isChecked[defender] = true;
    updateIsCheckmated(attacker, defender);
  } else {
    isChecked[defender] = false;
  }
}

void Eyes::updateIsStalemate(int attacker, int defender) {
  if (pieces[attacker].size() == 1 && pieces[defender].size() == 1) {
    isStalemate = true;
    return;
  }
  if (!isChecked[defender]) {
    // cout << pieces[defender].size() << endl;
    for (auto piece : pieces[defender]) {
      if (!piece->possibleMoves(true).empty()) {
        isStalemate = false;
        return;
      }
    }
    isStalemate = true;
  } else {
    isStalemate = false;
  }
}

void Eyes::removePiece(shared_ptr<Piece> p) {
  int player = p->getPlayer();
  for (auto it = pieces[player].begin(); it != pieces[player].end(); ++it) {
    if (*it == p) {
      pieces[player].erase(it);
      break;
    }
  }
}

void Eyes::addPiece(shared_ptr<Piece> p) {
  int player = p->getPlayer();
  pieces[player].emplace_back(p);
}

void Eyes::updateState(int attacker, int defender) {
  updateIsChecked(attacker, defender);
  updateIsStalemate(attacker, defender);
}

bool Eyes::isSafeMove(shared_ptr<Move> m) {

  board->doValidMove(m);
  // cout << "tried move " << *m << " for " <<
  // board->getCell(m->getDest())->getPiece()->getType() << endl; cout <<
  // board->getThisTurn() << "'s turn" <<endl;
  int attacker =
      (board->getCell(m->getDest())->getPiece()->getPlayer() + 1) % 2;
  int defender = board->getCell(m->getDest())->getPiece()->getPlayer();
  // cout << board->getThisTurn() << "'s turn, returning false in safe" <<endl;
  if (!checked(attacker, defender)) {
    board->undo(false);
    board->setTurn(defender);
    //cout << board->getThisTurn() << "'s turn, returning true in safe" <<endl;
    return true;
  }
  board->undo(false);
  board->setTurn(defender);
  //cout << board->getThisTurn() << "'s turn, returning false in safe" <<endl;
  return false;
}

int Eyes::getThisTurn() const { return board->getThisTurn(); }

vector<shared_ptr<Piece>> Eyes::getPieces(int player) const {
  return pieces[player];
}

shared_ptr<GameBoard> Eyes::getBoard() { return board; }
