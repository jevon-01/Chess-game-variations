#include "King.hpp"
#include <utility>
using namespace std;

int King::_nKings = 0;

vector<pair<int, int>> King::directions = { { 0, 1 } , { 0, -1 }, { -1, 0 } , { 1, 0 }, { -1, 1 },  { -1, -1 } , { 1, 1 } , { 1, -1 } };

King::King(const int& row, const int& col, const Color& color) : Piece(row, col, color) {
    type = PieceType::KING;
    if (++_nKings > 2) {
        throw TooManyKingsException("Cannot have more than 2 Kings");
    }
}

King::~King() {
    _nKings--;
}