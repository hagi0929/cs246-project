#include <boost/algorithm/string.hpp>
#include <iostream>
#include <string>
#include <vector>

#include "game.h"
#include "human.h"

using namespace std;

int const NUMOFPLAYERS = 2;

string SetupState::headmessage() { return "setup: "; }
shared_ptr<ICommand> SetupState::getCommand(Game& game) {
  string rawCmd = game.getInput();
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
    return make_shared<AddPieceCommand>(
        Coor{cmd[1][0] - 'a', 7 - (cmd[1][1] - '1')}, cmd[2][0]);
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
}

string InGameState::headmessage() { return "game: "; }

shared_ptr<ICommand> InGameState::getCommand(Game& game) {
  std::weak_ptr<Player> currentPlayer = game.getCurrentPlayer();
  return currentPlayer.lock()->getCommand();
}

string MenuState::headmessage() { return "menu: "; }

shared_ptr<ICommand> MenuState::getCommand(Game& game) {
  string rawCmd = game.getInput();
  vector<string> cmd;
  boost::split(cmd, rawCmd, boost::is_any_of(" "));

  if (cmd.size() == 0) {
    cout << "Invalid command" << endl;
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
}
