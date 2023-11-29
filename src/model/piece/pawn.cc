#include "pawn.h"

using namespace std;

Pawn::Pawn(pair<int, int> coor, int player, shared_ptr<Eyes> eyes)
    : Piece{coor, player, eyes} {}

vector<shared_ptr<Move>> Pawn::possibleMoves() const
{
    cout << "Pawn possibleMoves() is called" << endl;
    vector<shared_ptr<Move>> validMoves;
}

char Pawn::getType() const
{
    cout << "Pawn getType() is called" << endl;
    return getPlayer() == 0 ? 'P' : 'p';
}
