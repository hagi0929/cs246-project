#include "gamelog.h"

#include <iostream>
using namespace std;

EmptyStackException::~EmptyStackException() {}

RedoEmptyStackException::~RedoEmptyStackException() {}

UndoEmptyStackException::~UndoEmptyStackException() {}

const char *RedoEmptyStackException::what() const noexcept
{
    return "Redo stack is empty";
}

const char *UndoEmptyStackException::what() const noexcept
{
    return "Undo stack is empty";
}

Move Stack::pop()
{
    if (isEmpty())
    {
        throw EmptyStackException();
    }
    Move top = peek();
    stack.pop_back();
    return top;
    /*
    1st Get to the top of the elements
    2nd Remove the element
    */
}
void Stack::push(Move m)
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
Move Stack::peek()
{
    return stack.back();
}

GameLog::GameLog() {}
GameLog::~GameLog() {}

Move GameLog::redo(int n = 0)
{
    try
    {
        Move lastMove = redoStack.pop();
        undoStack.push(lastMove);
        return lastMove;
    }
    catch (EmptyStackException &e)
    {
        throw RedoEmptyStackException();
    }
}
Move GameLog::undo(int n = 0)
{
    try
    {
        Move lastMove = undoStack.pop();
        redoStack.push(lastMove);
        return lastMove;
    }
    catch (EmptyStackException &e)
    {
        throw UndoEmptyStackException();
    }
}
void GameLog::save(Move m)
{
    undoStack.push(m);
}

void GameLog::showLog()
{
    // TO DO: show all game log to player
}

void GameLog::save()
{
    // TO DO:save all moves into a file(ex : game1.txt)
}
