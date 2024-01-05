#ifndef SNAPSHOT_H
#define SNAPSHOT_H

#include <memory>
#include <vector>

#include "piece.h"

class Snapshot {
  std::vector<std::shared_ptr<Piece>> pieces;
  bool checked[2];
  int turn;
  bool calculateCheck(int playerNum);
  std::shared_ptr<Piece> getKing(int playerNum);
  std::vector<std::shared_ptr<Piece>> getPieces(int playerNum);

 public:
  Snapshot(std::vector<std::shared_ptr<Piece>> pieces, int turn);
  std::shared_ptr<Piece> getPiece(Coor);
  // TODO consider out of bounds
  bool isEmpty(Coor);
  bool isEnemy(Coor, int);
  bool isAlley(Coor, int);
  std::shared_ptr<Snapshot> simulateMove(Move move) const;
  bool isChecked(int playerNum);
  bool isCheckmate(int playerNum);
  bool isStalemate();
  bool canEnPassent(Coor);
  friend std::ostream& operator<<(std::ostream& out, const Snapshot& s);
  bool isDraw();
};
std::ostream& operator<<(std::ostream& out, const Snapshot& s);
#endif