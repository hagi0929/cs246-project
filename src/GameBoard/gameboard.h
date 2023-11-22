#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include "../Cell/cell.h"
#include "../Player/player.h"
#include "../etc/history.h"
#include "../Piece/piece.h"

const int BOARD_SIZE = 8;

class GameBoard {
  Cell board[BOARD_SIZE][BOARD_SIZE];
  History history;
  int thisTurn;
  Player *players[2];

 public:
  GameBoard();
  ~GameBoard();
  bool isValidMove(Turn t) const;
  bool move(Coor c1, Coor c2);
  void addPiece(Piece &p, Coor c);
  void removePiece(Coor c);
  void setBeginPlayer(Player &p);
  void undo(int moves);
  void redo(int moves);
  int getThisTurn() const;
};
#endif