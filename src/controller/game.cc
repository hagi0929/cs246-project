#include "game.h"
#include <iostream>
#include <string>

Game::Game() : board{nullptr} {
    dout << "Game ctor is called" << endl;
}

Game::~Game() {
    // delete currentGame;
    dout << "Game dtor is called" << endl;
}

void Game::play() {
    dout << "Game::play() is called" << endl;
}

bool Game::isValidCmd() const {
    dout << "Game::isValidCmd() is called" << endl;
    string cmd;

    return true;
}
