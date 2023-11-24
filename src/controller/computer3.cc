#include "computer3.h"

Computer3::Computer3(GameBoard *board) : board(board) {
  dout << "Computer3 has been created" << endl;
}
Computer3::~Computer3() { dout << "Computer3 has been destroyed" << endl; }
Turn &Computer3::getNextTurn() {
  dout << "Computer3 is getting its next turn" << endl;
}
Computer3::getScore() const { dout << "Computer3 getScore is called" << endl; }
