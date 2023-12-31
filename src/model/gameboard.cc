#include "gameboard.h"
#include "coor.h"
#include <iostream>

using namespace std;

Gameboard::Gameboard() { init(); }
Cell &Gameboard::getCell(int row, int col) { return board[row][col]; }
void Gameboard::init() {}
int Gameboard::getThisTurn() { return thisTurn; }
void Gameboard::createPiece(const Coor &coor, char pieceType) {}
void Gameboard::removePiece(const Coor &coor) {}
void Gameboard::movePiece(const Coor &from, const Coor &to, char promotion) {
    cout << "player " << thisTurn << " moved piece from " << from << " to " << to
         << endl;
    thisTurn = thisTurn == 0 ? 1 : 0;
}
void Gameboard::setThisTurn(int turn) { thisTurn = turn; }
void Gameboard::resign() {}