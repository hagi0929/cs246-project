#include "human.h"
#include <iostream>
 
Human::Human() {
    dout << "Human has been created" << endl;
}
Human::~Human() {
    dout << "Human has been destroyed" << endl;
}
Turn &Human::getNextTurn() {
    dout << "Human is getting its next turn" << endl;
}

