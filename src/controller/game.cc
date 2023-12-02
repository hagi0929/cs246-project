#include "game.h"

#include <boost/algorithm/string.hpp>

#include "player.h"
#include "textdisplay.h"

using namespace std;

Game::Game(std::istream &in)
    : gameBoard{nullptr}, display{nullptr}, gameInProgress{false}, in{in}
{
  gameBoard = make_shared<GameBoard>();
  display = make_shared<TextDisplay>();
  gameBoard->init(display);
}

Game::~Game()
{
  // delete currentGame;
}

void Game::play() {}

// • setup enters setup mode, within which you can set up your own initial board
// configurations. This can only be done
//  when a game is not currently running. Within setup mode, the following
//  language is used: – + K e1 places the piece K (i.e., white king in this
//  case) on the square e1. If a piece is already on that square, it is
//  replaced. The board should be redisplayed. – - e1 removes the piece from the
//  square e1 and then redisplays the board. If there is no piece at that
//  square, take no action. – = colour makes it colour’s turn to go next. – done
//  leaves setup mode.

void Game::setupCmd()
{
  string rawCmd;
  getline(in, rawCmd);
  vector<string> cmd;
  boost::split(cmd, rawCmd, boost::is_any_of(" "));
  if (cmd.size() == 0)
  {
    throw runtime_error("Invalid command");
  }
  if (cmd.front() == "+")
  {
    if (cmd.size() != 3)
    {
      throw runtime_error("Invalid argument");
    }
    if (cmd[1].size() != 2 || cmd[1][0] < 'a' || cmd[1][0] > 'h' ||
        cmd[1][1] < '1' || cmd[1][1] > '8')
    {
      throw runtime_error("Invalid coordinate");
    }
    if (cmd[2].size() != 1 ||
        (cmd[2][0] != 'q' && cmd[2][0] != 'r' && cmd[2][0] != 'b' &&
         cmd[2][0] != 'k' && cmd[2][0] != 'n' && cmd[2][0] != 'p' &&
         cmd[2][0] != 'Q' && cmd[2][0] != 'R' && cmd[2][0] != 'B' &&
         cmd[2][0] != 'K' && cmd[2][0] != 'N' && cmd[2][0] != 'P'))
    {
      throw runtime_error("Invalid piece");
    }
    pair<int, int> coor = {7 - (cmd[1][1] - '1'), cmd[1][0] - 'a'};
    gameBoard->createPiece(coor, cmd[2][0]);
    display->display();
  }
  else if (cmd.front() == "-")
  {
    if (cmd.size() != 2)
    {
      throw runtime_error("Invalid argument");
    }
    if (cmd[1].size() != 2 || cmd[1][0] < 'a' || cmd[1][0] > 'h' ||
        cmd[1][1] < '1' || cmd[1][1] > '8')
    {
      throw runtime_error("Invalid coordinate");
    }
    pair<int, int> coor = {7 - (cmd[1][1] - '1'), cmd[1][0] - 'a'};
    gameBoard->removePiece(coor);
    display->display();
  }
  else if (cmd.front() == "=")
  {
    if (cmd.size() != 2)
    {
      throw runtime_error("Invalid argument");
    }
    if (cmd[1].size() != 1 || (cmd[1][0] != '0' && cmd[1][0] != '1'))
    {
      throw runtime_error("Invalid player");
    }
    gameBoard->setTurn(cmd[1][0] - '0');
  }
  else if (cmd.front() == "done")
  {
    if (cmd.size() != 1)
    {
      throw runtime_error("Invalid argument");
    }
    setupInProgress = false;
  }
  else
  {
    throw runtime_error("Invalid head command " + cmd.front());
  }
}
void Game::processCmd()
{
  string rawCmd;
  getline(in, rawCmd);
  vector<string> cmd;
  boost::split(cmd, rawCmd, boost::is_any_of(" "));

  if (cmd.size() == 0)
  {
    cout << "Invalid command" << endl;
  }
  if (cmd.front() == "quit")
  {
    exit(0);
  }
  else if (cmd.front() == "setup")
  {
    setupInProgress = true;
  }
  else if (cmd.front() == "game")
  {
    if (cmd.size() != NUMOFPLAYERS + 1)
    {
      throw runtime_error("Invalid argument");
    }
    for (int i = 0; i < NUMOFPLAYERS; i++)
    {
      if (cmd[1 + i] == "human")
      {
        players[i] = make_shared<Human>(in);
      }
      else if (cmd[1 + i] == "computer1")
      {
        // player1 = make_shared<Computer1>();
      }
      else if (cmd[1 + i] == "computer2")
      {
        // player1 = make_shared<Computer2>();
      }
      else if (cmd[1 + i] == "computer3")
      {
        // player1 = make_shared<Computer3>();
      }
      else if (cmd[1 + i] == "computer4")
      {
        // player1 = make_shared<Computer4>();
      }
      else
      {
        throw runtime_error("Invalid player type " + cmd[1 + i]);
        continue;
      }
    }
    gameInProgress = true;
  }
  else
  {
    throw runtime_error("Invalid head command " + cmd.front());
  }
}

void Game::activate()
{
  while (true)
  {
    try
    {
      if (in.eof())
      {
        exit(0);
      }
      if (gameInProgress)
      {
        display->display();
        cout << "type command for player " << gameBoard->getThisTurn() << endl;
        int currentPlayerNo = gameBoard->getThisTurn();
        userCmd cmdObj = players[currentPlayerNo]->getResponse();
        if (cmdObj.type == cmdType::QUIT)
        {
          exit(0);
        }
        else if (cmdObj.type == cmdType::RESIGN)
        {
          gameBoard->resign();
        }
        else if (cmdObj.type == cmdType::MOVE)
        {
          shared_ptr<Move> m;
          if (cmdObj.cmd.size() == 4) {
            m = make_shared<Move>(cmdObj.cmd[1], cmdObj.cmd[2], cmdObj.cmd[3][0]);
          } else {
            m = make_shared<Move>(cmdObj.cmd[1], cmdObj.cmd[2], ' ');
          }
          gameBoard->movePiece(m);
        }
        else if (cmdObj.type == cmdType::UNDO) {
          gameBoard->undo(true);
        }
        else if (cmdObj.type == cmdType::REDO) {
          gameBoard->redo();
        }
      }
      else if (setupInProgress)
      {
        cout << "type command for setup" << endl;
        setupCmd();
      }
      else
      {
        cout << "type command for general" << endl;
        processCmd();
      }
    }
    catch (runtime_error &e)
    {
      cout << "CMD ERROR: " << e.what() << endl;
    }
  }
}
