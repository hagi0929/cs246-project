#include "move.h"

Move::Move(Coor from, Coor to, std::shared_ptr<Piece> captured)
    : from{from}, to{to}, captured{captured} {}

Coor Move::getFrom() const { return from; }

Coor Move::getTo() const { return to; }

std::shared_ptr<Piece> Move::getCaptured() const { return captured; }
std::ostream& operator<<(std::ostream& out, const Move& move) {
  out << move.from << " -> " << move.to << " captured: " << move.captured;
  return out;
}

bool Move::operator==(const Move& other) const {
  return from == other.from && to == other.to &&
         captured.get() == other.captured.get();
}
