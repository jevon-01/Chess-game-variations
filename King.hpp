#pragma once
#include "Piece.hpp"
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

class TooManyKingsException : public exception
{
public:
    using exception::exception;

};

enum class PieceMvt {
    RIGHT,
    LEFT,
    UP,
    DOWN,
    UP_RIGHT,
    UP_LEFT,
    DOWN_RIGHT,
    DOWN_LEFT

};

class King : public Piece
{
public:
    King(const int& row, const int& col, const Color& color);
    ~King();

    static vector<pair<int, int>> directions;
    static int _nKings;

};