#include "Piece.hpp"

vector<pair<int, int>> Rook::directions = { { 0, 1 } , { 0, -1 }, { -1, 0 } , { 1, 0 } };
vector<pair<int, int>> Bishop::directions = { { -1, 1 },  { -1, -1 } , { 1, 1 } , { 1, -1 } };

Color Piece::getColor() const {
	return color_;
}

pair<int, int> Piece::getPosition() const {
	return pos_;
}

void Piece::setPosition(int row, int col) noexcept {
	pos_ = pair<int, int>(row, col);
}

void Piece::setPosition(pair<int, int> pos) noexcept {
	pos_ = pos;
}

pair<int, int> operator+(const pair<int, int>& pair1, const pair<int, int>& pair2) {
	return pair<int, int>(pair1.first + pair2.first, pair1.second + pair2.second);
}

bool Piece::isPieceInsideBoard(const pair<int, int>& pos) const {
	return (pos.first >= 0) && (pos.first < 8)
		&& (pos.second >= 0) && (pos.second < 8);
}