#ifndef MOVE_H
#define MOVE_H

#include <string>

class Move {
  int curRow, curCol, destRow, destCol;
  std::string promotion;
  int getRow(std::string coor) const;
  int getCol(std::string coor) const;

 public:
  Move(std::string cur, std::string dest, std::string promotion);
  Move(int curRow, int curCol, int destRow, int destCol, std::string promotion);
  int getCurRow() const;
  int getCurCol() const;
  int getDestRow() const;
  int getDestCol() const;
  std::string getPromotion() const;
  bool operator==(const Move &other) const;
};

#endif