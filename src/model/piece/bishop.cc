#include "bishop.h"
using namespace std;

Bishop::Bishop(pair<int, int> coor, int player, shared_ptr<Eyes> eyes)
    : Piece{coor, player, eyes} {}

vector<shared_ptr<Move>> Bishop::possibleMoves() const {
    vector<shared_ptr<Move>> validMoves;

    // Diagonal directions: top-left, top-right, bottom-left, bottom-right
    int dirR[] = {-1, -1, 1, 1};
    int dirC[] = {-1, 1, 1, -1};

    for (int i = 0; i < 4; ++i) {
        int r = coor.first;
        int c = coor.second;

        while (true) {
            r += dirR[i];
            c += dirC[i];

            // Check if the next coordinate is within the board boundaries
            if (r < 0 || r >= 8 || c < 0 || c >= 8) {
                break;
            }

            // Check if the next cell is occupied
            if (eyes->isOccupied({r, c})) {
                // If occupied by an opponent, add as a valid move, then break
                if (eyes->isOpponent({r, c})) {
                    validMoves.emplace_back(make_shared<Move>(coor, make_pair(r, c), ' '));
                }
                break;
            }

            // Add the move if the cell is not occupied
            validMoves.emplace_back(make_shared<Move>(coor, make_pair(r, c), ' '));
        }
    }
    return validMoves;
}

char Bishop::getType() const {
    return getPlayer() == 0 ? 'B' : 'b';
}
