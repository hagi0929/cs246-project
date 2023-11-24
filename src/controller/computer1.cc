#include "computer1.h"
 
Computer1::Computer1(GameBoard *board) : score{0}, board(board) {
    dout << "computer1 has been created" << endl;
}
Computer1::~Computer1() {
    dout << "computer1 has been destroyed" << endl;
}
Turn &Computer1::getNextTurn() {
    dout << "computer1 is getting its next turn" << endl;
}
Computer1::getScore() const {
    dout << "computer1 getScore is called" << endl;
}
