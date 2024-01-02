#ifndef COOR_H
#define COOR_H
#include <iostream>
#include <string>

class Coor {
  int x;
  int y;

 public:
  Coor(int x, int y);
  Coor(std::string s);
  int getX() const;
  int getY() const;
  friend std::ostream& operator<<(std::ostream& out, const Coor& coor);
  bool operator==(const Coor& other) const;
  Coor operator+(const Coor& other) const;
  Coor operator-(const Coor& other) const;
  bool isInbound() const;
};

#endif