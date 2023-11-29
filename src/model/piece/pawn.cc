#include "pawn.h"
using namespace std;

Pawn::Pawn(pair<int, int> coor, int player, shared_ptr<Eyes> eyes)
    : Piece{coor, player, eyes} {}

vector<shared_ptr<Move>> Pawn::possibleMoves() const {
  vector<shared_ptr<Move>> validMoves;

  if (getPlayer() == 0) {
    if (moveCount == 0 && coor.first - 2 >= 0 &&
        !eyes->isOccupied({coor.first - 2, coor.second})) {
      if (coor.first - 2 > 0) {
        shared_ptr<Move> mp{new Move{coor, {coor.first - 2, coor.second}, ""}};
        validMoves.emplace_back(mp);
      } else {
        shared_ptr<Move> mpQueen{new Move{coor, {coor.first - 2, coor.second}, "queen"}};
        validMoves.emplace_back(mpQueen);
        shared_ptr<Move> mpRook{new Move{coor, {coor.first - 2, coor.second}, "rook"}};
        validMoves.emplace_back(mpRook);
        shared_ptr<Move> mpKnight{new Move{coor, {coor.first - 2, coor.second}, "knight"}};
        validMoves.emplace_back(mpKnight);
        shared_ptr<Move> mpBishop{new Move{coor, {coor.first - 2, coor.second}, "bishop"}};
        validMoves.emplace_back(mpBishop);
      }
    }
    if (coor.first - 1 >= 0) {
      if (!eyes->isOccupied({coor.first - 1, coor.second})) {
        if (coor.first - 1 > 0) {
          shared_ptr<Move> mp{new Move{coor, {coor.first - 1, coor.second}, ""}};
          validMoves.emplace_back(mp);
        } else {
          shared_ptr<Move> mpQueen{new Move{coor, {coor.first - 1, coor.second}, "queen"}};
          validMoves.emplace_back(mpQueen);
          shared_ptr<Move> mpRook{new Move{coor, {coor.first - 1, coor.second}, "rook"}};
          validMoves.emplace_back(mpRook);
          shared_ptr<Move> mpKnight{new Move{coor, {coor.first - 1, coor.second}, "knight"}};
          validMoves.emplace_back(mpKnight);
          shared_ptr<Move> mpBishop{new Move{coor, {coor.first - 1, coor.second}, "bishop"}};
          validMoves.emplace_back(mpBishop);
        }
      }
      if (eyes->isOccupied({coor.first - 1, coor.second - 1}) &&
          eyes->isOpponent({coor.first - 1, coor.second - 1})) {
        if (coor.first - 1 > 0) {
          shared_ptr<Move> mp{new Move{coor, {coor.first - 1, coor.second - 1}, ""}};
          validMoves.emplace_back(mp);
        } else {
          shared_ptr<Move> mpQueen{new Move{coor, {coor.first - 1, coor.second - 1}, "queen"}};
          validMoves.emplace_back(mpQueen);
          shared_ptr<Move> mpRook{new Move{coor, {coor.first - 1, coor.second - 1}, "rook"}};
          validMoves.emplace_back(mpRook);
          shared_ptr<Move> mpKnight{new Move{coor, {coor.first - 1, coor.second - 1}, "knight"}};
          validMoves.emplace_back(mpKnight);
          shared_ptr<Move> mpBishop{new Move{coor, {coor.first - 1, coor.second - 1}, "bishop"}};
          validMoves.emplace_back(mpBishop);
        }
      }
      if (eyes->isOccupied({coor.first - 1, coor.second + 1}) &&
          eyes->isOpponent({coor.first - 1, coor.second + 1})) {
        if (coor.first - 1 > 0) {
          shared_ptr<Move> mp{new Move{coor, {coor.first - 1, coor.second + 1}, ""}};
          validMoves.emplace_back(mp);
        } else {
          shared_ptr<Move> mpQueen{new Move{coor, {coor.first - 1, coor.second + 1}, "queen"}};
          validMoves.emplace_back(mpQueen);
          shared_ptr<Move> mpRook{new Move{coor, {coor.first - 1, coor.second + 1}, "rook"}};
          validMoves.emplace_back(mpRook);
          shared_ptr<Move> mpKnight{new Move{coor, {coor.first - 1, coor.second + 1}, "knight"}};
          validMoves.emplace_back(mpKnight);
          shared_ptr<Move> mpBishop{new Move{coor, {coor.first - 1, coor.second + 1}, "bishop"}};
          validMoves.emplace_back(mpBishop);
        }
      }
    }
  } else if (getPlayer() == 1) {
    if (moveCount == 0 && coor.first + 2 <= 7 &&
        !eyes->isOccupied({coor.first + 2, coor.second})) {
      if (coor.first + 2 < 7) {
        shared_ptr<Move> mp{new Move{coor, {coor.first + 2, coor.second}, ""}};
        validMoves.emplace_back(mp);
      } else {
        shared_ptr<Move> mpQueen{new Move{coor, {coor.first + 2, coor.second}, "queen"}};
        validMoves.emplace_back(mpQueen);
        shared_ptr<Move> mpRook{new Move{coor, {coor.first + 2, coor.second}, "rook"}};
        validMoves.emplace_back(mpRook);
        shared_ptr<Move> mpKnight{new Move{coor, {coor.first + 2, coor.second}, "knight"}};
        validMoves.emplace_back(mpKnight);
        shared_ptr<Move> mpBishop{new Move{coor, {coor.first + 2, coor.second}, "bishop"}};
        validMoves.emplace_back(mpBishop);
      }
    }
    if (coor.first + 1 <= 7) {
      if (!eyes->isOccupied({coor.first + 1, coor.second})) {
        if (coor.first + 1 < 7) {
          shared_ptr<Move> mp{new Move{coor, {coor.first + 1, coor.second}, ""}};
          validMoves.emplace_back(mp);
        } else {
          shared_ptr<Move> mpQueen{new Move{coor, {coor.first + 1, coor.second}, "queen"}};
          validMoves.emplace_back(mpQueen);
          shared_ptr<Move> mpRook{new Move{coor, {coor.first + 1, coor.second}, "rook"}};
          validMoves.emplace_back(mpRook);
          shared_ptr<Move> mpKnight{new Move{coor, {coor.first + 1, coor.second}, "knight"}};
          validMoves.emplace_back(mpKnight);
          shared_ptr<Move> mpBishop{new Move{coor, {coor.first + 1, coor.second}, "bishop"}};
          validMoves.emplace_back(mpBishop);
        }
      }
      if (eyes->isOccupied({coor.first + 1, coor.second - 1}) &&
          eyes->isOpponent({coor.first + 1, coor.second - 1})) {
        if (coor.first + 1 < 7) {
          shared_ptr<Move> mp{new Move{coor, {coor.first + 1, coor.second - 1}, ""}};
          validMoves.emplace_back(mp);
        } else {
          shared_ptr<Move> mpQueen{new Move{coor, {coor.first + 1, coor.second - 1}, "queen"}};
          validMoves.emplace_back(mpQueen);
          shared_ptr<Move> mpRook{new Move{coor, {coor.first + 1, coor.second - 1}, "rook"}};
          validMoves.emplace_back(mpRook);
          shared_ptr<Move> mpKnight{new Move{coor, {coor.first + 1, coor.second - 1}, "knight"}};
          validMoves.emplace_back(mpKnight);
          shared_ptr<Move> mpBishop{new Move{coor, {coor.first + 1, coor.second - 1}, "bishop"}};
          validMoves.emplace_back(mpBishop);
        }
      }
      if (eyes->isOccupied({coor.first + 1, coor.second + 1}) &&
          eyes->isOpponent({coor.first + 1, coor.second + 1})) {
        if (coor.first + 1 < 7) {
          shared_ptr<Move> mp{new Move{coor, {coor.first + 1, coor.second + 1}, ""}};
          validMoves.emplace_back(mp);
        } else {
          shared_ptr<Move> mpQueen{new Move{coor, {coor.first + 1, coor.second + 1}, "queen"}};
          validMoves.emplace_back(mpQueen);
          shared_ptr<Move> mpRook{new Move{coor, {coor.first + 1, coor.second + 1}, "rook"}};
          validMoves.emplace_back(mpRook);
          shared_ptr<Move> mpKnight{new Move{coor, {coor.first + 1, coor.second + 1}, "knight"}};
          validMoves.emplace_back(mpKnight);
          shared_ptr<Move> mpBishop{new Move{coor, {coor.first + 1, coor.second + 1}, "bishop"}};
          validMoves.emplace_back(mpBishop);
        }
      }
    }
  }

  return validMoves;
}

char Pawn::getType() const {
  return getPlayer() == 0 ? 'P' : 'p';
}
