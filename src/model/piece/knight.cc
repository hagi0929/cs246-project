#include "knight.h"

using namespace std;

Knight::Knight(pair<int, int> coor, int player, shared_ptr<Eyes> eyes)
    : Piece{coor, player, eyes} {}

vector<shared_ptr<Move>> Knight::possibleMoves() const
{
    cout << "Knight possibleMoves() is called" << endl;
    vector<shared_ptr<Move>> validMoves;
}

char Knight::getType() const
{
    cout << "Knight getType() is called" << endl;
    return getPlayer() == 0 ? 'N' : 'n';
}
