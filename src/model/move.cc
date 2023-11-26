#include "move.h"
#include <iostream>
using namespace std;

Move::Move(string cur, string dest, string promotion) : cur{cur}, dest{dest}, promotion{promotion} {
  cout << "Move ctor is called" << endl;
}

int Move::getRow(string coor) const {
  return 8 - (coor[1] - '1');
}

int Move::getCol(string coor) const {
  return coor[0] - 'a';
}

int Move::getCurRow(string coor) const {
  return getRow(cur);
}

int Move::getCurCol(string coor) const {
  return getCol(cur);
}

int Move::getDestRow(string coor) const {
  return getRow(dest);
}

int Move::getDestCol(string coor) const {
  return getCol(dest);
}
