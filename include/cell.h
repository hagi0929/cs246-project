#ifndef CELL_H
#define CELL_H
#include <iostream>
#include <memory>
#include <vector>

#include "bishop.h"
#include "display.h"
#include "king.h"
#include "knight.h"
#include "observer.h"
#include "pawn.h"
#include "piece.h"
#include "queen.h"
#include "rook.h"
#include "subject.h"

class Piece;

class Cell : public Subject {
  std::shared_ptr<Piece> piece;
  std::pair<int, int> coor;

 public:
  Cell(std::pair<int, int> coor);
  ~Cell();
  std::shared_ptr<Piece> getPiece();
  void setPiece(std::shared_ptr<Piece> p);
  int getRow() const;
  int getCol() const;
  bool isEmpty();
  void removePiece();
  void notifyObservers();
};

#endif
