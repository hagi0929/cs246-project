#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <memory>
#include "cell.h"
#include "coor.h"
#include "gamelog.h"
#include "player.h"

using namespace std;

const int BOARD_SIZE = 8;

class GameBoard {
  Cell board[BOARD_SIZE][BOARD_SIZE];
  GameLog log;
  int thisTurn;
  bool playerColors[2];

 public:
  GameBoard();
  ~GameBoard();
  bool isValidMove(Move &t) const;
  bool move(Coor c1, Coor c2);
  void addPiece(Piece &p, Coor c);
  void removePiece(Coor c);
  void setBeginPlayer(int player);
  void undo(int moves);
  void redo(int moves);
  int getThisTurn() const;
};
#endif