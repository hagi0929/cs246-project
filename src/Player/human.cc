#include "Human.h"
 
Human::Human(GameBoard &gameBoard) : Player(gameBoard) {
    dout << "Human has been created" << endl;
}
Human::~Human() {
    dout << "Human has been destroyed" << endl;
}
Turn Human::getNextTurn() {
    dout << "Human is getting its next turn" << endl;
}
getScore() const {
    dout << "Human getScore is called" << endl;
}
