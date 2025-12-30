#include "ChessBoardArray.hpp"

void backend::Square::setPiece(shared_ptr<Piece> pieceToAdd) {
	piece_ = std::move(pieceToAdd);
}

void backend::Square::setPos(int row, int col) {
	pos_ = pair<int, int>(row, col);
}

pair<int, int> backend::Square::getPos() {
	return pos_;
}

backend::Square::Square(QWidget* parent) : QWidget(parent) {
	QGridLayout* layout = new QGridLayout(this);

	QPushButton* bouton = new QPushButton(this);
	piece_ = nullptr;
	button = &*bouton;
	bouton->setFixedSize(60, 60);

	layout->addWidget(bouton);

}

void backend::Square::checkSquare() {

	if (this->isPotential && this->piece_ != nullptr) {
		emit checkToEat();
	}
	if (this->piece_ != nullptr) {
		emit hasPiece();
	}
	else if (this->isPotential) {
		emit pieceToMove();
	}
	else {
		emit squareIsEmpty();
	}

}

void backend::Square::deletePiece() {
	piece_.reset();
}

shared_ptr<Piece> backend::Square::getPiece() const {
	return piece_;
}

Color backend::ChessBoardArray::getColorCurrentPlayer() {
	return currentPLayerColor_;
}

void backend::ChessBoardArray::addPiece(shared_ptr<Piece> pieceType, const Color& color, const pair<int, int>& pos) {
	auto&& [x, y] = pos;
	board_[x][y]->setPiece((pieceType));
	if (color == Color::WHITE)
		listWhitePieces_.insert((board_[x][y]->getPiece()));
	else if (color == Color::BLACK)
		listBlackPieces_.insert((board_[x][y]->getPiece()));
}

void backend::ChessBoardArray::initializeChessBoard() {
	for (int i = 0; i < DIMENSION; i++) {

		for (int j = 0; j < DIMENSION; j++) {

			board_[i][j] = make_shared<backend::Square>();
			board_[i][j]->setPos(i, j);

			if (i % 2 == 0 && j % 2 == 0) {
				board_[i][j]->button->setStyleSheet("background-color: brown;");
			}
			else if (i % 2 != 0 && j % 2 != 0) {
				board_[i][j]->button->setStyleSheet("background-color: brown;");
			}
			else {
				board_[i][j]->button->setStyleSheet("background-color: grey;");
			}

			QObject::connect(board_[i][j]->button, &QPushButton::clicked, &*board_[i][j], &Square::checkSquare);
			QObject::connect(&*board_[i][j], &Square::hasPiece, this, &ChessBoardArray::potential);
			QObject::connect(&*board_[i][j], &Square::squareIsEmpty, this, &ChessBoardArray::uncolorSquares);
			QObject::connect(&*board_[i][j], &Square::pieceToMove, this, &ChessBoardArray::movePieceSlot);
			QObject::connect(&*board_[i][j], &Square::checkToEat, this, &ChessBoardArray::movePieceSlot);

		}
	}
	setGame();
}

backend::ChessBoardArray::ChessBoardArray() {

	initializeChessBoard();

}

void backend::ChessBoardArray::gameModeChanged(int index) {

	QComboBox* comboBox = dynamic_cast<QComboBox*>(QObject::sender());

	for (int i = 0; i < DIMENSION; i++) {

		for (int j = 0; j < DIMENSION; j++) {

			board_[i][j]->button->setIcon(QIcon());
			board_[i][j]->deletePiece();

		}
	}

	listWhitePieces_.clear();
	listBlackPieces_.clear();
	validWhiteMoves_.clear();
	validBlackMoves_.clear();

	if (index == 0) {
		currentPLayerColor_ = Color::WHITE;
		setGame();
	}
	else if (index == 1) {
		currentPLayerColor_ = Color::WHITE;
		setGameRandom();
	}
	else {
		currentPLayerColor_ = Color::BLACK;
		setGameInverse();
	}

	emit playerPlayed();

}

