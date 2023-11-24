#ifndef TEXTDISPLAY_H
#define TEXTDISPLAY_H

#include <iostream>
#include <vector>
#include "observer.h"

using namespace std;

const int gridSize = 8;

class TextDisplay: public Observer {
  vector<vector<char>> display;

 public:
  TextDisplay();
  void notify(Cell &c) override;
  ~TextDisplay();
  friend ostream &operator<<(ostream &out, const TextDisplay &td);
};

#endif
