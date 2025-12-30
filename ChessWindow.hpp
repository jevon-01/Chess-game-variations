#pragma once
#pragma warning(push, 0) // Sinon Qt fait des avertissements à /W4.
#include "ChessBoardArray.hpp"
#include <QMainWindow>
#include <QPushButton>
#include <QString>
#include <QLabel>
#include <QHBoxLayout>
#include <QButtonGroup>
#include <QComboBox>
#include <QVariant>
#include <random>
#pragma pop()

namespace frontend {
	class ChessWindow : public QMainWindow {
		Q_OBJECT

	public:

		ChessWindow(QWidget* parent = nullptr);
		~ChessWindow() override = default;

		QLabel* labelTurn;
		QGridLayout* gridLayoutChess;
		QComboBox* comboBoxGame;

	public slots:

		void changeTurn();

	private:

		backend::ChessBoardArray chessBoard_;
	};
}
