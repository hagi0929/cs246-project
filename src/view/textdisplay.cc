#include "textdisplay.h"

#include <iostream>

using namespace std;

void TextDisplay::notifyAdd(Coor c, char ch) { 
  cout << "notifyAdd" << endl;
  board[c.getCol()][c.getRow()] = ch; }

void TextDisplay::notifyRemove(Coor c) { board[c.getCol()][c.getRow()] = ' '; }

void TextDisplay::notifyMove(Coor from, Coor to) {
  board[to.getCol()][to.getRow()] = board[from.getCol()][from.getRow()];
  board[from.getCol()][from.getRow()] = 0;
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