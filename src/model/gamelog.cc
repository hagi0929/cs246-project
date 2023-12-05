#include "gamelog.h"

#include <iostream>
using namespace std;

shared_ptr<Move> Stack::pop()
{
    shared_ptr<Move> top = peek();
    stack.pop_back();
    return top;
}
void Stack::push(shared_ptr<Move> m)
{
    stack.emplace_back(m);
}
bool Stack::isEmpty()
{
    return stack.size() == 0;
}
int Stack::getSize()
{
    return stack.size();
}
shared_ptr<Move> Stack::peek()
{
    return stack.back();
}
void Stack::clearStack() {
    stack.clear();
}

GameLog::GameLog() {}
GameLog::~GameLog() {}

shared_ptr<Move> GameLog::redo()
{
    if (redoStack.isEmpty())
    {
        throw runtime_error("Redo stack is empty");
    }
    shared_ptr<Move> lastMove = redoStack.pop();
    // undoStack.push(lastMove);
    return lastMove;
}
shared_ptr<Move> GameLog::undo()
{
    if (undoStack.isEmpty())
    {
        throw runtime_error("Undo stack is empty");
    }
    shared_ptr<Move> lastMove = undoStack.pop();
    // redoStack.push(lastMove);
    return lastMove;
}
void GameLog::undoPush(shared_ptr<Move> m)
{
    undoStack.push(m);
}

void GameLog::redoPush(shared_ptr<Move> m)
{
    redoStack.push(m);
}

void GameLog::clearRedoStack() {
    redoStack.clearStack();
}
