#include "ChessWindow.hpp"
#include "ChessBoardArray.hpp"
#pragma warning(push, 0) // Sinon Qt fait des avertissements à /W4.
#pragma pop()
#include <iostream>
#include <type_traits>
#include <cppitertools/range.hpp>

using iter::range;

void frontend::ChessWindow::changeTurn() {
	backend::ChessBoardArray* chessboard = dynamic_cast<backend::ChessBoardArray*>(QObject::sender());
	if (chessboard->getColorCurrentPlayer() == Color::BLACK) {
		labelTurn->setText("TURN : BLACK");
	}
	else if (chessboard->getColorCurrentPlayer() == Color::WHITE) {
		labelTurn->setText("TURN : WHITE");
	}
}

frontend::ChessWindow::ChessWindow(QWidget* parent) :
	QMainWindow(parent)
{

	QWidget* centralWidget = new QWidget(this);
	setCentralWidget(centralWidget);

	QVBoxLayout* layoutVertical = new QVBoxLayout(centralWidget);

	QLabel* label = new QLabel("TURN : WHITE", centralWidget);
	labelTurn = &*label;
	QObject::connect(&chessBoard_, &backend::ChessBoardArray::playerPlayed, this, &frontend::ChessWindow::changeTurn);

	label->setAlignment(Qt::AlignCenter);
	layoutVertical->addWidget(label);

	QWidget* chessboardWidget = new QWidget(centralWidget);
	QGridLayout* gridLayout = new QGridLayout(chessboardWidget);

	gridLayoutChess = &*gridLayout;
	gridLayout->setSpacing(0);
	gridLayout->setAlignment(Qt::AlignCenter);

	for (int i : range(8)) {

		for (int j : range(8)) {

			gridLayoutChess->addWidget(chessBoard_.board_[i][j]->button, i, j);
		}
	}

	layoutVertical->addWidget(chessboardWidget);

	QComboBox* comboBox = new QComboBox(centralWidget);
	comboBoxGame = &*comboBox;
	comboBox->setWindowTitle("Different game modes");
	comboBox->addItem("Normal 3 pieces per team");
	comboBox->addItem("Random place of 1 white king and 3 black pieces");
	comboBox->addItem("Normal inverted");

	QObject::connect(comboBox, QOverload<int>::of(&QComboBox::currentIndexChanged),
		&chessBoard_, &backend::ChessBoardArray::gameModeChanged);

	layoutVertical->addWidget(comboBox);

	setWindowTitle("Chess Game");

}
