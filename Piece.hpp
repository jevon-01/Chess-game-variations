#pragma once
#include <string>
#include <utility>
#include <vector>
#include <memory>
using namespace std;

enum class Color {
    WHITE,
    BLACK,
    BLANK,
};

enum class PieceType {
    KING,
    BISHOP,
    ROOK,
    NONE,
};

class Piece {
public:
    Piece(const int& row, const int& col, const Color& pieceColor) : pos_(pair<int, int>(row, col)), color_(pieceColor) {}
    Piece(const pair<int, int>& pos, const Color& pieceColor) : pos_(pos), color_(pieceColor) {}

    virtual ~Piece() = default;
    Color getColor() const;
    pair<int, int> getPosition() const;
    void setPosition(int row, int col) noexcept;
    void setPosition(pair<int, int> pos) noexcept;
    bool isPieceInsideBoard(const pair<int, int>& move) const;

    vector<pair<int, int>> listValidMoves;
    PieceType type = PieceType::NONE;

protected:

    Color color_;
    pair<int, int> pos_;
};

class Rook : public Piece {
public:

    Rook(const int& row, const int& col, const Color& color) : Piece(row, col, color) { type = PieceType::ROOK; }
    ~Rook() = default;

    static vector<pair<int, int>> directions;

};


class Bishop : public Piece {
public:

    Bishop(const int& row, const int& col, const Color& color) : Piece(row, col, color) { type = PieceType::BISHOP; }
    ~Bishop() = default;

    static vector<pair<int, int>> directions;

};

pair<int, int> operator+(const pair<int, int>& pair1, const pair<int, int>& pair2);