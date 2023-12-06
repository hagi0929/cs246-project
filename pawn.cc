#include "pawn.h"
using namespace std;

Pawn::Pawn(pair<int, int> coor, int player, shared_ptr<Eyes> eyes)
    : Piece{coor, player, eyes} {}

vector<shared_ptr<Move>> Pawn::possibleMoves(bool checkSafety) const {
  vector<shared_ptr<Move>> validMoves;
  vector<pair<int, int>> moveDirections;
  vector<pair<int, int>> attackDirections;
  const pair<int, int> coor = getCoor();
  const int moveCount = getMoveCount();
  const int player = getPlayer();
  const int opponent = player == 0 ? 1 : 0;
  if (getPlayer() == 0) {
    if (moveCount == 0 && coor.first - 2 >= 0 &&
        !eyes->isOccupied({coor.first - 1, coor.second})) {
      moveDirections.emplace_back(-2, 0);
    }
    moveDirections.emplace_back(-1, 0);
    attackDirections.emplace_back(-1, -1);
    attackDirections.emplace_back(-1, 1);
  } else if (getPlayer() == 1) {
    if (moveCount == 0 && coor.first + 2 <= 7 &&
        !eyes->isOccupied({coor.first + 1, coor.second})) {
      moveDirections.emplace_back(2, 0);
    }
    moveDirections.emplace_back(1, 0);
    attackDirections.emplace_back(1, -1);
    attackDirections.emplace_back(1, 1);
  }

  for (auto &dir : moveDirections) {
    const pair<int, int> nextCoor = {coor.first + dir.first,
                               coor.second + dir.second};
    if (nextCoor.first >= 0 && nextCoor.first <= 7 && nextCoor.second >= 0 &&
        nextCoor.second <= 7 && (coor.second != nextCoor.second ||
        coor.first != nextCoor.first)) {
      if (!eyes->isOccupied(nextCoor)) {
        if (nextCoor.first == 0 || nextCoor.first == 7) {
          shared_ptr<Move> mQueen{
              new Move{coor, nextCoor, getPlayer() == 0 ? 'Q' : 'q', "0"}};
          if ((checkSafety && eyes->isSafeMove(mQueen)) || !checkSafety)
            validMoves.emplace_back(mQueen);
          shared_ptr<Move> mRook{
              new Move{coor, nextCoor, getPlayer() == 0 ? 'R' : 'r', "4"}};
          if ((checkSafety && eyes->isSafeMove(mRook)) || !checkSafety)
            validMoves.emplace_back(mRook);
          shared_ptr<Move> mKnight{
              new Move{coor, nextCoor, getPlayer() == 0 ? 'N' : 'n', "8"}};
          if ((checkSafety && eyes->isSafeMove(mKnight)) || !checkSafety)
            validMoves.emplace_back(mKnight);
          shared_ptr<Move> mBishop{
              new Move{coor, nextCoor, getPlayer() == 0 ? 'B' : 'b', "12"}};
          if ((checkSafety && eyes->isSafeMove(mBishop)) || !checkSafety)
            validMoves.emplace_back(mBishop);
        } else {
          shared_ptr<Move> m{
              new Move{coor, nextCoor, getPlayer() == 0 ? ' ' : ' ', "16"}};
          if ((checkSafety && eyes->isSafeMove(m)) || !checkSafety)
            validMoves.emplace_back(m);
        }
      }
    }
  }
  for (auto &dir : attackDirections) {
    const pair<int, int> nextCoor = {coor.first + dir.first,
                               coor.second + dir.second};

    if (nextCoor.first >= 0 && nextCoor.first <= 7 && nextCoor.second >= 0 &&
        nextCoor.second <= 7 && (coor.second != nextCoor.second ||
        coor.first != nextCoor.first)) {
      if (eyes->isOccupied(nextCoor) &&
          eyes->isOpponent(nextCoor)) {  // opponent piece
        if (nextCoor.first == 0 || nextCoor.first == 7) {
          shared_ptr<Move> mQueen{
              new Move{coor, nextCoor, getPlayer() == 0 ? 'Q' : 'q', "20"}};
          if ((checkSafety && eyes->isSafeMove(mQueen)) || !checkSafety)
            validMoves.emplace_back(mQueen);
          shared_ptr<Move> mRook{
              new Move{coor, nextCoor, getPlayer() == 0 ? 'R' : 'r', "24"}};
          if ((checkSafety && eyes->isSafeMove(mRook)) || !checkSafety)
            validMoves.emplace_back(mRook);
          shared_ptr<Move> mKnight{
              new Move{coor, nextCoor, getPlayer() == 0 ? 'N' : 'n', "28"}};
          if ((checkSafety && eyes->isSafeMove(mKnight)) || !checkSafety)
            validMoves.emplace_back(mKnight);
          shared_ptr<Move> mBishop{
              new Move{coor, nextCoor, getPlayer() == 0 ? 'B' : 'b', "32"}};
          if ((checkSafety && eyes->isSafeMove(mBishop)) || !checkSafety)
            validMoves.emplace_back(mBishop);
        } else {
          shared_ptr<Move> m{
              new Move{coor, nextCoor, getPlayer() == 0 ? ' ' : ' ', "36"}};
          if ((checkSafety && eyes->isSafeMove(m)) || !checkSafety)
            validMoves.emplace_back(m);
        }
      }
    }
  }
  return validMoves;
}

char Pawn::getType() const { return getPlayer() == 0 ? 'P' : 'p'; }
