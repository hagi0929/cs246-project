#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <memory>
#include <string>
#include <utility>

#include "cell.h"
#include "eyes.h"
#include "gamelog.h"
#include "move.h"
#include "piece.h"
#include "player.h"

const int BOARD_SIZE = 8;

class GameBoard : public std::enable_shared_from_this<GameBoard> {
  std::shared_ptr<Cell> board[BOARD_SIZE][BOARD_SIZE];
  std::shared_ptr<Eyes> eyes = nullptr;
  GameLog log;
  int thisTurn;
  bool playerColors[2];

 public:
  GameBoard();
  ~GameBoard();
  void init(std::shared_ptr<Observer> o);
  void doValidMove(std::shared_ptr<Move> m);
  void movePiece(std::shared_ptr<Move> m, bool AI);
  void addPiece(std::shared_ptr<Piece> p, std::pair<int, int> coor);
  void removePiece(std::pair<int, int> coor);
  void setTurn(int player);
  void undo(bool push);
  void redo();
  void resign();
  int getThisTurn() const;
  void createPiece(std::pair<int, int> coor, char p);
  std::shared_ptr<Cell> getCell(std::pair<int, int> coor) const;
  std::shared_ptr<Eyes> getEyes() const;
};

#endif
