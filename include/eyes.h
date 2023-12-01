#ifndef EYES_H
#define EYES_H
#include <iostream>
#include <memory>
#include <utility>
#include <vector>

class GameBoard;
class Cell;
class Piece;

class Eyes {
  std::weak_ptr<GameBoard> board;
  // [0]: White, [1]: Black
  std::vector<std::vector<std::shared_ptr<Piece>>> pieces;
  std::vector<bool> isChecked;
  std::vector<bool> isCheckmated;
  bool isStalemate;
  bool checked(std::pair<int, int> kingCoor, int attacker) const;
  void updateIsCheckmated(std::pair<int, int> kingCoor, int defender);
  void updateIsChecked(int attacker, int defender);
  void updateIsStalemate(int defender);

 public:
  Eyes(std::weak_ptr<GameBoard> board);
  bool isOccupied(std::pair<int, int> coor) const;
  bool isOpponent(std::pair<int, int> coor) const;
  bool getIsChecked(int player) const;
  bool getIsCheckmated(int player) const;
  bool getIsStalemate() const;
  void removePiece(std::shared_ptr<Piece> p);
  // Updates isChecked, isCheckmated, and isStalemate
  // where defender is the player getting attacked
  void updateState(int attacker, int defender);
};

#endif
