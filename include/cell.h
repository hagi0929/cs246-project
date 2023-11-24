#ifndef CELL_H
#define CELL_H
#include <memory>

#include "observer.h"
#include "piece.h"
#include "coor.h"

using namespace std;

const int observerCount = 2;

class Cell {
  shared_ptr<Piece> piece;
  unique_ptr<Observer> observers[observerCount];
  Coor coor;
 public:
  Cell(Coor coor);
  shared_ptr<Piece> getPiece();
  void setPiece(shared_ptr<Piece> p);
  void attach(unique_ptr<Observer> ob);
  void detach(unique_ptr<Observer> ob);
  int getRow() const;
  int getCol() const;
  bool isEmpty();
  void removePiece();
  void notifyDisplay();
};

#endif
