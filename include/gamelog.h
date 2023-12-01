#ifndef GAMELOG_H
#define GAMELOG_H

#include <string>
#include <vector>
#include <memory>
#include "move.h"

class Stack
{
  std::vector<std::shared_ptr<Move>> stack;

 public:
  std::shared_ptr<Move> pop();
  void push(std::shared_ptr<Move> m);
  bool isEmpty();
  int getSize();
  std::shared_ptr<Move> peek();
  void showStack();
  void clearStack();
};

class GameLog
{
  Stack undoStack;
  Stack redoStack;

 public:
  GameLog();
  ~GameLog();
  std::shared_ptr<Move> redo();
  std::shared_ptr<Move> undo();
  void save(std::shared_ptr<Move> m); // push a single move to a stack
  void showUndoStack();
  void showRedoStack();
  void saveToFile(); // save all moves into a file (ex: game1.txt)
};

#endif
