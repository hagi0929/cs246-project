#include "gameboard.h"

using namespace std;

GameBoard::GameBoard() : thisTurn{0}, playerColors{{}} {
  for (int i = 0; i < BOARD_SIZE; ++i) {
    for (int j = 0; j < BOARD_SIZE; ++j) {
      board[i][j] = make_shared<Cell>(make_pair(j, i));
    }
  }
}
void GameBoard::init(shared_ptr<Observer> o) {
  for (int i = 0; i < BOARD_SIZE; ++i) {
    for (int j = 0; j < BOARD_SIZE; ++j) {
      board[i][j]->subscribe(o);
    }
  }
  eyes = make_shared<Eyes>(shared_from_this());
}

GameBoard::~GameBoard() {}
void GameBoard::move(Move &m) { thisTurn = (thisTurn + 1) % 2; }
void GameBoard::addPiece(shared_ptr<Piece> p, pair<int, int> coor) {
  board[coor.first][coor.second]->setPiece(p);
}
void GameBoard::removePiece(pair<int, int> coor) {
  board[coor.first][coor.second]->removePiece();
}
void GameBoard::setTurn(int player) { thisTurn = player; }
void GameBoard::undo(int moves) {}
void GameBoard::redo(int moves) {}
int GameBoard::getThisTurn() const { return thisTurn; }
void GameBoard::resign() {
  cout << "player " << thisTurn << " has resigned" << endl;
}
shared_ptr<Cell> GameBoard::getCell(pair<int, int> coor) const {
  return board[coor.first][coor.second];
}

void GameBoard::createPiece(pair<int, int> coor, char p, int playerNo) {
  shared_ptr<Piece> piece;
  p = tolower(p);
  if (playerNo == -1) {
    playerNo = thisTurn;
  }
  switch (p) {
    case 'p':
      piece = make_shared<Pawn>(coor, playerNo, eyes);
      break;
    case 'r':
      piece = make_shared<Rook>(coor, playerNo, eyes);
      break;
    case 'n':
      piece = make_shared<Knight>(coor, playerNo, eyes);
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
