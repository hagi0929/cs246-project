#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include "cell.h"
#include "coor.h"
#include "observer.h"

class Gameboard {
  std::vector<std::shared_ptr<Piece>> pieces;
  std::vector<std::shared_ptr<Observer>> observer;

 public:
  Gameboard();
  Cell &getCell(int row, int col);
  // void setCell(int row, int col, Piece piece);
  void init();
  int getThisTurn();
  void createPiece(const Coor &coor, char pieceType);
  void removePiece(const Coor &coor);
  void movePiece(const Coor &from, const Coor &to, char promotion);
  void setThisTurn(int turn);
  void resign();
  std::vector<std::shared_ptr<Piece>> getPieces();
  std::vector<std::shared_ptr<Piece>> getCapturedPieces();
};

#endif