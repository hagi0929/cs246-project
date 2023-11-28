#include "move.h"

#include <iostream>
using namespace std;

Move::Move(string cur, string dest, string promotion) {
  curRow = 8 - (cur[1] - '1');
  curCol = cur[0] - 'a';
  destRow = 8 - (dest[1] - '1');
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

int Move::getRow(string coor) const { return 8 - (coor[1] - '1'); }

int Move::getCol(string coor) const { return coor[0] - 'a'; }

int Move::getCurRow() const { return curRow; }

int Move::getCurCol() const { return curCol; }

int Move::getDestRow() const { return destRow; }

int Move::getDestCol() const { return destCol; }

string Move::getPromotion() const { return promotion; }

bool Move::operator==(const Move &other) const {
  return (getCurRow() == other.getCurRow() &&
          getCurCol() == other.getCurCol() &&
          getDestRow() == other.getDestRow() &&
          getDestCol() == other.getDestCol() &&
          getPromotion() == other.getPromotion());
}
