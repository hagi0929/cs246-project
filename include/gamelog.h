#ifndef GAMELOG_H
#define GAMELOG_H

#include <string>
#include <vector>
#include "turn.h"

using namespace std;

class GameLog {
  vector<Turn *> stack;
  int timeline, timelineLimit;
 public:
  GameLog();
  ~GameLog();
  Turn *pop(int n);
  void push(Turn *);
};

#endif