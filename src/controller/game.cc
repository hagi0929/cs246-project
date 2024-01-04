#include "game.h"
#include "human.h"
#include "textdisplay.h"
using namespace std;

Game::Game(istream& in)
    : in{in},
      gamestate{make_unique<MenuState>()},
      gameboard{make_unique<Gameboard>()},
      displays{} {
        displays.emplace_back(make_shared<TextDisplay>());
        gameboard->attach(displays.back());
      }
void Game::play() {
  while (true) {
    try {
      cout << gamestate->headmessage();
      shared_ptr<ICommand> cmdObj = gamestate->getCommand(*this);
      cmdObj->execute(*this);
    } catch (exception& e) {
      cerr << "ERROR: " << e.what() << endl;
    }
  }
}
void Game::showAll() {
  for (auto& display : displays) {
    display->show();
  }
}
void Game::setState(Gamestate* newState) { gamestate.reset(newState); }
std::weak_ptr<Player> Game::getCurrentPlayer() {
  return players[gameboard->getThisTurn()];
}
void Game::addPieceToBoard(const Coor& coor, char piece) {
  gameboard->addPiece(coor, piece);
}
void Game::removePieceFromBoard(const Coor& coor) {
  gameboard->removePiece(coor);
}
void Game::movePiece(const Coor& from, const Coor& to, char promotion) {
  gameboard->movePiece(from, to, promotion);
}
void Game::setThisTurn(int turn) { gameboard->setTurn(turn); }
void Game::setPlayer(string player, int playerNum) {
  if (player == "human") {
    players[playerNum] = make_shared<Human>(*this);
  } else if (player == "computer1") {
    // players[i] = make_shared<Computer1>();
  } else if (player == "computer2") {
    // players[i] = make_shared<Computer2>();
  } else if (player == "computer3") {
    // players[i] = make_shared<Computer3>();
  } else if (player == "computer4") {
    // players[i] = make_shared<Computer4>();
  } else {
    throw runtime_error("Invalid player type " + player);
  }

}
void Game::resign() {}
void Game::executeCommand(unique_ptr<ICommand> command) {
  command->execute(*this);
}
string Game::getInput() {
  string rawCmd;
  getline(in, rawCmd);
  if (in.eof()) {
    exit(0);
  }
  return rawCmd;
}
