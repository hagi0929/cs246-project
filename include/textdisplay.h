#ifndef TEXTDISPLAY_H
#define TEXTDISPLAY_H

#include <iostream>
#include <vector>
#include "cell.h"
#include "display.h"

class TextDisplay: public Display {
  std::vector<std::vector<char>> theDisplay;

 public:
  TextDisplay();
  ~TextDisplay();
  void display() override;
  void notify(Cell &c) override;
  friend std::ostream &operator<<(std::ostream &out, const TextDisplay &td);
};

#endif
