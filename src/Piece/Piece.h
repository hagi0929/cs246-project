enum class PieceType {}

class Piece {
    bool color;
    public:
    Color getColor();
    virtual PieceType getType() = 0;
};