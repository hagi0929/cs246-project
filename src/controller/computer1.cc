#include "computer.h"

using namespace std;

Computer1::Computer1(Game &game, int playerNum) : Player{game, playerNum} {}

shared_ptr<ICommand> Computer1::getCommand() {
  // ranfomly choose a move
  auto snapshot = game.getSnapshot();
  vector<Move> moves = vector<Move>{};
  for (auto &piece : snapshot->getPieces(playerNum)) {
    for (auto &move : piece->possibleMoves(*snapshot)) {
      moves.emplace_back(move);
    }
  }
  int random = rand() % moves.size();
  auto move = moves[random];
  return make_shared<MoveCommand>(move.getFrom(), move.getTo(),
                                  move.getPromotion());
}