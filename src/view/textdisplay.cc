#include "textdisplay.h"
#include <iostream>
#include <string>

using namespace std;

TextDisplay::TextDisplay()
{
  cout << "TextDisplay ctor is called" << endl;

  theDisplay.resize(getBoardSize(), std::vector<char>(10));

  for (int i = 0; i < getBoardSize(); ++i)
  {
    int rowNum = 8 - i;
    char rowChar = to_string(rowNum)[0];

    theDisplay[i][0] = rowChar;
    theDisplay[i][1] = ' ';
    for (int j = 2; j < getBoardSize() + 2; ++j)
    {

      if ((i + j) % 2 == 0)
      {
        theDisplay[i][j] = ' ';
      }
      else
      {
        theDisplay[i][j] = '_';
      }
    }
  }
}

TextDisplay::~TextDisplay()
{
  cout << "TextDisplay dtor is called" << endl;
}

void TextDisplay::display()
{
  cout << "TextDisplay::display() is called" << endl;

  cout << this;
}

void TextDisplay::notify(Cell &c)
{
  cout << "TextDisplay::notify() is called" << endl;
  int row = c.getRow();
  int col = c.getCol() + 2;

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
  for (auto r : td.theDisplay)
  {
    for (auto c : r)
    {
      out << c;
    }
    out << endl;
  }
  return out;
}
