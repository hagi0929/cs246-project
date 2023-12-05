#include "pawn.h"
using namespace std;

Pawn::Pawn(pair<int, int> coor, int player, shared_ptr<Eyes> eyes)
    : Piece{coor, player, eyes} {}

vector<shared_ptr<Move>> Pawn::possibleMoves(bool checkSafety) const {
  vector<shared_ptr<Move>> validMoves;

  if (getPlayer() == 0) {
    if (moveCount == 0 && coor.first - 2 >= 0 &&
        !eyes->isOccupied({coor.first - 2, coor.second})) {
      if (coor.first - 2 > 0) {
        shared_ptr<Move> m{new Move{coor, {coor.first - 2, coor.second}, ' '}};
        if ((checkSafety && eyes->isSafeMove(m)) || !checkSafety) validMoves.emplace_back(m);
      } else {
        shared_ptr<Move> mQueen{new Move{coor, {coor.first - 2, coor.second}, 'Q'}};
        if ((checkSafety && eyes->isSafeMove(mQueen)) || !checkSafety) validMoves.emplace_back(mQueen);
        shared_ptr<Move> mRook{new Move{coor, {coor.first - 2, coor.second}, 'R'}};
        if ((checkSafety && eyes->isSafeMove(mRook)) || !checkSafety) validMoves.emplace_back(mRook);
        shared_ptr<Move> mKnight{new Move{coor, {coor.first - 2, coor.second}, 'N'}};
        if ((checkSafety && eyes->isSafeMove(mKnight)) || !checkSafety) validMoves.emplace_back(mKnight);
        shared_ptr<Move> mBishop{new Move{coor, {coor.first - 2, coor.second}, 'B'}};
        if ((checkSafety && eyes->isSafeMove(mBishop)) || !checkSafety) validMoves.emplace_back(mBishop);
      }
    }
    if (coor.first - 1 >= 0) {
      if (!eyes->isOccupied({coor.first - 1, coor.second})) {
        if (coor.first - 1 > 0) {
          shared_ptr<Move> m{new Move{coor, {coor.first - 1, coor.second}, ' '}};
          if ((checkSafety && eyes->isSafeMove(m)) || !checkSafety) validMoves.emplace_back(m);
        } else {
          shared_ptr<Move> mQueen{new Move{coor, {coor.first - 1, coor.second}, 'Q'}};
          if ((checkSafety && eyes->isSafeMove(mQueen)) || !checkSafety) validMoves.emplace_back(mQueen);
          shared_ptr<Move> mRook{new Move{coor, {coor.first - 1, coor.second}, 'R'}};
          if ((checkSafety && eyes->isSafeMove(mRook)) || !checkSafety) validMoves.emplace_back(mRook);
          shared_ptr<Move> mKnight{new Move{coor, {coor.first - 1, coor.second}, 'N'}};
          if ((checkSafety && eyes->isSafeMove(mKnight)) || !checkSafety) validMoves.emplace_back(mKnight);
          shared_ptr<Move> mBishop{new Move{coor, {coor.first - 1, coor.second}, 'B'}};
          if ((checkSafety && eyes->isSafeMove(mBishop)) || !checkSafety) validMoves.emplace_back(mBishop);
        }
      }
      if (eyes->isOccupied({coor.first - 1, coor.second - 1}) &&
          eyes->isOpponent({coor.first - 1, coor.second - 1})) {
        if (coor.first - 1 > 0) {
          shared_ptr<Move> m{new Move{coor, {coor.first - 1, coor.second - 1}, ' '}};
          if ((checkSafety && eyes->isSafeMove(m)) || !checkSafety) validMoves.emplace_back(m);
        } else {
          shared_ptr<Move> mQueen{new Move{coor, {coor.first - 1, coor.second - 1}, 'Q'}};
          if ((checkSafety && eyes->isSafeMove(mQueen)) || !checkSafety) validMoves.emplace_back(mQueen);
          shared_ptr<Move> mRook{new Move{coor, {coor.first - 1, coor.second - 1}, 'R'}};
          if ((checkSafety && eyes->isSafeMove(mRook)) || !checkSafety) validMoves.emplace_back(mRook);
          shared_ptr<Move> mKnight{new Move{coor, {coor.first - 1, coor.second - 1}, 'N'}};
          if ((checkSafety && eyes->isSafeMove(mKnight)) || !checkSafety) validMoves.emplace_back(mKnight);
          shared_ptr<Move> mBishop{new Move{coor, {coor.first - 1, coor.second - 1}, 'B'}};
          if ((checkSafety && eyes->isSafeMove(mBishop)) || !checkSafety) validMoves.emplace_back(mBishop);
        }
      }
      if (eyes->isOccupied({coor.first - 1, coor.second + 1}) &&
          eyes->isOpponent({coor.first - 1, coor.second + 1})) {
        if (coor.first - 1 > 0) {
          shared_ptr<Move> m{new Move{coor, {coor.first - 1, coor.second + 1}, ' '}};
          if ((checkSafety && eyes->isSafeMove(m)) || !checkSafety) validMoves.emplace_back(m);
        } else {
          shared_ptr<Move> mQueen{new Move{coor, {coor.first - 1, coor.second + 1}, 'Q'}};
          if ((checkSafety && eyes->isSafeMove(mQueen)) || !checkSafety) validMoves.emplace_back(mQueen);
          shared_ptr<Move> mRook{new Move{coor, {coor.first - 1, coor.second + 1}, 'R'}};
          if ((checkSafety && eyes->isSafeMove(mRook)) || !checkSafety) validMoves.emplace_back(mRook);
          shared_ptr<Move> mKnight{new Move{coor, {coor.first - 1, coor.second + 1}, 'N'}};
          if ((checkSafety && eyes->isSafeMove(mKnight)) || !checkSafety) validMoves.emplace_back(mKnight);
          shared_ptr<Move> mBishop{new Move{coor, {coor.first - 1, coor.second + 1}, 'B'}};
          if ((checkSafety && eyes->isSafeMove(mBishop)) || !checkSafety) validMoves.emplace_back(mBishop);
        }
      }
    }
  } else if (getPlayer() == 1) {
    if (moveCount == 0 && coor.first + 2 <= 7 &&
        !eyes->isOccupied({coor.first + 2, coor.second})) {
      if (coor.first + 2 < 7) {
        shared_ptr<Move> m{new Move{coor, {coor.first + 2, coor.second}, ' '}};
        if ((checkSafety && eyes->isSafeMove(m)) || !checkSafety) validMoves.emplace_back(m);
      } else {
        shared_ptr<Move> mQueen{new Move{coor, {coor.first + 2, coor.second}, 'q'}};
        if ((checkSafety && eyes->isSafeMove(mQueen)) || !checkSafety) validMoves.emplace_back(mQueen);
        shared_ptr<Move> mRook{new Move{coor, {coor.first + 2, coor.second}, 'r'}};
        if ((checkSafety && eyes->isSafeMove(mRook)) || !checkSafety) validMoves.emplace_back(mRook);
        shared_ptr<Move> mKnight{new Move{coor, {coor.first + 2, coor.second}, 'n'}};
        if ((checkSafety && eyes->isSafeMove(mKnight)) || !checkSafety) validMoves.emplace_back(mKnight);
        shared_ptr<Move> mBishop{new Move{coor, {coor.first + 2, coor.second}, 'b'}};
        if ((checkSafety && eyes->isSafeMove(mBishop)) || !checkSafety) validMoves.emplace_back(mBishop);
      }
    }
    if (coor.first + 1 <= 7) {
      if (!eyes->isOccupied({coor.first + 1, coor.second})) {
        if (coor.first + 1 < 7) {
          shared_ptr<Move> m{new Move{coor, {coor.first + 1, coor.second}, ' '}};
          if ((checkSafety && eyes->isSafeMove(m)) || !checkSafety) validMoves.emplace_back(m);
        } else {
          shared_ptr<Move> mQueen{new Move{coor, {coor.first + 1, coor.second}, 'q'}};
          if ((checkSafety && eyes->isSafeMove(mQueen)) || !checkSafety) validMoves.emplace_back(mQueen);
          shared_ptr<Move> mRook{new Move{coor, {coor.first + 1, coor.second}, 'r'}};
          if ((checkSafety && eyes->isSafeMove(mRook)) || !checkSafety) validMoves.emplace_back(mRook);
          shared_ptr<Move> mKnight{new Move{coor, {coor.first + 1, coor.second}, 'n'}};
          if ((checkSafety && eyes->isSafeMove(mKnight)) || !checkSafety) validMoves.emplace_back(mKnight);
          shared_ptr<Move> mBishop{new Move{coor, {coor.first + 1, coor.second}, 'b'}};
          if ((checkSafety && eyes->isSafeMove(mBishop)) || !checkSafety) validMoves.emplace_back(mBishop);
        }
      }
      if (eyes->isOccupied({coor.first + 1, coor.second - 1}) &&
          eyes->isOpponent({coor.first + 1, coor.second - 1})) {
        if (coor.first + 1 < 7) {
          shared_ptr<Move> m{new Move{coor, {coor.first + 1, coor.second - 1}, ' '}};
          if ((checkSafety && eyes->isSafeMove(m)) || !checkSafety) validMoves.emplace_back(m);
        } else {
          shared_ptr<Move> mQueen{new Move{coor, {coor.first + 1, coor.second - 1}, 'q'}};
          if ((checkSafety && eyes->isSafeMove(mQueen)) || !checkSafety) validMoves.emplace_back(mQueen);
          shared_ptr<Move> mRook{new Move{coor, {coor.first + 1, coor.second - 1}, 'r'}};
          if ((checkSafety && eyes->isSafeMove(mRook)) || !checkSafety) validMoves.emplace_back(mRook);
          shared_ptr<Move> mKnight{new Move{coor, {coor.first + 1, coor.second - 1}, 'n'}};
          if ((checkSafety && eyes->isSafeMove(mKnight)) || !checkSafety) validMoves.emplace_back(mKnight);
          shared_ptr<Move> mBishop{new Move{coor, {coor.first + 1, coor.second - 1}, 'b'}};
          if ((checkSafety && eyes->isSafeMove(mBishop)) || !checkSafety) validMoves.emplace_back(mBishop);
        }
      }
      if (eyes->isOccupied({coor.first + 1, coor.second + 1}) &&
          eyes->isOpponent({coor.first + 1, coor.second + 1})) {
        if (coor.first + 1 < 7) {
          shared_ptr<Move> m{new Move{coor, {coor.first + 1, coor.second + 1}, ' '}};
          if ((checkSafety && eyes->isSafeMove(m)) || !checkSafety) validMoves.emplace_back(m);
        } else {
          shared_ptr<Move> mQueen{new Move{coor, {coor.first + 1, coor.second + 1}, 'q'}};
          if ((checkSafety && eyes->isSafeMove(mQueen)) || !checkSafety) validMoves.emplace_back(mQueen);
          shared_ptr<Move> mRook{new Move{coor, {coor.first + 1, coor.second + 1}, 'r'}};
          if ((checkSafety && eyes->isSafeMove(mRook)) || !checkSafety) validMoves.emplace_back(mRook);
          shared_ptr<Move> mKnight{new Move{coor, {coor.first + 1, coor.second + 1}, 'n'}};
          if ((checkSafety && eyes->isSafeMove(mKnight)) || !checkSafety) validMoves.emplace_back(mKnight);
          shared_ptr<Move> mBishop{new Move{coor, {coor.first + 1, coor.second + 1}, 'b'}};
          if ((checkSafety && eyes->isSafeMove(mBishop)) || !checkSafety) validMoves.emplace_back(mBishop);
        }
      }
    }
  }

  return validMoves;
}

char Pawn::getType() const {
  return getPlayer() == 0 ? 'P' : 'p';
}
