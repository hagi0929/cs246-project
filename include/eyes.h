#ifndef EYES_H
#define EYES_H
#include <iostream>
#include <memory>
#include <utility>
#include <vector>

class GameBoard;
class Cell;
class Piece;
class Move;

class Eyes {
  std::shared_ptr<GameBoard> board;
  // [0]: White, [1]: Black
  std::vector<std::vector<std::shared_ptr<Piece>>> pieces;
  std::vector<bool> isChecked;
  std::vector<bool> isCheckmated;
  bool isStalemate;
  void updateIsCheckmated(int attacker, int defender);
  void updateIsChecked(int attacker, int defender);
  void updateIsStalemate(int attacker, int defender);

 public:
  Eyes(std::shared_ptr<GameBoard> board);
  bool isOccupied(std::pair<int, int> coor) const;
  bool isOpponent(std::pair<int, int> coor) const;
  bool checked(int attacker, int defender) const;
  bool getIsChecked(int player) const;
  bool getIsCheckmated(int player) const;
  bool getIsStalemate() const;
  void removePiece(std::shared_ptr<Piece> p);
  void addPiece(std::shared_ptr<Piece> p);
  // Updates isChecked, isCheckmated, and isStalemate
  // where defender is the player getting attacked
  void updateState(int attacker, int defender);
  bool isSafeMove(std::shared_ptr<Move> m);
    int getThisTurn() const;
  std::vector<std::shared_ptr<Piece>> getPieces(int player) const;
  std::shared_ptr<GameBoard> getBoard();

};

#endif
