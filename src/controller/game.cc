#include "game.h"

#include <boost/algorithm/string.hpp>

#include "player.h"

using namespace std;

Game::Game(std::istream &in)
    : board{nullptr}, display{nullptr}, gameInProgress{false}, in{in} {
  cout << "Game ctor is called" << endl;
}

Game::~Game() {
  // delete currentGame;
  cout << "Game dtor is called" << endl;
}

void Game::play() { cout << "Game::play() is called" << endl; }

vector<string> Game::parseCmd(string cmd) {
  vector<string> result;
  string temp;
  for (auto c : cmd) {
    if (c == ' ') {
      result.push_back(temp);
      temp = "";
    } else {
      temp += c;
    }
  }
  result.push_back(temp);
  return result;
}

void Game::processCmd() {
  string rawCmd;
  getline(cin, rawCmd);
  vector<string> cmd;
  boost::split(cmd, rawCmd, boost::is_any_of(" "));

  if (cmd.size() == 0) {
    cout << "Invalid command" << endl;
  }
  if (cmd.front() == "quit") {
    exit(0);
  } else if (cmd.front() == "setup") {
  } else if (cmd.front() == "game") {
    if (cmd.size() != NUMOFPLAYERS + 1) {
      throw runtime_error("Invalid argument");
    }
    for (int i = 0; i < NUMOFPLAYERS; i++) {
      if (cmd[1 + i] == "human") {
        players[i] = make_shared<Human>(in);
      } else if (cmd[1 + i] == "computer1") {
        // player1 = make_shared<Computer1>();
      } else if (cmd[1 + i] == "computer2") {
        // player1 = make_shared<Computer2>();
      } else if (cmd[1 + i] == "computer3") {
        // player1 = make_shared<Computer3>();
      } else if (cmd[1 + i] == "computer4") {
        // player1 = make_shared<Computer4>();
      } else {
        throw runtime_error("Invalid player type " + cmd[1 + i]);
        continue;
      }
    }
    board = make_shared<GameBoard>();
    gameInProgress = true;
  } else {
    throw runtime_error("Invalid head command " + cmd.front());
  }
}

void Game::activate() {
  while (true) {
    try {
      if (gameInProgress) {
        cout << "type command for player " << board->getThisTurn() << endl;
        int currentPlayerNo = board->getThisTurn();
        userCmd cmdObj = players[currentPlayerNo]->getResponse();
        if (cmdObj.type == cmdType::QUIT) {
          exit(0);
        } else if (cmdObj.type == cmdType::RESIGN) {
          board->resign();
        } else if (cmdObj.type == cmdType::MOVE) {
          try {
            Move m = Move{cmdObj.cmd[1], cmdObj.cmd[2], ""};
            board->move(m);
          } catch (runtime_error &e) {
            cout << "LOGIC ERROR: " << e.what() << endl;
          }
        } else {
          cout << "type command for general" << endl;
          processCmd();
        }
      }
      catch (runtime_error &e) {
        cout << "CMD ERROR: " << e.what() << endl;
      }
    }
  }