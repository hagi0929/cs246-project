#ifndef CELL_H
#define CELL_H
#include "../Piece/piece.h"

class Cell {
  Piece *piece;
  friend class GameBoard;
  Piece getPiece();
  bool isEmpty();
  void setPiece(Piece *p);
  void removePiece();
};

#endif