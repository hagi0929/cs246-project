#include "human.h"

#include <boost/algorithm/string.hpp>
#include <iostream>
using namespace std;

Human::Human(istream &in) : in{in} {}
Human::~Human() {}

userCmd Human::getResponse() {
  string rawCmd;
  getline(cin, rawCmd);
  vector<string> cmd;
  boost::split(cmd, rawCmd, boost::is_any_of(" "));
  if (cmd.size() == 0) {
    cout << "Invalid command" << endl;
  }
  cmdType type = cmdType::MOVE;
  if (cmd.front() == "move") {
    if (cmd.size() < 3 || 4 < cmd.size()) {
      throw runtime_error("Invalid argument");
    }
    if (cmd[1].size() != 2 || cmd[1][0] < 'a' || cmd[1][0] > 'h' ||
        cmd[1][1] < '1' || cmd[1][1] > '8' || cmd[2].size() != 2 ||
        cmd[2][0] < 'a' || cmd[2][0] > 'h' || cmd[2][1] < '1' ||
        cmd[2][1] > '8') {
      throw runtime_error("Invalid coordinate");
    }
    if (cmd.size() == 4 &&
        (cmd[3].size() != 1 ||
         (cmd[3][0] != 'q' && cmd[3][0] != 'r' && cmd[3][0] != 'b' &&
          cmd[3][0] != 'k' && cmd[3][0] != 'n' && cmd[3][0] != 'p'))) {
      throw runtime_error("Invalid promotion");
    }
    type = cmdType::MOVE;
  } else if (cmd.front() == "quit") {
    type = cmdType::QUIT;
  } else if (cmd.front() == "resign") {
    type = cmdType::RESIGN;
  } else if (cmd.front() == "undo") {
    type = cmdType::UNDO;
  } else if (cmd.front() == "redo") {
    type = cmdType::REDO;
  } else {
    throw runtime_error("Invalid head command ");
  }
  return userCmd{type, cmd};
}
