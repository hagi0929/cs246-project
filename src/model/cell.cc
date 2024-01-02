#inlcude "cell.h"

Cell::Cell(Coor coor) : coor{coor} {}
Cell::Cell(Coor coor, std::shared_ptr<Piece> piece) : coor{coor}, piece{piece} {}
Coor Cell::getCoor() const { return coor; }
std::shared_ptr<Piece> Cell::getPiece() const { return piece; }
void Cell::setPiece(std::shared_ptr<Piece> piece) { this->piece = piece; }
void Cell::removePiece() { piece = nullptr; }
std::ostream& operator<<(std::ostream& out, const Cell& cell) {
  if (cell.piece == nullptr) {
    out << " ";
  } else {
    out << cell.piece->getSymbol();
  }
  return out;
}
