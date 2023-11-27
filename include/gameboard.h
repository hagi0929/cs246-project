#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <memory>
#include <string>
#include "move.h"
#include "gamelog.h"
#include "player.h"
#include "piece.h"
#include "cell.h"

const int BOARD_SIZE = 8;

class GameBoard {
  std::shared_ptr<Cell> board[BOARD_SIZE][BOARD_SIZE];
  // GameLog log;
  int thisTurn;
  bool playerColors[2];

 public:
  GameBoard();
  ~GameBoard();
  void move(Move &m);
  void addPiece(Piece &p, std::string coor);
  void removePiece(std::string coor);
  void setBeginPlayer(int player);
  void undo(int moves);
  void redo(int moves);
  void resign();
  int getThisTurn() const;
};

#endif
