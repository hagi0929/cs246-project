#include "computer1.h"

using namespace std;

Computer1::Computer1(shared_ptr<Eyes> eye) : Computer{eye} {}

userCmd Computer1::getResponse() {
  int turn = eye->getThisTurn();
  vector<shared_ptr<Move>> validMoves;
  for (auto piece : eye->getPieces(turn)) {
    vector<shared_ptr<Move>> pieceValidMoves = piece->possibleMoves(true);
    for (auto move : pieceValidMoves) {
      validMoves.emplace_back(move);
    }
  }
  if (validMoves.size() == 0) {
    return userCmd{cmdType::RESIGN};
  }

  int randNum = rand() % validMoves.size();
  cout << "randNum " << *validMoves[randNum] << endl;
  return userCmd{cmdType::MOVE, validMoves[randNum]->getCmd()};
}
