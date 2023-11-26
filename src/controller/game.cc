#include "game.h"
#include <iostream>
using namespace std;

Game::Game(GameBoard *board, Display *display): board{board}, display{display} {
    cout << "Game ctor is called" << endl;
}

Game::~Game() {
    // delete currentGame;
    cout << "Game dtor is called" << endl;
}

void Game::play() {
    cout << "Game::play() is called" << endl;
}

bool Game::isValidCmd() const {
    cout << "Game::isValidCmd() is called" << endl;
    return true;
}
