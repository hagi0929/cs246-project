#ifndef MOVE_H
#define MOVE_H

#include <string>

class Move {
  std::string cur, dest, promotion;
  int getRow(std::string coor) const;
  int getCol(std::string coor) const;

 public:
  Move(std::string cur, std::string dest, std::string promotion);
  int getCurRow(std::string coor) const;
  int getCurCol(std::string coor) const;
  int getDestRow(std::string coor) const;
  int getDestCol(std::string coor) const;
};

#endif