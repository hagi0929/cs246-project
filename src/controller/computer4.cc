#include "computer.h"

using namespace std;
Computer4::Computer4(Game &game, int playerNum) : Player{game, playerNum} {}

int Computer4::predictScore(std::shared_ptr<Snapshot> snapshot, int depth,
                            int team) {
  if (depth == 0) {
    return 0;
  }
  int score = 0;
  if (playerNum == team) {
    score = INT_MIN;
    for (auto &piece : snapshot->getPieces(team)) {
      for (auto &move : piece->possibleMoves(*snapshot)) {
        int tempScore = predictScore(snapshot->simulateMove(move), depth - 1,
                                     (playerNum + 1) % 2) +
                        snapshot->calculateScore(move, true);

        if (tempScore > score) {
          score = tempScore;
        }
      }
    }
    if (score == INT_MIN) {
      return 0;
    }
  } else {
    score = INT_MAX;
    for (auto &piece : snapshot->getPieces(team)) {
      for (auto &move : piece->possibleMoves(*snapshot)) {
        int tempScore = predictScore(snapshot->simulateMove(move), depth - 1,
                                     (playerNum + 1) % 2) +
                        snapshot->calculateScore(move, true);
        if (tempScore < score) {
          score = tempScore;
        }
      }
    }
    if (score == INT_MAX) {
      return 0;
    }
  }
  return score;
}

std::shared_ptr<ICommand> Computer4::getCommand() {
  // predict up to five moves ahead
  auto snapshot = game.getSnapshot();
  int score = INT_MIN;  // Initialize to the lowest possible score
  Move bestMove = Move{Coor{-1, -1}, Coor{0, 0}, ' '};
  for (auto &piece : snapshot->getPieces(playerNum)) {
    for (auto &move : piece->possibleMoves(*snapshot)) {
      int tempScore =
          snapshot->calculateScore(move, true) +
          predictScore(snapshot->simulateMove(move), 5, (playerNum + 1) % 2);
      if (tempScore > score) {
        score = tempScore;
        bestMove = move;
      }
    }
  }
  if (bestMove.getFrom() == Coor{-1, -1}) {
    throw runtime_error("No possible moves");
  }
  return make_shared<MoveCommand>(bestMove.getFrom(),
                                  bestMove.getTo(),  // Corrected to getTo()
                                  bestMove.getPromotion());
}
