#include "computer3.h"
using namespace std;

Computer3::Computer3(shared_ptr<Eyes> eye) : Computer{eye} {}

int Computer3::calculateScore(shared_ptr<Move> move) {
  int score = 0;
  eye->getBoard()->movePiece(move);
  if (eye->getIsChecked(eye->getThisTurn())) {
    score += 10;
  }
  int turn = eye->getThisTurn();
  vector<pair<shared_ptr<Move>, int>> validMoves;
  for (auto piece : eye->getPieces(turn + 1 % 2)) {
    vector<shared_ptr<Move>> pieceValidMoves = piece->possibleMoves(false);
    for (auto move : pieceValidMoves) {
      if (move->getCapturedPiece() != ' ') {
        score -= 5;
      }
    }
  }

  eye->getBoard()->undo(false);
  if (move->getCapturedPiece() != ' ') {
    score += 5;
  }
  return score;
}

userCmd Computer3::getResponse() {
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
      for (auto &enemyPiece : eye->getPieces((eye->getThisTurn()) % 2)) {
        vector<shared_ptr<Move>> enemyPieceValidMoves =
            enemyPiece->possibleMoves(false);
        for (auto enemyMove : enemyPieceValidMoves) {
          if (enemyMove->getCapturedPiece() != '10') {
            score -= 5;
          }
        }
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
  // sort by score than pick the highest score randomly
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