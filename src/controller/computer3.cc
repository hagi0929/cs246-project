#include "computer.h"


using namespace std;

Computer3::Computer3(Game &game, int playerNum) : Player{game, playerNum} {}

std::shared_ptr<ICommand> Computer3::getCommand() {
  auto snapshot = game.getSnapshot();
  int score = 0;
  Move bestMove = Move{Coor{-1, -1}, Coor{0, 0}, ' '};
  for (auto &piece : snapshot->getPieces(playerNum)) {
    for (auto &move : piece->possibleMoves(*snapshot)) {
      int tempScore = snapshot->calculateScore(move, true);
      if (tempScore > score) {
        bestMove = move;
      }
    }
  }
  if (bestMove.getFrom() == Coor{-1, -1}) {
    throw runtime_error("No possible moves");
  }
  return make_shared<MoveCommand>(bestMove.getFrom(), bestMove.getFrom(),
                                  bestMove.getPromotion());
}
