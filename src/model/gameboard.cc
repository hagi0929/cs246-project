#include "gameboard.h"

using namespace std;

GameBoard::GameBoard() : thisTurn{0}, playerColors{{}}
{
  cout << "game has been started" << endl;
  for (int i = 0; i < BOARD_SIZE; ++i)
  {
    for (int j = 0; j < BOARD_SIZE; ++j)
    {
      board[i][j] = make_shared<Cell>(make_pair(j, i));
    }
  }
}
void GameBoard::init(shared_ptr<Observer> o)
{
  for (int i = 0; i < BOARD_SIZE; ++i)
  {
    for (int j = 0; j < BOARD_SIZE; ++j)
    {
      board[i][j]->subscribe(o);
    }
  }
  eyes = make_shared<Eyes>(shared_from_this());
}

GameBoard::~GameBoard() { cout << "GameBoard dtor is called" << endl; }
void GameBoard::move(Move &m) { thisTurn = (thisTurn + 1) % 2; }
void GameBoard::addPiece(shared_ptr<Piece> p, pair<int, int> coor)
{
  cout << endl
       << "row: " << coor.second << " col: " << coor.first << " Piece: " << p << endl;
  board[coor.first][coor.second]->setPiece(p);
}
void GameBoard::removePiece(pair<int, int> coor)
{
  board[coor.first][coor.second]->removePiece();
}
void GameBoard::setTurn(int player) { thisTurn = player; }
void GameBoard::undo(int moves) { cout << "GameBoard::undo is called" << endl; }
void GameBoard::redo(int moves) { cout << "GameBoard::redo is called" << endl; }
int GameBoard::getThisTurn() const { return thisTurn; }
void GameBoard::resign()
{
  cout << "player " << thisTurn << " is called" << endl;
}
shared_ptr<Cell> GameBoard::getCell(pair<int, int> coor) const
{
  return board[coor.first][coor.second];
}

void GameBoard::createPiece(pair<int, int> coor, char p, int playerNo)
{
  cout << endl
       << "row: " << coor.second << " col: " << coor.first << " Piece: " << p << " Player: " << playerNo << endl;
  shared_ptr<Piece> piece;
  p = tolower(p);
  if (playerNo == -1)
  {
    playerNo = thisTurn;
  }
  switch (p)
  {
  case 'p':
    break;
  case 'r':
    piece = make_shared<Rook>(coor, playerNo, eyes);
    break;
  case 'n':
    break;
  case 'b':
    piece = make_shared<Bishop>(coor, playerNo, eyes);
    break;
  case 'q':
    piece = make_shared<Queen>(coor, playerNo, eyes);
    break;
  case 'k':
    piece = make_shared<King>(coor, playerNo, eyes);
    break;
  default:
    cerr << "Invalid piece type" << endl;
    return;
  }
  addPiece(piece, coor);
}
