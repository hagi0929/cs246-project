#if DEBUG
#define dout cout
#else
#define dout 0 && cout
#endif

#include <iostream>
#include <stdexcept>
#include "game.h"

using namespace std;

int main() {
  try {
    Game game{};
    cout << "Welcome tdo the game!" << endl;
    dout << "Welcome to the gsdfame!" << endl;
  } catch (exception& e) {
    cerr << "ERROR: " << e.what() << endl;
  }
}
