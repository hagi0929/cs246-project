#include "computer4.h"

using namespace std;

Computer4::Computer4(shared_ptr<Eyes> eye) : Computer{eye} {}

int Computer4::calculateScore(shared_ptr<Move> move, int depth) {
  if (depth == 0) {
    return 0;
  }
  int score = 0;
  eye->getBoard()->doValidMove(move);
  if (tolower(move->getCapturedPiece()) == 'k') {
    score += 100;
  }
  if (tolower(move->getCapturedPiece()) == 'q') {
    score += 40;
  }
  if (tolower(move->getCapturedPiece()) == 'r') {
    score += 25;
  }
  if (tolower(move->getCapturedPiece()) == 'b') {
    score += 25;
  }
  if (tolower(move->getCapturedPiece()) == 'n') {
    score += 20;
  }
  if (tolower(move->getCapturedPiece()) == 'p') {
    score += 10;
  }
  if (eye->getIsChecked(eye->getThisTurn())) {
    score += 20;
  }
  if (eye->getIsCheckmated(eye->getThisTurn())) {
    score += 200;
  }
  int turn = eye->getThisTurn();
  int enemyScore = -10;
  vector<pair<shared_ptr<Move>, int>> validMoves;
  for (auto piece : eye->getPieces(turn + 1 % 2)) {
    vector<shared_ptr<Move>> pieceValidMoves = piece->possibleMoves(false);
    for (auto &enemyMove : pieceValidMoves) {
      enemyScore = max(calculateScore(move, depth - 1), enemyScore);
    }
  }

  eye->getBoard()->undo(false);
  return score - enemyScore;
}

userCmd Computer4::getResponse() {
  cout << "Computer4's turn" << endl;
  int turn = eye->getThisTurn();
  vector<pair<shared_ptr<Move>, int>> validMoves;
  int score = 0;
  cout << eye->getPieces(turn).size() << endl;
  for (auto piece : eye->getPieces(turn)) {
    vector<shared_ptr<Move>> pieceValidMoves = piece->possibleMoves(true);
    cout << "piece: " << piece->getType() << endl;
    for (auto move : pieceValidMoves) {
      score = calculateScore(move, 5);
      cout << *move << " " << score << endl;
      validMoves.emplace_back(make_pair(move, score));
    }
  }
  if (validMoves.size() == 0) {
    return userCmd{cmdType::QUIT};
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
  for (auto move : bestMoves) {
    cout << *move.first << " " << move.second << endl;
  }
  cout << "best move: " << *bestMoves[index].first << endl;
  return userCmd{cmdType::MOVE, bestMoves[index].first->getCmd()};
}
