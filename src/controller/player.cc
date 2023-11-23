#include "player.h"
#include <iostream>


Player::Player() : score{0} {
    dout << "Player ctor is called" << endl;
}

int Player::getScore() const {
    dout << "Player::getScore is called" << endl;
    return score;
}