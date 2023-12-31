#include "human.h"

#include <boost/algorithm/string.hpp>
#include <iostream>
#include <string>
#include <vector>

#include "game.h"

using namespace std;

Human::Human(Game& game) : game{game} {}
shared_ptr<ICommand> Human::getCommand() {
  string rawCmd = game.getInput();
  vector<string> cmd;
  boost::split(cmd, rawCmd, boost::is_any_of(" "));
  if (cmd.size() == 0) {
    throw runtime_error("Invalid command");
  }
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
    return make_shared<MoveCommand>(Coor{cmd[1]}, Coor{cmd[2]},
                                    cmd.size() == 4 ? cmd[3][0] : ' ');
  } else if (cmd.front() == "quit") {
    return make_shared<QuitCommand>(QuitCommand());
  } else if (cmd.front() == "resign") {
    return make_shared<ResignCommand>(ResignCommand());
  } else {
    throw runtime_error("Invalid head command ");
  }
}
