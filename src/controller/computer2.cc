#include "computer2.h"

#include <time.h>

using namespace std;

Computer2::Computer2(shared_ptr<Eyes> eye) : Computer{eye} {}

userCmd Computer2::getResponse() {
  cout << endl;
  int turn = eye->getThisTurn();
  vector<pair<shared_ptr<Move>, int>> validMoves;
  for (auto piece : eye->getPieces(turn)) {
    vector<shared_ptr<Move>> pieceValidMoves = piece->possibleMoves(true);
    for (auto move : pieceValidMoves) {
      int score = 0;
      eye->getBoard()->movePiece(move);
      if (move->getCapturedPiece() != ' ') {
        score += 10;
      }

      if (eye->getIsChecked(turn)) {
        score += 10;
      }
      // validate move
      score += rand() % 2;

      eye->getBoard()->undo(false);
      validMoves.emplace_back(make_pair(move, score));
    }
  }
  if (validMoves.size() == 0) {
    return userCmd{cmdType::RESIGN};
  }
  sort(validMoves.begin(), validMoves.end(),
       [](const pair<shared_ptr<Move>, int> &left,
          const pair<shared_ptr<Move>, int> &right) {
         return left.second > right.second;
       });
  vector<pair<shared_ptr<Move>, int>> bestMoves;
  int bestScore = validMoves[0].second;
  for (auto move : validMoves) {
    if (move.second == bestScore) {
      bestMoves.emplace_back(move);
    }
  }
  int index = rand() % bestMoves.size();
  cout << "best move: " << *bestMoves[index].first << endl;
  return userCmd{cmdType::MOVE, bestMoves[index].first->getCmd()};
}