void backend::ChessBoardArray::potential() {

	Square* square = dynamic_cast<Square*>(QObject::sender());
	auto piece = square->getPiece();
	clearHighlightBoard();

	if (currentPLayerColor_ == square->getPiece()->getColor()) {
		if (square->isPotential) {
			emit& Square::pieceToMove;
		}
		else {

			for (int i = 0; i < piece->listValidMoves.size(); i++) {
				auto&& [x, y] = piece->listValidMoves[i];
				board_[x][y]->button->setStyleSheet("background-color: green;");
				board_[x][y]->isPotential = true;
				board_[x][y]->potentialPos = piece->getPosition();
			}
		}
	}
}

void backend::ChessBoardArray::movePieceSlot() {
	Square* square = dynamic_cast<Square*>(QObject::sender());

	auto piece = square->getPiece();
	clearHighlightBoard();
	auto&& [x, y] = square->potentialPos;
	if (board_[x][y]->getPiece()->getColor() == Color::BLACK) {

		if (board_[x][y]->getPiece()->type == PieceType::KING) {
			QIcon icon(static_cast<QString>("black_king.png"));
			movePiece(board_[x][y]->getPiece(), square->getPos());
			square->button->setIcon(icon);
			square->button->setIconSize(QSize(60, 60));
			board_[x][y]->button->setIcon(QIcon());
		}
		else if (board_[x][y]->getPiece()->type == PieceType::BISHOP) {
			QIcon icon(static_cast<QString>("black_bishop.png"));
			movePiece(board_[x][y]->getPiece(), square->getPos());
			square->button->setIcon(icon);
			square->button->setIconSize(QSize(60, 60));
			board_[x][y]->button->setIcon(QIcon());
		}
		else if (board_[x][y]->getPiece()->type == PieceType::ROOK) {
			QIcon icon(static_cast<QString>("black_rook.png"));
			movePiece(board_[x][y]->getPiece(), square->getPos());
			square->button->setIcon(icon);
			square->button->setIconSize(QSize(60, 60));
			board_[x][y]->button->setIcon(QIcon());
		}

	}
	else {
		if (board_[x][y]->getPiece()->type == PieceType::KING) {
			QIcon icon(static_cast<QString>("white_king.png"));
			movePiece(board_[x][y]->getPiece(), square->getPos());
			square->button->setIcon(icon);
			square->button->setIconSize(QSize(60, 60));

			board_[x][y]->button->setIcon(QIcon());
		}
		else if (board_[x][y]->getPiece()->type == PieceType::BISHOP) {
			QIcon icon(static_cast<QString>("white_bishop.png"));
			movePiece(board_[x][y]->getPiece(), square->getPos());
			square->button->setIcon(icon);
			square->button->setIconSize(QSize(60, 60));
			board_[x][y]->button->setIcon(QIcon());
		}
		else if (board_[x][y]->getPiece()->type == PieceType::ROOK) {
			QIcon icon(static_cast<QString>("white_rook.png"));
			movePiece(board_[x][y]->getPiece(), square->getPos());
			square->button->setIcon(icon);
			square->button->setIconSize(QSize(60, 60));
			board_[x][y]->button->setIcon(QIcon());
		}

	}

	emit playerPlayed();

}

void backend::ChessBoardArray::clearHighlightBoard() {

	for (int i = 0; i < DIMENSION; i++) {

		for (int j = 0; j < DIMENSION; j++) {

			if (i % 2 == 0 && j % 2 == 0) {
				board_[i][j]->button->setStyleSheet("background-color: brown;");
			}
			else if (i % 2 != 0 && j % 2 != 0) {
				board_[i][j]->button->setStyleSheet("background-color: brown;");
			}
			else {
				board_[i][j]->button->setStyleSheet("background-color: grey;");
			}
			board_[i][j]->isPotential = false;
		}
	}
}

void backend::ChessBoardArray::uncolorSquares() {
	clearHighlightBoard();
}

