#include "BigTicTacToe.h"


BigBoard::BigBoard() {
	boards = new SubBoard*[3];
	board = new char* [3];
	for (int i = 0; i < 3; i++) {
		boards[i] = new SubBoard[3];
		board[i] = new char[3] {'-', '-', '-' };
	}
}

BigBoard::~BigBoard() {
	for (int i = 0; i < 3; i++) {
		delete[] boards[i];
		delete[] board[i];
	}

	delete[] boards;
	delete[] board;
}

bool BigBoard::update_board(int x,int y,char symb) {
	int boardx = x / 3;
	int boardy = y / 3;
	int subx = x % 3;
	int suby = y % 3;

	if (boards[boardx][boardy].is_game_over()) {
		cout << "Board is Already Over" << endl;
		return false;
	}
	auto move = boards[boardx][boardy].makeMove(subx,suby,symb);

	if (!move) {
		cout << "Invalid Move" << endl;
		return false;
	}
	
	int counter = 0;
	board[boardx][boardy] = boards[boardx][boardy].getValue();

	for (int i = -1; i < 2; i++) {
		for (int j = -1; j < 2; j++) {
			if (i == 0 && j == 0) continue;
			if (count_moves(board, boardx, boardy, i, j, symb)) {
				win = true;
				return true;
			};
		}
	}


	this->draw = true; 
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3;j++) {
			if (!boards[i][j].is_game_over()) {
				draw = false;
				break;
			}
		}
		if (!draw)
			break;
	}


	return true;
}



void BigBoard::display_board() {
	cout << endl;

	cout << "  012   345   678" << endl;
	for (int x = 0; x < 9; x++) {
		cout << x << " ";
		for (int y = 0; y < 9; y++) {
			int boardx = x / 3;
			int boardy = y / 3;
			int subx = x % 3;
			int suby = y % 3;
			if (boards[boardx][boardy].is_game_over()) {
				char symbol = tolower(boards[boardx][boardy].getValue());
				int value;
				if (symbol == 'x') {
					value = 0;
				}
				else if (symbol == 'o') {
					value = 1;
				}
				else {
					value = 2;
				}
				cout << symbols[value][subx][suby];
			}
			else {
				cout << boards[boardx][boardy].getValAt(subx, suby);
			}
			if ((y + 1) % 3 == 0 && y != 8) {
				cout << " | ";
			}
		}
		cout << " " << x << endl;
		if ((x + 1) % 3 == 0 && x != 8) {
			cout << "-----*-----*-----" << endl;
		}
	}
	cout << "  012   345   678" << endl;

}




SubBoard::SubBoard() {
	isOver = false;
	board = new char* [3];
	for (int i = 0; i < 3; i++) {
		board[i] = new char[3] {'-', '-', '-'};
	}
}

SubBoard::~SubBoard() {
	for (int i = 0; i < 3; i++) {
		delete[] board[i];
	}

	delete[] board;
}

bool SubBoard::makeMove(int x, int y, char symb) {
	if (board[x][y] != '-') {
		return false;
	}

	if (is_game_over()) {
		return false;
	}

	moves++;
	board[x][y] = symb;
	for (int i = -1; i < 3; i++) {
		for (int j = -1; j < 3; j++) {
			if (j == 0 && i == 0) continue;
			auto count = count_moves(board, x, y, i, j, symb);
			if (count) {
				current = symb;
				isOver = true;
				return true;
			}
		}
	}

	if (moves == 9) {
		isOver = true;
	}

	return true;

}


void Big_Player::getmove(int& x, int& y) {
	cout << "Row: ";
	cin >> x;
	cout << "Column: ";
	cin >> y;

	while (x < 0 || x > 8 || y < 0 || y > 8) {
		cout << "invalid move\n";
		cout << "Row: ";
		cin >> x;
		cout << "Column: ";
		cin >> y;
	}
}