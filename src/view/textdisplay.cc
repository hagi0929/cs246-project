#include "textdisplay.h"
#include <iostream>

using namespace std;

TextDisplay::TextDisplay()
{
  cout << "TextDisplay ctor is called" << endl;
  
  for (int i = 0; i < getBoardSize(); ++i)
  {
    char c = '_';
    vector<char> row(getBoardSize(), c);
    theDisplay.emplace_back(row);
  }
}

TextDisplay::~TextDisplay()
{
  cout << "TextDisplay dtor is called" << endl;
}

void TextDisplay::display()
{
}

void TextDisplay::notify(Cell &c)
{
  cout << "TextDisplay::notify() is called" << endl;
  int row = c.getRow();
  int col = c.getCol();

  theDisplay[row][col] = c.getPiece()->getType();
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
