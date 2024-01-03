#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include "cell.h"
#include "coor.h"
#include "move.h"
#include "observer.h"

enum class GameStatus {
  ONGOING,
  WHITE_WIN,
  BLACK_WIN,
  STALEMATE,
  DRAW,
  ERR,
};

class Gameboard {
  std::vector<std::shared_ptr<Piece>> pieces;
  std::vector<std::shared_ptr<Observer>> observers;
  std::shared_ptr<Eye> eye;
  int thisTurn;
  GameStatus gameStatus;
  std::shared_ptr<Piece> getPiece(Coor);
  bool isEmpty(Coor);
  void executeMove(Move&);
  void updateGameStatus();
 public:
  Gameboard();
  void attach(std::shared_ptr<Observer>);
  void movePiece(Coor, Coor, char);
  void addPiece(Coor, char);
  void removePiece(Coor);
  void setTurn(int);
  int getThisTurn() const;
  std::shared_ptr<Snapshot> getSnapshot() const;
};

#endif