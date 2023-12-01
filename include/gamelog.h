#ifndef GAMELOG_H
#define GAMELOG_H

#include <string>
#include <vector>
#include <move.h>

class EmptyStackException : public std::exception
{
public:
  ~EmptyStackException();
};

class RedoEmptyStackException : public EmptyStackException
{
public:
  ~RedoEmptyStackException();
  const char *what() const noexcept;
};

class UndoEmptyStackException : public EmptyStackException
{
public:
  ~UndoEmptyStackException();
  const char *what() const noexcept;
};

class Stack
{
  std::vector<Move> stack;

public:
  Move pop();
  void push(Move m);
  bool isEmpty();
  int getSize();
  Move peek();
};

class GameLog
{
  Stack undoStack;
  Stack redoStack;

public:
  GameLog();
  ~GameLog();
  Move redo(int n = 0);
  Move undo(int n = 0);
  void save(Move m); // push a single move to a stack
  void showLog();
  void save(); // save all moves into a file (ex: game1.txt)
};

#endif
