#include "move.h"
#include <iostream>
using namespace std;

Move::Move(Coor cur, Coor dest, string promotion) : cur{cur}, dest{dest}, promotion{promotion} {
    cout << "Move ctor is called" << endl;
}

Coor Move::getCur() const {
    cout << "getCur() is called" << endl;
    return cur;
}

Coor Move::getDest() const {
    cout << "getDest() is called" << endl;
    return dest;
}
