#ifndef CELL_H
#define CELL_H
#include <memory>
#include <vector>
#include <iostream>
#include "piece.h"
#include "rook.h"
#include "bishop.h"
#include "king.h"
#include "pawn.h"
#include "queen.h"
#include "knight.h"
#include "subject.h"
#include "observer.h"
#include "display.h"

class Piece;

class Cell : public Subject
{
  std::shared_ptr<Piece> piece;
  int row, col;

public:
  Cell(int row, int col);
  ~Cell();
  std::shared_ptr<Piece> getPiece();
  void setPiece(std::shared_ptr<Piece>);
  int getRow() const;
  int getCol() const;
  bool isEmpty();
  void removePiece();
  void notifyObservers();
};

#endif
