#include "rook.h"

using namespace std;

Rook::Rook(pair<int, int> coor, int player, shared_ptr<Eyes> eyes)
    : Piece{coor, player, eyes} {}

vector<shared_ptr<Move>> Rook::possibleMoves() const
{
    cout << "Rook possibleMoves() is called" << endl;
    vector<shared_ptr<Move>> validMoves;

    for (int i = 0; i < 8; ++i)
    {
        if (i != coor.second)
        {
            if (!eyes->isOccupied({coor.first, i}) || eyes->isOpponent({coor.first, i}))
            {
                shared_ptr<Move> mp{new Move{coor, {coor.first, i}, ""}};
                validMoves.emplace_back(mp);
                cout << mp->getCurRow() << "," << mp->getCurCol() + " "
                     << mp->getDestRow() << "," << mp->getDestCol() << endl;
            }
        }

        if (i != coor.first)
        {
            if (!eyes->isOccupied({i, coor.second}) || eyes->isOpponent({i, coor.second}))
            {
                shared_ptr<Move> mp{new Move{coor, {i, coor.second}, ""}};
                validMoves.emplace_back(mp);
                cout << mp->getCurRow() << "," << mp->getCurCol() + " "
                     << mp->getDestRow() << "," << mp->getDestCol() << endl;
            }
        }
    }
    return validMoves;
}

char Rook::getType() const
{
    cout << "Rook getType() is called" << endl;
    return getPlayer() == 0 ? 'R' : 'r';
}
