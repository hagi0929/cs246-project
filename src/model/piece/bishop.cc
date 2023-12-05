#include "bishop.h"
using namespace std;

Bishop::Bishop(pair<int, int> coor, int player, shared_ptr<Eyes> eyes)
    : Piece{coor, player, eyes} {}

vector<shared_ptr<Move>> Bishop::possibleMoves(bool checkSafety) const {
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
            if ((eyes->isOccupied({r, c}) && eyes->isOpponent({r, c})) || (!eyes->isOccupied({r, c}))) {
                shared_ptr<Move> m = make_shared<Move>(coor, make_pair(r, c), ' ');
                if ((checkSafety && eyes->isSafeMove(m)) || !checkSafety) {
                    validMoves.emplace_back(make_shared<Move>(coor, make_pair(r, c), ' '));
                }
            }
        }
    }
    return validMoves;
}

char Bishop::getType() const {
    return getPlayer() == 0 ? 'B' : 'b';
}
