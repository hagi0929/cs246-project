#include "knight.h"
#include "snapshot.h"
#include "piece.h"

using namespace std;

Knight::Knight(Coor coor, int player, int moveCount)
    : Piece(coor, player, moveCount) {}

Knight::Knight(Piece* other)
    : Piece(other->getCoor(), other->getPlayer(), other->getMoveCount()) {}

Knight::Knight(Knight& other)
    : Piece(other.getCoor(), other.getPlayer(), other.getMoveCount()) {}

vector<Move> Knight::possibleMoves(Snapshot& snapshot, bool safetyCheck) const {
    vector<Move> validMoves;
    vector<Coor> directions = {Coor(-2, -1), Coor(-2, 1), Coor(-1, -2), Coor(-1, 2),
                               Coor(1, -2), Coor(1, 2), Coor(2, -1), Coor(2, 1)};
    
    for (Coor direction : directions) {
        Coor nextCoor = this->coor + direction;
        if (!nextCoor.isInbound()) continue;
        if (snapshot.isEmpty(nextCoor) || snapshot.isEnemy(nextCoor, player)) {
            validMoves.emplace_back(Move{getCoor(), nextCoor});
        }
    }

    if (safetyCheck) {
        vector<Move> finalMoves;
        for (Move m : validMoves) {
            if (!snapshot.simulateMove(m)->isChecked(player)) {
                finalMoves.emplace_back(m);
            }
        }
        return finalMoves;
    } else {
        return validMoves;
    }
}shared_ptr<Piece> Knight::clone() {
    return make_shared<Knight>(*this);
}

char Knight::getType() const {
    return 'N'; // 'N' for Knight
}

int Knight::getValue() const {
    return 3;
}