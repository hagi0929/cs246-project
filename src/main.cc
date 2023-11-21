#if DEBUG
#define dout cout
#else
#define dout 0 && cout
#endif

#include <iostream>

#include "Game/Game.h"
 
using namespace std;

int main() {
  try {
    cout << "Welcome tdo the game!" << endl;
    dout << "Welcome to the gsdfame!" << endl;
  } catch (string e) {
    cerr << "ERROR: " << e << endl;
  }
}
