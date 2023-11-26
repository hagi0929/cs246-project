#include <iostream>
#include <stdexcept>
#include "game.h"

using namespace std;

int main() {
  try {
    Game game{};
    game.activate();
    cout << "Welcome tdo the game!" << endl;
    cout << "Welcome to the gsdfame!" << endl;
  } catch (exception& e) {
    cerr << "ERROR: " << e.what() << endl;
  }
}
