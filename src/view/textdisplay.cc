#include "textdisplay.h"

#include <iostream>
#include <string>

using namespace std;

TextDisplay::TextDisplay()
{
  cout << "TextDisplay ctor is called" << endl;

  theDisplay.resize(getBoardSize(), std::vector<char>(8));

  int rows[] = {8, 7, 6, 5, 4, 3, 2, 1};
  char tiles[2][2] = {
      {' ', '_'}, // tiles for even rows
      {'_', ' '}  // tiles for odd rows
  };

  for (int r = 0; r < getBoardSize(); r++)
  {
    for (int c = 0; c < getBoardSize(); c++)
    {
      int i = r % 2, j = c % 2;
      theDisplay[r][c] = tiles[i][j];
    }
  }
}

TextDisplay::~TextDisplay() { cout << "TextDisplay dtor is called" << endl; }

void TextDisplay::display() { cout << *this; }

void TextDisplay::notify(Cell &c)
{
  cout << "TextDisplay::notify() is called" << endl;
  int row = c.getRow();
  int col = c.getCol();

  if (c.isEmpty())
  {
    theDisplay[row][col] = ((row + col) % 2 == 0) ? ' ' : '_';
  }
  else
  {
    theDisplay[row][col] = c.getPiece()->getType();
  }
}

ostream &operator<<(ostream &out, const TextDisplay &td)
{
  int rows[] = {8, 7, 6, 5, 4, 3, 2, 1};

  for (int r = 0; r < td.getBoardSize(); r++)
  {
    out << rows[r] << " ";
    for (int c = 0; c < td.getBoardSize(); c++)
    {
      out << td.theDisplay[r][c];
    }
    out << endl;
  }
  out << endl;
  out << "  abcdefgh" << endl;

  return out;
}
