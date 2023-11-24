#include "computer4.h"

Computer4::Computer4(GameBoard *board) : board(board) {
  dout << "computer4 has been created" << endl;
}
Computer4::~Computer4() { dout << "computer4 has been destroyed" << endl; }
Turn &Computer4::getNextTurn() {
  dout << "computer4 is getting its next turn" << endl;
}
Computer4::getScore() const { dout << "computer4 getScore is called" << endl; }