void backend::ChessBoardArray::setGame() {

	try {
		board_[7][4]->setPiece(make_shared<King>(7, 4, Color::WHITE));
		QIcon icon(static_cast<QString>("white_king.png"));
		addPiece(std::move(board_[7][4]->piece_), Color::WHITE, pair<int, int>{7, 4});
		board_[7][4]->button->setIcon(icon);
		board_[7][4]->button->setIconSize(QSize(60, 60));
	}
	catch (TooManyKingsException& e) {
		cout << e.what() << endl;
		board_[7][4]->setPiece(nullptr);
	}
	try {
		board_[0][3]->setPiece(make_shared<King>(0, 3, Color::BLACK));
		//auto it = board_[0][3]->getPiece();
		addPiece(std::move(board_[0][3]->piece_), Color::BLACK, pair<int, int>{0, 3});

		QIcon icon(static_cast<QString>("black_king.png"));
		board_[0][3]->button->setIcon(icon);
		board_[0][3]->button->setIconSize(QSize(60, 60));
	}
	catch (TooManyKingsException& e) {
		cout << e.what() << endl;
		board_[0][3]->setPiece(nullptr);
	}
	//Fill the rest of the board with nullptr
	for (int i = 0; i < DIMENSION; ++i) {
		for (int j = 0; j < DIMENSION; ++j) {
			if ((i != 7 && j == 4) || (i != 0 && j == 3))
				board_[i][j]->setPiece(nullptr);
		}
	}

	QIcon iconRB(static_cast<QString>("black_rook.png"));
	board_[0][0]->setPiece(make_shared<Rook>(0, 0, Color::BLACK));
	addPiece(std::move(board_[0][0]->piece_), Color::BLACK, pair<int, int>{0, 0});
	board_[0][0]->button->setIcon(iconRB);
	board_[0][0]->button->setIconSize(QSize(60, 60));

	QIcon iconRW(static_cast<QString>("white_rook.png"));
	board_[7][0]->setPiece(make_shared<Rook>(7, 0, Color::WHITE));
	addPiece(std::move(board_[7][0]->piece_), Color::WHITE, pair<int, int>{7, 0});
	board_[7][0]->button->setIcon(iconRW);
	board_[7][0]->button->setIconSize(QSize(60, 60));

	QIcon iconBB(static_cast<QString>("black_bishop.png"));
	board_[0][2]->setPiece(make_shared<Bishop>(0, 2, Color::BLACK));
	addPiece(std::move(board_[0][2]->piece_), Color::BLACK, pair<int, int>{0, 2});
	board_[0][2]->button->setIcon(iconBB);
	board_[0][2]->button->setIconSize(QSize(60, 60));


	QIcon iconBW(static_cast<QString>("white_bishop.png"));
	board_[7][2]->setPiece(make_shared<Bishop>(7, 2, Color::WHITE));
	addPiece(std::move(board_[7][2]->piece_), Color::WHITE, pair<int, int>{7, 2});
	board_[7][2]->button->setIcon(iconBW);
	board_[7][2]->button->setIconSize(QSize(60, 60));

	updateListAllValidMoves();

}

void backend::ChessBoardArray::setGameRandom() {
	int random_num = (rand() % 5) + 1;
	try {
		board_[7][random_num]->setPiece(make_shared<King>(7, random_num, Color::WHITE));
		QIcon icon(static_cast<QString>("white_king.png"));
		addPiece(std::move(board_[7][random_num]->piece_), Color::WHITE, pair<int, int>{7, random_num});
		board_[7][random_num]->button->setIcon(icon);
		board_[7][random_num]->button->setIconSize(QSize(60, 60));
	}
	catch (TooManyKingsException& e) {
		cout << e.what() << endl;
		board_[7][random_num]->setPiece(nullptr);
	}
	try {
		board_[0][3]->setPiece(make_shared<King>(0, 3, Color::BLACK));
		addPiece(std::move(board_[0][3]->piece_), Color::BLACK, pair<int, int>{0, 3});

		QIcon icon(static_cast<QString>("black_king.png"));
		board_[0][3]->button->setIcon(icon);
		board_[0][3]->button->setIconSize(QSize(60, 60));
	}
	catch (TooManyKingsException& e) {
		cout << e.what() << endl;
		board_[0][3]->setPiece(nullptr);
	}
	//Fill the rest of the board with nullptr
	for (int i = 0; i < DIMENSION; ++i) {
		for (int j = 0; j < DIMENSION; ++j) {
			if ((i != 7 && j == 4) || (i != 0 && j == 3))
				board_[i][j]->setPiece(nullptr);
		}
	}

	QIcon iconRB(static_cast<QString>("black_rook.png"));
	board_[0][0]->setPiece(make_shared<Rook>(0, 0, Color::BLACK));
	addPiece(std::move(board_[0][0]->piece_), Color::BLACK, pair<int, int>{0, 0});
	board_[0][0]->button->setIcon(iconRB);
	board_[0][0]->button->setIconSize(QSize(60, 60));

	QIcon iconBB(static_cast<QString>("black_bishop.png"));
	board_[0][2]->setPiece(make_shared<Bishop>(0, 2, Color::BLACK));
	addPiece(std::move(board_[0][2]->piece_), Color::BLACK, pair<int, int>{0, 2});
	board_[0][2]->button->setIcon(iconBB);
	board_[0][2]->button->setIconSize(QSize(60, 60));

	updateListAllValidMoves();

}

