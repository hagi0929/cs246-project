#include "../Cell/cell.h"
#include "../Player/player.h"
#include "../etc/history.h"
#include "../Display/textdisplay.h"
#include "../Display/graphicsdisplay.h"

const BOARD_SIZE = 8;

class GameBoard {
  Cell board[BOARD_SIZE][BOARD_SIZE];
  history History;
  int thisTurn;
  Player *players[2];
  Color playerColor[2];
  Display displays[2];
  
 public:
  GameBoard();
  ~GameBoard();
  bool isValidMove(Turn t) const;
  bool move(Coor c, Coor c);
  void addPiece(Piece &p, Coor c);
  void removePiece(Coor c);
  void setBeginPlayer(Player &p);
  void undo(int moves);
  void redo(int moves);
  int getThisTurn() const;
};