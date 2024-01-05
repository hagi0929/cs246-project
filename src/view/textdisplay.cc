#include "textdisplay.h"

#include <iostream>

using namespace std;

void TextDisplay::notifyAdd(Coor c, char ch) { board[c.getX()][c.getY()] = ch; }

void TextDisplay::notifyRemove(Coor c) { board[c.getX()][c.getY()] = ' '; }

void TextDisplay::notifyMove(Coor from, Coor to) {
  board[to.getX()][to.getY()] = board[from.getX()][from.getY()];
  board[from.getX()][from.getY()] = 0;
}

void TextDisplay::show() {
  for (int i = 0; i < 8; ++i) {
    cout << 8 - i << " ";
    for (int j = 0; j < 8; ++j) {
      if (board[j][i] == 0) {
        if ((i + j) % 2 == 0) {
          cout << '_';
        } else {
          cout << ' ';
        }
      } else {
        cout << board[j][i];
      }
    }
    cout << endl;
  }
  cout << endl;
  cout << "  abcdefgh" << endl;
}