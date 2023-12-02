#include "rook.h"

using namespace std;

Rook::Rook(pair<int, int> coor, int player, shared_ptr<Eyes> eyes)
    : Piece{coor, player, eyes} {}

vector<shared_ptr<Move>> Rook::possibleMoves() const
{
    vector<shared_ptr<Move>> validMoves;

    for (int i = 0; i < 8; ++i)
    {
        if (i != coor.second)
        {
            if (!eyes->isOccupied({coor.first, i}) || eyes->isOpponent({coor.first, i}))
            {
                shared_ptr<Move> mp{new Move{coor, {coor.first, i}, ' '}};
                validMoves.emplace_back(mp);
            }
        }

        if (i != coor.first)
        {
            if (!eyes->isOccupied({i, coor.second}) || eyes->isOpponent({i, coor.second}))
            {
                shared_ptr<Move> mp{new Move{coor, {i, coor.second}, ' '}};
                validMoves.emplace_back(mp);
            }
        }
    }
    return validMoves;
}

char Rook::getType() const
{
    return getPlayer() == 0 ? 'R' : 'r';
}
