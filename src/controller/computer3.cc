#include "computer3.h"

Computer3::Computer3(GameBoard &gameBoard) : Player(gameBoard) {
  dout << "Computer3 has been created" << endl;
}
Computer3::~Computer3() { dout << "computer1 has been destroyed" << endl; }
Turn Computer3::getNextTurn() {
  dout << "Computer3 is getting its next turn" << endl;
}
getScore() const { dout << "Computer3 getScore is called" << endl; }
