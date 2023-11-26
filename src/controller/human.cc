#include "human.h"
#include <iostream>
using namespace std;

Human::Human() { cout << "Human has been created" << endl; }
Human::~Human() { cout << "Human has been destroyed" << endl; }
Move &Human::getNextTurn() {
  cout << "Human is getting its next turn" << endl;
  Move m{"", "", ""};
  return m;
}
