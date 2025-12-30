#pragma once
#include <QtWidgets>
#include <QGridLayout>
#include <QPushButton>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QString>
#include "Piece.hpp"
#include "King.hpp"
#include <memory>
#include <span>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

namespace backend {

	class Square : public QWidget {
		Q_OBJECT

	public:
		Square(QWidget* parent = nullptr);
		~Square() = default;

		QPushButton* button;

		void deletePiece();
		void setPiece(shared_ptr<Piece> pieceToAdd);
		void setPos(int row, int col);
		shared_ptr<Piece> getPiece() const;

		bool isPotential = false;
		pair<int, int> potentialPos;
		pair<int, int> getPos();
		shared_ptr<Piece> piece_;
		pair<int, int> pos_;

	signals:

		void isClickedOnVoid(shared_ptr<Square> ptrSquare);
		void hasPiece();
		void squareIsEmpty();
		void pieceToMove();
		void checkToEat();


	public slots:

		void checkSquare();

	};

	struct PairHash {
		template <class T1, class T2>
		std::size_t operator () (const std::pair<T1, T2>& pair) const {

			return std::hash<T1>()(pair.first) ^ std::hash<T2>()(pair.second);
		}
	};

	class ChessBoardArray : public QWidget {
		Q_OBJECT

	public:
		ChessBoardArray();
		~ChessBoardArray() = default;
		void initializeChessBoard();

		void setGame();
		void setGameRandom();
		void setGameInverse();

		void addPiece(shared_ptr<Piece> pieceType, const Color& color, const pair<int, int>& pos);
		void movePiece(shared_ptr<Piece> piece, pair<int, int> nextPos);
		void movePieceSimulation(shared_ptr<Piece> ptrPiece, pair<int, int> nextPos);
		pair<int, int> findKingPos(const Color& color) const;

		bool isPosInsideBoard(const pair<int, int>& pos) const;
		bool isOwnPiece(shared_ptr<Piece> piece, const pair<int, int>& pos) const;
		bool isSquareEmpty(const pair<int, int>& pos) const;
		bool isValidMove(shared_ptr<Piece> piece, const pair<int, int>& move) const;
		bool isKingChecked(const Color& myColor) const;

		void movementKing(shared_ptr<Piece>& king);
		void movementRook(shared_ptr<Piece>& rook, bool kingChecked);
		void movementBishop(shared_ptr<Piece>& bishop);

		void removeSelfCheck(shared_ptr<Piece>& piece, const pair<int, int>& move);
		void removePlayerSelfCheck();

		void updateValidMoveWithoutCheck(const Color& color = Color::BLANK, bool kingChecked = false);
		void updateListAllValidMoves(bool removeSelfCheck = true);

		void clearHighlightBoard();
		Color getColorCurrentPlayer();

		static const int DIMENSION = 8;

		shared_ptr<Square> board_[DIMENSION][DIMENSION];
	signals:
		void signalUncolor();
		void playerPlayed();

	public slots:

		void movePieceSlot();
		void potential();
		void uncolorSquares();
		void gameModeChanged(int index);

	private:
		unordered_set<shared_ptr<Piece>> listWhitePieces_;
		unordered_set<shared_ptr<Piece>> listBlackPieces_;
		unordered_set<pair<int, int>, PairHash > validWhiteMoves_;
		unordered_set<pair<int, int>, PairHash> validBlackMoves_;
		Color currentPLayerColor_ = Color::WHITE;
	};
}