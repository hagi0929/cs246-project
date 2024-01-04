#include "gameboard.h"

#include <iostream>

#include "coor.h"
#include "king.h"
#include "piece.h"

using namespace std;

Gameboard::Gameboard()
    : pieces{vector<shared_ptr<Piece>>{}},
      observers{vector<shared_ptr<Observer>>{}},
      thisTurn{0} {}

void Gameboard::attach(shared_ptr<Observer> o) { observers.emplace_back(o); }

bool Gameboard::isEmpty(Coor c) {
  for (auto p : pieces) {
    if (p->getCoor() == c) {
      return false;
    }
  }
  return true;
}

void Gameboard::executeMove(Move &m) {
  m.execute(pieces);
  for (auto o : observers) {
    m.notify(o);
  }
  thisTurn = (thisTurn + 1) % 2;
  updateGameStatus();
}

void Gameboard::updateGameStatus() {
  // check if king is there
  bool p0king = false;
  bool p1king = false;
  for (auto p : pieces) {
    if (p->getType() == 'K') {
      p0king = true;
    } else if (p->getType() == 'k') {
      p1king = true;
    }
  }
  if (!p0king || !p1king) {
    gameStatus = GameStatus::ERR;
  }

  // check stallmate checkmate draw
  shared_ptr<Snapshot> s = getSnapshot();
  if (s->isCheckmate(0)) {
    gameStatus = GameStatus::WHITE_WIN;
  } else if (s->isCheckmate(1)) {
    gameStatus = GameStatus::BLACK_WIN;
  } else if (s->isStalemate()) {
    gameStatus = GameStatus::STALEMATE;
  } else {
    gameStatus = GameStatus::ONGOING;
  }
}

void Gameboard::movePiece(Coor from, Coor to, char promote) {
  if (isEmpty(from)) {
    cout << "No piece at " << from.getCol() << from.getRow() << endl;
    throw runtime_error("No piece at ");
  }
  int counter = 0;
  vector<Move> validMoves = getPiece(from)->possibleMoves(*getSnapshot());
  for (auto m : validMoves) {
    cout << m << endl;
    if (m.equals(from, to, promote)) {
      executeMove(m);
    }
  }
  if (counter == 0) {
    cout << "Invalid move";
  };
  if (counter > 1) {
    for (auto m : validMoves) {
      cout << m << endl;
    }
    cout << "Ambiguous move";
  }
}

void Gameboard::addPiece(Coor c, char type) {
  removePiece(c);
  switch (type) {
    case 'P':
      // pieces.emplace_back(make_shared<Pawn>(c, 0));
      break;
    case 'R':
      // pieces.emplace_back(make_shared<Rook>(c, 0));
      break;
    case 'N':
      // pieces.emplace_back(make_shared<Knight>(c, 0));
      break;
    case 'B':
      // pieces.emplace_back(make_shared<Bishop>(c, 0));
      break;
    case 'Q':
      // pieces.emplace_back(make_shared<Queen>(c, 0));
      break;
    case 'K':
      pieces.emplace_back(make_shared<King>(c, 0));
      break;
    case 'p':
      // pieces.emplace_back(make_shared<Pawn>(c, 1));
      break;
    case 'r':
      // pieces.emplace_back(make_shared<Rook>(c, 1));
      break;
    case 'n':
      // pieces.emplace_back(make_shared<Knight>(c, 1));
      break;
    case 'b':
      // pieces.emplace_back(make_shared<Bishop>(c, 1));
      break;
    case 'q':
      // pieces.emplace_back(make_shared<Queen>(c, 1));
      break;
    case 'k':
      pieces.emplace_back(make_shared<King>(c, 1));
      break;
    default:
      break;
  }
  for (auto o : observers) {
    o->notifyAdd(c, type);
  }
}

void Gameboard::removePiece(Coor c) {
  for (auto it = pieces.begin(); it != pieces.end(); ++it) {
    if ((*it)->getCoor() == c) {
      pieces.erase(it);
      return;
    }
  }
  for (auto o : observers) {
    o->notifyRemove(c);
  }
}

void Gameboard::setTurn(int turn) { thisTurn = turn; }

int Gameboard::getThisTurn() const { return thisTurn; }

shared_ptr<Snapshot> Gameboard::getSnapshot() const {
  return make_shared<Snapshot>(pieces, thisTurn);
}

shared_ptr<Piece> Gameboard::getPiece(Coor c) const {
  for (auto p : pieces) {
    if (p->getCoor() == c) {
      return p;
    }
  }
  return nullptr;
}
