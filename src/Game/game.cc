#include "game.h"

Game::Game() : currentGame{GameBoard()} {
  dout << "Game::Game() called" << endl;
}