void backend::ChessBoardArray::setGameInverse() {
	try {
		board_[7][4]->setPiece(make_shared<King>(7, 4, Color::BLACK));
		QIcon icon(static_cast<QString>("black_king.png"));
		addPiece(std::move(board_[7][4]->piece_), Color::BLACK, pair<int, int>{7, 4});
		board_[7][4]->button->setIcon(icon);
		board_[7][4]->button->setIconSize(QSize(60, 60));
	}
	catch (TooManyKingsException& e) {
		cout << e.what() << endl;
		board_[7][4]->setPiece(nullptr);
	}
	try {
		board_[0][3]->setPiece(make_shared<King>(0, 3, Color::WHITE));
		addPiece(std::move(board_[0][3]->piece_), Color::WHITE, pair<int, int>{0, 3});

		QIcon icon(static_cast<QString>("white_king.png"));
		board_[0][3]->button->setIcon(icon);
		board_[0][3]->button->setIconSize(QSize(60, 60));
	}
	catch (TooManyKingsException& e) {
		cout << e.what() << endl;
		board_[0][3]->setPiece(nullptr);
	}
	//Fill the rest of the board with nullptr
	for (int i = 0; i < DIMENSION; ++i) {
		for (int j = 0; j < DIMENSION; ++j) {
			if ((i != 7 && j == 4) || (i != 0 && j == 3))
				board_[i][j]->setPiece(nullptr);
		}
	}

	QIcon iconRB(static_cast<QString>("white_rook.png"));
	board_[0][0]->setPiece(make_shared<Rook>(0, 0, Color::WHITE));
	addPiece(std::move(board_[0][0]->piece_), Color::WHITE, pair<int, int>{0, 0});
	board_[0][0]->button->setIcon(iconRB);
	board_[0][0]->button->setIconSize(QSize(60, 60));

	QIcon iconRW(static_cast<QString>("black_rook.png"));
	board_[7][0]->setPiece(make_shared<Rook>(7, 0, Color::BLACK));
	addPiece(std::move(board_[7][0]->piece_), Color::BLACK, pair<int, int>{7, 0});
	board_[7][0]->button->setIcon(iconRW);
	board_[7][0]->button->setIconSize(QSize(60, 60));

	QIcon iconBB(static_cast<QString>("white_bishop.png"));
	board_[0][2]->setPiece(make_shared<Bishop>(0, 2, Color::WHITE));
	addPiece(std::move(board_[0][2]->piece_), Color::WHITE, pair<int, int>{0, 2});
	board_[0][2]->button->setIcon(iconBB);
	board_[0][2]->button->setIconSize(QSize(60, 60));

	QIcon iconBW(static_cast<QString>("black_bishop.png"));
	board_[7][2]->setPiece(make_shared<Bishop>(7, 2, Color::BLACK));
	addPiece(std::move(board_[7][2]->piece_), Color::BLACK, pair<int, int>{7, 2});
	board_[7][2]->button->setIcon(iconBW);
	board_[7][2]->button->setIconSize(QSize(60, 60));

	updateListAllValidMoves();
}

