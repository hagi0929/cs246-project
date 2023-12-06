#include <iostream>
#include <stdexcept>
#include "game.h"

using namespace std;

int main()
{
  bool graphics;
  cout << "Welcome to the game!" << endl;
  cout << "Would you like to turn on graphics? (y/n)" << endl;
  char yn;
  while (cin >> yn)
  {
    if (yn == 'y')
    {
      graphics = true;
      break;
    }
    else if (yn == 'n')
    {
      graphics = false;
      break;
    }
    else
    {
      cout << "answer with y or n" << endl;
    }
  }
  Game game{cin, graphics};
  game.activate();
}
