#include "game.h"

using namespace std;

Game::Game(shared_ptr<GameBoard> board, shared_ptr<Display> display)
    : board{nullptr} {
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

void Game::activate() {
  while (true) {
    string rawCmd;
    getline(cin, rawCmd);
    vector<string> cmd = parseCmd(rawCmd);
    if (cmd.size() == 0) {
      cout << "Invalid command" << endl;
      continue;
    }
    if (cmd.front() == "quit") {
      exit(0);
    } else if (cmd.front() == "setup") {
    } else if (cmd.front() == "game") {
      if (cmd.size() != NUMOFPLAYERS + 1) {
        cout << "Wrong argument" << endl;
        continue;
      }
      for (int i = 0; i < NUMOFPLAYERS; i++) {
        if (cmd[1 + i] == "human") {
          players[i] = make_shared<Human>();
        } else if (cmd[1 + i] == "computer1") {
          // player1 = make_shared<Computer1>();
        } else if (cmd[1 + i] == "computer2") {
          // player1 = make_shared<Computer2>();
        } else if (cmd[1 + i] == "computer3") {
          // player1 = make_shared<Computer3>();
        } else if (cmd[1 + i] == "computer4") {
          // player1 = make_shared<Computer4>();
        } else {
          cout << "Invalid player 1" << endl;
          continue;
        }
      }
      board = make_shared<GameBoard>();
      gameStarted = true;
    } else {
      cout << "Invalid command" << endl;
      continue;
    }
  }
}