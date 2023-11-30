#include "move.h"

#include <iostream>
using namespace std;

Move::Move(string cur, string dest, string promotion) {
  curRow = 7 - (cur[1] - '1');
  curCol = cur[0] - 'a';
  destRow = 7 - (dest[1] - '1');
  destCol = dest[0] - 'a';
  promotion = promotion;
}

Move::Move(int curRow, int curCol, int destRow, int destCol,
           std::string promotion)
    : curRow{curRow},
      curCol{curCol},
      destRow{destRow},
      destCol{destCol},
      promotion{promotion} {}

Move::Move(pair<int, int> cur, pair<int, int> dest, std::string promotion)
    : curRow{cur.first},
      curCol{cur.second},
      destRow{dest.first},
      destCol{dest.second},
      promotion{promotion} {}

int Move::getCurRow() const { return curRow; }

int Move::getCurCol() const { return curCol; }

int Move::getDestRow() const { return destRow; }

int Move::getDestCol() const { return destCol; }

pair<int, int> Move::getCur() const { return make_pair(curRow, curCol); }

pair<int, int> Move::getDest() const { return make_pair(destRow, destCol); }

string Move::getPromotion() const { return promotion; }

bool Move::operator==(const Move &other) const {
  return (getCurRow() == other.getCurRow() &&
          getCurCol() == other.getCurCol() &&
          getDestRow() == other.getDestRow() &&
          getDestCol() == other.getDestCol() &&
          getPromotion() == other.getPromotion());
}
