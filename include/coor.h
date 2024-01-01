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
  int getX();
  int getY();
  friend std::ostream& operator<<(std::ostream& out, const Coor& coor);
};


#endif