#include "move.h"

#include "king.h"
#include "piece.h"
using namespace std;

Move::Move(Coor from, Coor to) : pieceType{0}, type{MoveType::MOVE} {
  coords.emplace_back(from);
  coords.emplace_back(to);
}

Move::Move(Coor from, Coor to, char pieceType)
    : pieceType{pieceType}, type{MoveType::MOVE} {
  coords.emplace_back(from);
  coords.emplace_back(to);
}

Move::Move(Coor from, Coor to, Coor enPassant)
    : pieceType{0}, type{MoveType::ENPASSANT} {
  coords.emplace_back(from);
  coords.emplace_back(to);
  coords.emplace_back(enPassant);
}

Move::Move(Coor from, Coor to, Coor rookFrom, Coor rookTo)
    : pieceType{0}, type{MoveType::CASTLING} {
  coords.emplace_back(from);
  coords.emplace_back(to);
  coords.emplace_back(rookFrom);
  coords.emplace_back(rookTo);
}

bool Move::equals(Coor from, Coor to, char promote) {
  cout << "Move::equals" << endl;
  cout << "from: " << from << " == " << coords[0] << " is it same? "
       << (coords[0] == from ? "True" : "False") << endl;
  cout << "to: " << to << " == " << coords[1] << " is it same? "
       << (coords[1] == to ? "True" : "False") << endl;
  cout << "promote: " << promote << " == " << pieceType << " is it same? "
       << (pieceType == promote ? "True" : "False") << endl;
  return coords[0] == from && coords[1] == to && pieceType == promote;
}

void Move::execute(vector<shared_ptr<Piece>> &pieces) {
  for (auto p = pieces.begin(); p != pieces.end(); ++p) {
    if (p->get()->getCoor() == coords[0]) {
      p->get()->setCoor(coords[1]);
      if (pieceType == 'q' && pieceType == 'Q') {
        // p->reset(new Queen{p->get()});
      } else if (pieceType == 'r' && pieceType == 'R') {
        // p->reset(new Rook{p->get()});
      } else if (pieceType == 'b' && pieceType == 'B') {
        // p->reset(new Bishop{p->get()});
      } else if (pieceType == 'n' && pieceType == 'N') {
        // p->reset(new Knight{p->get()});
      }
    } else if (p->get()->getCoor() == coords[1]) {
      pieces.erase(p);
    }
  }
  if (type == MoveType::CASTLING) {
    for (auto p = pieces.begin(); p != pieces.end(); p++) {
      if (p->get()->getCoor() == coords[2]) {
        p->get()->setCoor(coords[3]);
      }
    }
  }
  if (type == MoveType::ENPASSANT) {
    for (auto p = pieces.begin(); p != pieces.end(); p++) {
      if (p->get()->getCoor() == coords[2]) {
        pieces.erase(p);
      }
    }
  }
}

Coor Move::getFrom() const { return coords[0]; }

Coor Move::getTo() const { return coords[1]; }

void Move::notify(shared_ptr<Observer> o) {
  if (type == MoveType::CASTLING) {
    o->notifyMove(coords[0], coords[1]);
    o->notifyMove(coords[2], coords[3]);
  } else if (type == MoveType::ENPASSANT) {
    o->notifyMove(coords[0], coords[1]);
    o->notifyRemove(coords[2]);
  } else {
    o->notifyMove(coords[0], coords[1]);
    if (pieceType != 0) {
      o->notifyAdd(coords[1], pieceType);
    }
  }
}

ostream &operator<<(ostream &out, const Move &m) {
  if (m.type == MoveType::CASTLING) {
    out << "Castling: king " << m.coords[0] << "->" << m.coords[1] << ", rook "
        << m.coords[2] << "->" << m.coords[3];
  } else if (m.type == MoveType::ENPASSANT) {
    out << "EnPassant: " << m.coords[0] << " " << m.coords[1] << " "
        << m.coords[2];
  } else {
    out << "Move: " << m.coords[0] << "->" << m.coords[1]
        << " promotion: " << m.pieceType;
  }
  return out;
}