//[[[===================toCheckPieceMouvements===================]]]

void backend::ChessBoardArray::movePiece(shared_ptr<Piece> ptrPiece, pair<int, int> nextPos) {

	auto& myListPieces = (currentPLayerColor_ == Color::BLACK) ? listWhitePieces_ : listBlackPieces_;
	auto&& [nextX, nextY] = nextPos;
	auto&& [oldX, oldY] = ptrPiece->getPosition();

	if (!isSquareEmpty(nextPos)) {
		myListPieces.erase(board_[nextX][nextY]->getPiece());
	}
	board_[nextX][nextY]->setPiece((ptrPiece));
	ptrPiece->setPosition(nextX, nextY);
	board_[oldX][oldY]->setPiece(nullptr);
	board_[oldX][oldY]->isPotential = false;
	board_[nextX][nextY]->isPotential = false;

	currentPLayerColor_ = currentPLayerColor_ == Color::WHITE ? Color::BLACK : Color::WHITE;

	updateListAllValidMoves();
}

void backend::ChessBoardArray::movePieceSimulation(shared_ptr<Piece> ptrPiece, pair<int, int> nextPos) {
	auto&& [nextX, nextY] = nextPos;
	auto&& [oldX, oldY] = ptrPiece->getPosition();
	board_[nextX][nextY]->setPiece((ptrPiece));
	ptrPiece->setPosition(nextX, nextY);
	board_[oldX][oldY]->setPiece(nullptr);
}

void backend::ChessBoardArray::movementKing(shared_ptr<Piece>& king) {
	for (auto dir : King::directions) {
		auto newPos = king->getPosition() + dir;
		if (isValidMove(king, newPos)) {
			king->listValidMoves.push_back(newPos);
		}
	}
}

void backend::ChessBoardArray::movementRook(shared_ptr<Piece>& rook, bool kingChecked) {
	auto oppKingColor = (currentPLayerColor_ == Color::BLACK) ? Color::WHITE : Color::BLACK;
	for (auto dir : Rook::directions) {
		auto newPos = rook->getPosition() + dir;
		while (isValidMove(rook, newPos)) {
			rook->listValidMoves.push_back(newPos);
			if (newPos == findKingPos(currentPLayerColor_) && kingChecked) {
				rook->listValidMoves.push_back(newPos + dir);
				break;
			}
			if (!isSquareEmpty(newPos) && !isOwnPiece(rook, newPos))
				break;
			newPos = newPos + dir;
		}
	}
}

void backend::ChessBoardArray::movementBishop(shared_ptr<Piece>& bishop) {
	for (auto dir : Bishop::directions) {
		auto newPos = bishop->getPosition() + dir;
		while (isValidMove(bishop, newPos)) {
			bishop->listValidMoves.push_back(newPos);
			if (!isSquareEmpty(newPos) && !isOwnPiece(bishop, newPos))
				break;
			newPos = newPos + dir;
		}
	}
}

bool backend::ChessBoardArray::isKingChecked(const Color& myColor) const {
	auto posKing = findKingPos(myColor);
	auto& oppValidMoves = (myColor == Color::WHITE) ? validBlackMoves_ : validWhiteMoves_;
	auto it = oppValidMoves.find(posKing);
	if (it != oppValidMoves.end())
		return true;
	return false;
}

bool backend::ChessBoardArray::isPosInsideBoard(const pair<int, int>& pos) const {
	return (pos.first >= 0) && (pos.first < 8)
		&& (pos.second >= 0) && (pos.second < 8);
}

bool backend::ChessBoardArray::isOwnPiece(shared_ptr<Piece> piece, const pair<int, int>& pos) const {

	auto&& [x, y] = pos;
	return (piece->getColor() == board_[x][y]->getPiece()->getColor());
}

bool backend::ChessBoardArray::isSquareEmpty(const pair<int, int>& pos) const {

	return (board_[pos.first][pos.second]->getPiece() == nullptr);
}

