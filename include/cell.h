#ifndef CELL_H
#define CELL_H
#include <memory>

#include "observer.h"
#include "piece.h"
#include "coor.h"

using namespace std;

class Cell {
  shared_ptr<Piece> piece;
  Observer *observers[2];
  Coor coor;
 public:
  Cell();
  ~Cell();
  shared_ptr<Piece> getPiece();
  void setPiece(shared_ptr<Piece>);
  bool isEmpty();
  void removePiece();
  void notifyDisplay();
};

#endif
