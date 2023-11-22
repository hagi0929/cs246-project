#include "Computer2.h"
 
Computer2::Computer2(GameBoard &gameBoard) : Player(gameBoard) {
    dout << "Computer2 has been created" << endl;
}
Computer2::~Computer2() {
    dout << "Computer2 has been destroyed" << endl;
}
Turn Computer2::getNextTurn() {
    dout << "Computer2 is getting its next turn" << endl;
}
getScore() const {
    dout << "Computer2 getScore is called" << endl;
}
