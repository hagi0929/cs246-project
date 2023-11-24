#ifndef MOVE_H
#define MOVE_H

#include <string>
#include "coor.h"

using namespace std;

class Move {
  Coor cur, dest;
  string promotion;

 public:
  Move(Coor cur, Coor dest, string promotion);
  Coor getCur() const;
  Coor getDest() const;
};

#endif