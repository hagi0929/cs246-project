#include "move.h"

#include <iostream>
using namespace std;

Move::Move(string cur, string dest, char promotion)
    : curRow{7 - (cur[1] - '1')},
      curCol{cur[0] - 'a'},
      destRow{7 - (dest[1] - '1')},
      destCol{dest[0] - 'a'},
      capturedMoveCount{0},
      promotion{promotion},
      capturedPiece{' '} {}

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

Move::Move(pair<int, int> cur, pair<int, int> dest, char promotion,
           string debug)
    : curRow{cur.first},
      curCol{cur.second},
      destRow{dest.first},
      destCol{dest.second},
      capturedMoveCount{0},
      promotion{promotion},
      capturedPiece{' '},
      debug{debug} {}

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
  return (curRow == other.getCurRow() && curCol == other.getCurCol() &&
          destRow == other.getDestRow() && destCol == other.getDestCol() &&
          promotion == other.getPromotion());
}

vector<string> Move::getCmd() const {
  vector<string> cmd;
  cmd.push_back("move");
  cmd.push_back(string(1, 'a' + curCol) + to_string(8 - curRow));
  cmd.push_back(string(1, 'a' + destCol) + to_string(8 - destRow));
  if (promotion != ' ') {
    cmd.push_back(string(1, promotion));
  }
  return cmd;
}

ostream &operator<<(ostream &out, const Move &move) {
  out << "(" << move.getCurRow() << "," << move.getCurCol() << ")->("
      << move.getDestRow() << ", " << move.getDestCol() << ")";
  out << ": " << move.getPromotion() << move.capturedPiece
      << "debug: " << move.debug << endl;
  return out;
}