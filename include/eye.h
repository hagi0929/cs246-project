#include <memory>
#include <vector>

#include "gameboard.h"
#include "piece.h"

enum class GameStatus { Ongoing, Checkmate, Stalemate };

class Eye {
  Eye(std::vector<std::shared_ptr<Piece>> pieces,
      std::vector<std::shared_ptr<Piece>> captured);
  std::vector<std::shared_ptr<Piece>> pieces;
  std::vector<std::shared_ptr<Piece>> captured;
  GameStatus gameStatus;
  bool checked[2];
  int turn;
  bool calculateCheck(int playerNum);
  bool calculateStalemate();
  void checkGamestatus();
  std::shared_ptr<Piece> getKing(int playerNum);
  std::vector<std::shared_ptr<Piece>> getPieces(int playerNum);

 public:
  Eye(Gameboard& gameboard);
  std::shared_ptr<Piece> getPiece(Coor);
  std::shared_ptr<Eye> simulateMove(Move move) const;
  bool isChecked(int playerNum);
};