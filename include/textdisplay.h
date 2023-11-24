#ifndef TEXTDISPLAY_H
#define TEXTDISPLAY_H

#include <iostream>
#include <vector>
#include "observer.h"

using namespace std;

class TextDisplay: public Observer {
  std::vector<std::vector<char>> display;
  const int gridSize;

 public:
  TextDisplay();
  void notify(Turn &t) override;
  ~TextDisplay();
  friend std::ostream &operator<<(std::ostream &out, const TextDisplay &td);
};

#endif
