#include "gamelog.h"

GameLog::GameLog() {
  dout << "gamelog ctor is called" << endl;
}
GameLog::~GameLog() {
  dout << "gamelog dtor is called" << endl;
}
Turn *GameLog::pop(int turns) {
  dout << "gamelog dtor is called" << endl;
  return nullptr;
}
void GameLog::push(Turn *move) {
  dout << "gamelog dtor is called" << endl;
}
