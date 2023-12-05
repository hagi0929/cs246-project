#include "computer4.h"

using namespace std;

Computer4::Computer4(shared_ptr<Eyes> eye) : Computer{eye} {}


int Computer4::calculateScore(shared_ptr<Move> move, int depth) {
  int score = 0;
  int turn = eye->getThisTurn();
  vector<pair<shared_ptr<Move>, int>> validMoves;
  for (auto piece : eye->getPieces(turn)) {
    vector<shared_ptr<Move>> pieceValidMoves = piece->possibleMoves(true);
    for (auto move : pieceValidMoves) {
      score -= calculateScore(move, 5);
      validMoves.emplace_back(make_pair(move, score));
    }
  }
}

userCmd Computer4::getResponse() {
  int turn = eye->getThisTurn();
  vector<pair<shared_ptr<Move>, int>> validMoves;
  for (auto piece : eye->getPieces(turn)) {
    vector<shared_ptr<Move>> pieceValidMoves = piece->possibleMoves(true);
    for (auto move : pieceValidMoves) {
      int score = calculateScore(move, 5);
      validMoves.emplace_back(make_pair(move, score));
    }
  }
  // sort by score
  sort(validMoves.begin(), validMoves.end(),
       [](const pair<shared_ptr<Move>, int> &left,
          const pair<shared_ptr<Move>, int> &right) {
         return left.second < right.second;
       });

  return userCmd{cmdType::MOVE, validMoves[0].first->getCmd()};
}