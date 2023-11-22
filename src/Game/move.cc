#include "move.h"
#include <iostream>
using namespace std;

Move::Move(Coor cur, Coor dest, string promotion) : cur{cur}, dest{dest}, promotion{promotion} {
    dout << "Move ctor is called" << endl;
}

Coor Move::getCur() const {
    dout << "getCur() is called" << endl;
    return cur;
}

Coor Move::getDest() const {
    dout << "getDest() is called" << endl;
    return dest;
}