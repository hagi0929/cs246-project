#include "gameboard.h"

using namespace std;

GameBoard::GameBoard() : thisTurn{0}, playerColors{{}}
{
  for (int i = 0; i < BOARD_SIZE; ++i)
  {
    for (int j = 0; j < BOARD_SIZE; ++j)
    {
      board[i][j] = make_shared<Cell>(make_pair(i, j));
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
  createPiece(make_pair(0, 0), 'r');
  createPiece(make_pair(0, 1), 'n');
  createPiece(make_pair(0, 2), 'b');
  createPiece(make_pair(0, 3), 'q');
  createPiece(make_pair(0, 4), 'k');
  createPiece(make_pair(0, 5), 'b');
  createPiece(make_pair(0, 6), 'n');
  createPiece(make_pair(0, 7), 'r');
  createPiece(make_pair(1, 0), 'p');
  createPiece(make_pair(1, 1), 'p');
  createPiece(make_pair(1, 2), 'p');
  createPiece(make_pair(1, 3), 'p');
  createPiece(make_pair(1, 4), 'p');
  createPiece(make_pair(1, 5), 'p');
  createPiece(make_pair(1, 6), 'p');
  createPiece(make_pair(1, 7), 'p');
}

GameBoard::~GameBoard() {}

void GameBoard::movePiece(shared_ptr<Move> m)
{
  pair<int, int> cur = m->getCur();
  if (!getCell(cur)->getPiece() || getCell(cur)->getPiece()->getPlayer() != thisTurn)
  {
    throw runtime_error("Wrong piece selected");
  }
  
  vector<shared_ptr<Move>> validMoves = getCell(m->getCur())->getPiece()->possibleMoves();
  if (validMoves.empty()) cout << "its empty" << endl;
  for (auto move : validMoves)
  {
    if (*move == *m)
    {
      shared_ptr<Piece> thisPiece = getCell(m->getCur())->getPiece();

      // player captures enemy piece
      if (!getCell(m->getDest())->isEmpty() && getCell(m->getDest())->getPiece()->getPlayer() != thisTurn)
      {
        m->setCapturedPiece(getCell(m->getDest())->getPiece()->getType());
        m->setCapturedMoveCount(getCell(m->getDest())->getPiece()->getMoveCount());
        removePiece(m->getDest());
      }

      board[m->getDestRow()][m->getDestCol()]->setPiece(board[m->getCurRow()][m->getCurCol()]->getPiece());
      board[m->getCurRow()][m->getCurCol()]->setPiece(nullptr);
      board[m->getDestRow()][m->getDestCol()]->getPiece()->setCoor(m->getDest());

      if (m->getPromotion() != ' ') {
        int moveCount = getCell(m->getDest())->getPiece()->getMoveCount();
        removePiece(m->getDest());
        createPiece(m->getDest(), m->getPromotion());
        getCell(m->getDest())->getPiece()->setMoveCount(moveCount);
      }

      log.save(m);
      getCell(m->getDest())->getPiece()->addMove();
      thisTurn = (thisTurn + 1) % 2;
      return;
    }
  }

  throw runtime_error("Invalid move");
}
void GameBoard::addPiece(shared_ptr<Piece> p, pair<int, int> coor)
{
  board[coor.first][coor.second]->setPiece(p);
}
void GameBoard::removePiece(pair<int, int> coor)
{
  board[coor.first][coor.second]->removePiece();
}
void GameBoard::setTurn(int player) { thisTurn = player; }
void GameBoard::undo() {
  try {
    shared_ptr<Move> m = log.undo();
    thisTurn = (thisTurn + 1) % 2;

    if (m->getPromotion() != ' ') {
      int moveCount = getCell(m->getDest())->getPiece()->getMoveCount();
      removePiece(m->getDest());
      createPiece(m->getDest(), thisTurn == 0 ? 'P' : 'p');
      getCell(m->getDest())->getPiece()->setMoveCount(moveCount);
    }

    board[m->getCurRow()][m->getCurCol()]->setPiece(board[m->getDestRow()][m->getDestCol()]->getPiece());
    board[m->getDestRow()][m->getDestCol()]->setPiece(nullptr);
    board[m->getCurRow()][m->getCurCol()]->getPiece()->setCoor(m->getCur());

    if (m->getCapturedPiece() != ' ') {
      createPiece(m->getDest(), m->getCapturedPiece());
      getCell(m->getDest())->getPiece()->setMoveCount(m->getCapturedMoveCount());
    }

    getCell(m->getCur())->getPiece()->subtractMove();
  } catch (runtime_error &e) {
    throw;
  }
}
void GameBoard::redo() {
  
}
int GameBoard::getThisTurn() const { return thisTurn; }
void GameBoard::resign()
{
  cout << "player " << thisTurn << " has resigned" << endl;
}
shared_ptr<Cell> GameBoard::getCell(pair<int, int> coor) const
{
  return board[coor.first][coor.second];
}

void GameBoard::createPiece(pair<int, int> coor, char p)
{
  shared_ptr<Piece> piece;
  int playerNo;

  if (isupper(p))
  {
    playerNo = 0;
  }
  else
  {
    playerNo = 1;
  }
  p = tolower(p);

  switch (p)
  {
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