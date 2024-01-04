#ifndef COOR_H
#define COOR_H
#include <iostream>
#include <string>

class Coor {
  int col;
  int row;

 public:
  Coor(int row, int col);
  Coor(std::string s);
  int getRow() const;
  int getCol() const;
  friend std::ostream& operator<<(std::ostream& out, const Coor& coor);
  bool operator==(const Coor& other) const;
  Coor operator+(const Coor& other) const;
  Coor operator-(const Coor& other) const;
  bool isInbound() const;
};

#endif