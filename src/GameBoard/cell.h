#include "../Piece/piece.h"

class Cell {
  Piece *piece;
  friend class GameBoard;
  Piece getPiece();
  bool isEmpty();
  void setPiece(Piece *p);
  void removePiece();
}