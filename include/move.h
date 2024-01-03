#ifndef MOVE_H
#define MOVE_H

#include <memory>
#include <ostream>
#include <vector>

#include "coor.h"
#include "observer.h"
class Piece;

enum class MoveType {
  MOVE,
  CASTLING,
  ENPASSANT,
};
class Move {
  char pieceType;
  MoveType type;
  std::vector<Coor> coords = std::vector<Coor>{}; // from, to , (enPassant or (rookFrom, rookTo))

 public:
  Move(Coor from, Coor to);                              // Move
  Move(Coor from, Coor to, char pieceType);              // Promotion
  Move(Coor from, Coor to, Coor enPassant);              // EnPassant
  Move(Coor from, Coor to, Coor rookFrom, Coor rookTo);  // Castling
  bool equals(Coor from, Coor to, char promote);
  void execute(std::vector<std::shared_ptr<Piece>> &pieces);
  void notify(std::shared_ptr<Observer> o);
  friend std::ostream &operator<<(std::ostream &out, const Move &m);
};

#endif