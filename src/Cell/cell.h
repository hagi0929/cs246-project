class Cell {
    Piece *piece;
    public:
    Cell();
    ~Cell();
    Piece getPiece();
    bool isEmpty();
};