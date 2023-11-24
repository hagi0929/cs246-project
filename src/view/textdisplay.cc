#include "textdisplay.h"
#include <iostream>
#include <vector>

using namespace std;

TextDisplay::TextDisplay() {
  for (int i = 0; i < gridSize; ++i) {
    char c = '_';
    vector<char> row(gridSize, c);
    display.emplace_back(row);
  }
}

TextDisplay::~TextDisplay() {}

void TextDisplay::notify(Cell &c) {
  int row = c.getRow();
  int col = c.getCol();

  display[row][col] = c.getPiece()->getChar();
}

ostream &operator<<(ostream &out, const TextDisplay &td) {
  for (auto r : td.display) {
    for (auto c : r) {
      out << c;
    }
    out << endl;
  }
  return out;
}

