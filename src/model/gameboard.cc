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
  createPiece(make_pair(7, 0), 'R');
  createPiece(make_pair(7, 1), 'N');
  createPiece(make_pair(7, 2), 'B');
  createPiece(make_pair(7, 3), 'Q');
  createPiece(make_pair(7, 4), 'K');
  createPiece(make_pair(7, 5), 'B');
  createPiece(make_pair(7, 6), 'N');
  createPiece(make_pair(7, 7), 'R');
  createPiece(make_pair(6, 0), 'P');
  createPiece(make_pair(6, 1), 'P');
  createPiece(make_pair(6, 2), 'P');
  createPiece(make_pair(6, 3), 'P');
  createPiece(make_pair(6, 4), 'P');
  createPiece(make_pair(6, 5), 'P');
  createPiece(make_pair(6, 6), 'P');
  createPiece(make_pair(6, 7), 'P');
  createPiece(make_pair(0, 0), 'r', 1);
  createPiece(make_pair(0, 1), 'n', 1);
  createPiece(make_pair(0, 2), 'b', 1);
  createPiece(make_pair(0, 3), 'q', 1);
  createPiece(make_pair(0, 4), 'k', 1);
  createPiece(make_pair(0, 5), 'b', 1);
  createPiece(make_pair(0, 6), 'n', 1);
  createPiece(make_pair(0, 7), 'r', 1);
  createPiece(make_pair(1, 0), 'p', 1);
  createPiece(make_pair(1, 1), 'p', 1);
  createPiece(make_pair(1, 2), 'p', 1);
  createPiece(make_pair(1, 3), 'p', 1);
  createPiece(make_pair(1, 4), 'p', 1);
  createPiece(make_pair(1, 5), 'p', 1);
  createPiece(make_pair(1, 6), 'p', 1);
  createPiece(make_pair(1, 7), 'p', 1);
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
