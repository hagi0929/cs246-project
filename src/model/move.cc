#include "move.h"

#include <iostream>
using namespace std;

Move::Move(string cur, string dest, char promotion) {
  curRow = 7 - (cur[1] - '1');
  curCol = cur[0] - 'a';
  destRow = 7 - (dest[1] - '1');
  destCol = dest[0] - 'a';
  capturedMoveCount = 0;
  promotion = promotion;
  capturedPiece = ' ';
}

Move::Move(int curRow, int curCol, int destRow, int destCol, char promotion)
    : curRow{curRow},
      curCol{curCol},
      destRow{destRow},
      destCol{destCol},
      capturedMoveCount{0},
      promotion{promotion},
      capturedPiece{' '} {}

Move::Move(pair<int, int> cur, pair<int, int> dest, char promotion)
    : curRow{cur.first},
      curCol{cur.second},
      destRow{dest.first},
      destCol{dest.second},
      capturedMoveCount{0},
      promotion{promotion},
      capturedPiece{' '} {}

int Move::getCurRow() const { return curRow; }

int Move::getCurCol() const { return curCol; }

int Move::getDestRow() const { return destRow; }

int Move::getDestCol() const { return destCol; }

pair<int, int> Move::getCur() const { return make_pair(curRow, curCol); }

pair<int, int> Move::getDest() const { return make_pair(destRow, destCol); }

char Move::getPromotion() const { return promotion; }

char Move::getCapturedPiece() const { return capturedPiece; }

void Move::setCapturedPiece(char c) { capturedPiece = c; }

int Move::getCapturedMoveCount() const { return capturedMoveCount; }

void Move::setCapturedMoveCount(int count) { capturedMoveCount = count; }

bool Move::operator==(const Move &other) const {
  return (getCurRow() == other.getCurRow() &&
          getCurCol() == other.getCurCol() &&
          getDestRow() == other.getDestRow() &&
          getDestCol() == other.getDestCol() &&
          getPromotion() == other.getPromotion());
}

ostream &operator<<(ostream &out, Move &move)
{
  cout << "[Cur: ] (" << move.getCurRow() << ", " << move.getCurCol() << "), ";
  cout << "Dest: ] (" << move.getDestRow() << ", " << move.getDestCol() << "), ";
  cout << "Promo: " << move.getPromotion()<< "]";
}
