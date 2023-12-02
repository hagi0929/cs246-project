#ifndef MOVE_H
#define MOVE_H

#include <string>
#include <utility>

class Move {
  int curRow, curCol, destRow, destCol, capturedMoveCount = 0;
  char promotion, capturedPiece = ' ';
  int getRow(std::string coor) const;
  int getCol(std::string coor) const;


 public:
  Move(std::string cur, std::string dest, char promotion);
  Move(int curRow, int curCol, int destRow, int destCol, char promotion);
  Move(std::pair<int, int> cur, std::pair<int, int> dest, char promotion);
  int getCurRow() const;
  int getCurCol() const;
  int getDestRow() const;
  int getDestCol() const;
  std::pair<int, int> getCur() const;
  std::pair<int, int> getDest() const;
  char getPromotion() const;
  char getCapturedPiece() const;
  void setCapturedPiece(char c);
  int getCapturedMoveCount() const;
  void setCapturedMoveCount(int count);
  bool operator==(const Move &other) const;
  friend std::ostream &operator<<(std::ostream &out, const Move &move);
};

#endif
