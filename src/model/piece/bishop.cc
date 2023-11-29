#include "bishop.h"

using namespace std;

Bishop::Bishop(pair<int, int> coor, int player, shared_ptr<Eyes> eyes)
    : Piece{coor, player, eyes} {}

vector<shared_ptr<Move>> Bishop::possibleMoves() const
{
    vector<shared_ptr<Move>> validMoves;

    int dirR[] = {-1, -1, 1, 1};
    int dirC[] = {-1, 1, -1, 1};

    for (int i = 0; i < 4; ++i)
    {
        int r = coor.first;
        int c = coor.second;

        while (true)
        {
            r += dirR[i];
            c += dirC[i];

            if (r < 0 || r > 7 || c < 0 || c > 7)
            {
                break;
            }

            if (eyes->isOccupied({r, c}) && !eyes->isOpponent(coor))
            {
                break;
            }
            shared_ptr<Move> mp{new Move{coor, {r, c}, ""}};
            validMoves.emplace_back(mp);
            cout << mp->getCurRow() << "," << mp->getCurCol() + " "
                 << mp->getDestRow() << "," << mp->getDestCol() << endl;
        }
    }
    return validMoves;
}

char Bishop::getType() const
{
    return getPlayer() == 0 ? 'B' : 'b';
}
