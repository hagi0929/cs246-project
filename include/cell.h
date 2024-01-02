#ifndef CELL_H
#define CELL_H

#include "cell.h"
#include "piece.h"
#include "coor.h"

class Cell {
  Coor coor;
  std::shared_ptr<Piece> piece = nullptr;

 public:
  Cell(Coor coor);
  Cell(Coor coor, std::shared_ptr<Piece> piece);
  Coor getCoor() const;
  std::shared_ptr<Piece> getPiece() const;
  void setPiece(std::shared_ptr<Piece> piece);
  void removePiece();
  friend std::ostream& operator<<(std::ostream& out, const Cell& cell);
};

#endif