bool backend::ChessBoardArray::isValidMove(shared_ptr<Piece> piece, const pair<int, int>& move) const {

	return (isPosInsideBoard(move) && (isSquareEmpty(move) || !isOwnPiece(piece, move)));

}

void backend::ChessBoardArray::updateValidMoveWithoutCheck(const Color& color, bool kingChecked) {
	bool updateWhite = (color != Color::BLACK) ? true : false;
	bool updateBlack = (color != Color::WHITE) ? true : false;
	if (updateWhite) {
		validBlackMoves_.clear();
		for (auto pieceType : listWhitePieces_) {
			pieceType->listValidMoves.clear();
			switch (pieceType->type) {
			case PieceType::KING:
				movementKing(pieceType);
				break;
			case PieceType::ROOK:
				movementRook(pieceType, kingChecked);
				break;
			case PieceType::BISHOP:
				movementBishop(pieceType);
				break;
			}
		}
	}
	if (updateBlack) {
		validWhiteMoves_.clear();
		for (auto pieceType : listBlackPieces_) {
			pieceType->listValidMoves.clear();
			switch (pieceType->type) {
			case PieceType::KING:
				movementKing(pieceType);
				break;
			case PieceType::ROOK:
				movementRook(pieceType, kingChecked);
				break;
			case PieceType::BISHOP:
				movementBishop(pieceType);
				break;
			}
		}
	}
}

void backend::ChessBoardArray::removeSelfCheck(shared_ptr<Piece>& piece, const pair<int, int>& move) {

	auto oldPosPair = piece->getPosition();
	shared_ptr<Piece> pieceToReplace = nullptr;
	if (!isSquareEmpty(move))
		pieceToReplace = board_[move.first][move.second]->getPiece();
	movePieceSimulation(piece, move);
	auto oppColor = (currentPLayerColor_ == Color::WHITE) ? Color::BLACK : Color::WHITE;
	updateValidMoveWithoutCheck(oppColor, true);

	auto& oppValidMoves = (currentPLayerColor_ == Color::WHITE) ? validBlackMoves_ : validWhiteMoves_;
	auto& myValidMoves = (currentPLayerColor_ == Color::WHITE) ? validWhiteMoves_ : validBlackMoves_;

	if (isKingChecked(currentPLayerColor_)) {

		auto it = remove(piece->listValidMoves.begin(), piece->listValidMoves.end(), move);
		piece->listValidMoves.erase(it, piece->listValidMoves.end());;
	}

	movePieceSimulation(piece, oldPosPair);
	if (pieceToReplace != nullptr)
		addPiece(pieceToReplace, pieceToReplace->getColor(), move);

	updateListAllValidMoves(false);


}

void backend::ChessBoardArray::removePlayerSelfCheck() {
	auto& listPieces = (currentPLayerColor_ == Color::WHITE) ? listWhitePieces_ : listBlackPieces_;
	for (auto piece : listPieces) {

		vector<pair<int, int>> copyList;
		copy(piece->listValidMoves.begin(), piece->listValidMoves.end(), back_inserter(copyList));

		for (auto pair : copyList) {
			removeSelfCheck(piece, pair);
		}
	}
}

void backend::ChessBoardArray::updateListAllValidMoves(bool removeSelfCheck) {
	if (removeSelfCheck) {
		updateValidMoveWithoutCheck();
		removePlayerSelfCheck();
	}

	validWhiteMoves_.clear();
	validBlackMoves_.clear();
	for (auto pieceW : listWhitePieces_) {
		for (auto moveW : pieceW->listValidMoves)
			validWhiteMoves_.insert(moveW);
	}
	for (auto pieceB : listBlackPieces_) {
		for (auto moveB : pieceB->listValidMoves)
			validBlackMoves_.insert(moveB);
	}
}

pair<int, int> backend::ChessBoardArray::findKingPos(const Color& color) const {
	auto& listPieces = (color == Color::WHITE) ? listWhitePieces_ : listBlackPieces_;
	for (auto it : listPieces) {
		auto piece = it;
		if (auto king = dynamic_cast<King*>(piece.get()))
			return king->getPosition();
	}
}