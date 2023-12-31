#include <stdexcept>

#include "game.h"

using namespace std;
int const NUMOFPLAYERS = 2;
int main() {
  try {
    Game game{cin};
    game.play();
    cout << "welcome!" << endl;
  } catch (exception& e) {
    cerr << "Game Crashed: " << e.what() << endl;
  }
}