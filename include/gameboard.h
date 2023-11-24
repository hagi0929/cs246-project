#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include "cell.h"
#include "turn.h"
#include "gamelog.h"
#include "coor.h"
#include "player.h"

using namespace std;

const int BOARD_SIZE = 8;

class GameBoard {
  Cell board[BOARD_SIZE][BOARD_SIZE];
  GameLog log;
  int thisTurn;
  Player *players[2];
  bool playerColors[2];

 public:
  GameBoard();
  ~GameBoard();
  bool isValidMove(Turn &t) const;
  bool move(Coor c1, Coor c2);
  void addPiece(Piece &p, Coor c);
  void removePiece(Coor c);
  void setBeginPlayer(Player &p);
  void undo(int moves);
  void redo(int moves);
  int getThisTurn() const;
};
#endif