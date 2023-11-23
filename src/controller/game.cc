#include "game.h"
#include <iostream>

Game::Game() : currentGame{nullptr} {
    dout << "Game ctor is called" << endl;
}

Game::~Game() {
    // delete currentGame;
    dout << "Game dtor is called" << endl;
}

void Game::play() {
    dout << "Game::play() is called" << endl;
}

bool Game::isValidCmd() {
    dout << "Game::isValidCmd() is called" << endl;
    return true;
}