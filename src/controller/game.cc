#include "game.h"

#include <boost/algorithm/string.hpp>

#include "human.h"
#include "textdisplay.h"
using namespace std;
const int NUMOFPLAYERS = 2;
Game::Game(istream& in)
    : in{in}, gameboard{make_unique<Gameboard>()}, displays{} {
  displays.emplace_back(make_shared<TextDisplay>());
  gameboard->attach(displays.back());
}
void Game::play() {
  while (true) {
    try {
      shared_ptr<ICommand> cmdObj = getCommand();
      cmdObj->execute(*this, *gameboard);
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

shared_ptr<ICommand> Game::getCommand() {
  if (gameState == GameState::MENU) {
    string rawCmd = getInput();
    vector<string> cmd;
    boost::split(cmd, rawCmd, boost::is_any_of(" "));

    if (cmd.size() == 0) {
      throw runtime_error("Invalid command");
    }
    if (cmd.front() == "quit") {
      return make_shared<QuitCommand>();
    } else if (cmd.front() == "setup") {
      return make_shared<SetUpCommand>();
    } else if (cmd.front() == "game") {
      if (cmd.size() != NUMOFPLAYERS + 1) {
        throw runtime_error("Invalid argument");
      }
      for (int i = 0; i < NUMOFPLAYERS; i++) {
        if (cmd[1 + i] == "human") {
        } else if (cmd[1 + i] == "computer1") {
        } else if (cmd[1 + i] == "computer2") {
        } else if (cmd[1 + i] == "computer3") {
        } else if (cmd[1 + i] == "computer4") {
        } else {
          throw runtime_error("Invalid player type " + cmd[1 + i]);
          continue;
        }
      }
      return make_shared<GameCommand>(cmd[1], cmd[2]);
    } else {
      throw runtime_error("Invalid head command " + cmd.front());
    }
  } else if (gameState == GameState::PLAYING) {
    showAll();
    std::weak_ptr<Player> currentPlayer = getCurrentPlayer();
    return currentPlayer.lock()->getCommand();

  } else if (gameState == GameState::SETUP) {
    string rawCmd = getInput();
    vector<string> cmd;
    boost::split(cmd, rawCmd, boost::is_any_of(" "));
    if (cmd.size() == 0) {
      throw runtime_error("Invalid command");
    }
    if (cmd.front() == "+") {
      if (cmd.size() != 3) {
        throw runtime_error("Invalid argument");
      }
      if (cmd[1].size() != 2 || cmd[1][0] < 'a' || cmd[1][0] > 'h' ||
          cmd[1][1] < '1' || cmd[1][1] > '8') {
        throw runtime_error("Invalid coordinate");
      }
      if (cmd[2].size() != 1 ||
          (cmd[2][0] != 'q' && cmd[2][0] != 'r' && cmd[2][0] != 'b' &&
           cmd[2][0] != 'k' && cmd[2][0] != 'n' && cmd[2][0] != 'p' &&
           cmd[2][0] != 'Q' && cmd[2][0] != 'R' && cmd[2][0] != 'B' &&
           cmd[2][0] != 'K' && cmd[2][0] != 'N' && cmd[2][0] != 'P')) {
        throw runtime_error("Invalid piece");
      }
      return make_shared<AddPieceCommand>(
          Coor{cmd[1][0] - 'a', 7 - (cmd[1][1] - '1')}, cmd[2][0]);
    } else if (cmd.front() == "-") {
      if (cmd.size() != 2) {
        throw runtime_error("Invalid argument");
      }
      if (cmd[1].size() != 2 || cmd[1][0] < 'a' || cmd[1][0] > 'h' ||
          cmd[1][1] < '1' || cmd[1][1] > '8') {
        throw runtime_error("Invalid coordinate");
      }
      return make_shared<RemovePiece>(
          Coor{cmd[1][0] - 'a', 7 - (cmd[1][1] - '1')});
    } else if (cmd.front() == "=") {
      if (cmd.size() != 2) {
        throw runtime_error("Invalid argument");
      }
      if (cmd[1].size() != 1 || (cmd[1][0] != '0' && cmd[1][0] != '1')) {
        throw runtime_error("Invalid player");
      }
      return make_shared<SetTurn>(cmd[1][0] - '0');
    } else if (cmd.front() == "done") {
      if (cmd.size() != 1) {
        throw runtime_error("Invalid argument");
      }
      return make_shared<DoneSetup>();
    } else {
      throw runtime_error("Invalid head command " + cmd.front());
    }

  } else {
  }
}
void Game::setState(GameState newState) { gameState = newState; }
std::weak_ptr<Player> Game::getCurrentPlayer() {
  return players[gameboard->getThisTurn()];
}
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
  command->execute(*this, *gameboard);
}
string Game::getInput() {
  string rawCmd;
  getline(in, rawCmd);
  if (in.eof()) {
    exit(0);
  }
  return rawCmd;
}
