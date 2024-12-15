#include "ToeTacTic.h"


void ToeTacTic_Player::getmove(int& x, int& y) {
	cout << "Row: ";
	cin >> x;
	cout << "Column: ";
	cin >> y;

	while (x < 0 || x > 2 || y < 0 || y > 2) {
		cout << "invalid move\n";
		cout << "Row: ";
		cin >> x;
		cout << "Column: ";
		cin >> y;
	}
}


ToeTacTic_Board::ToeTacTic_Board() {
	this->board = new char* [3];
	for (int x = 0; x < 3; x++) {
		this->board[x] = new char[3];
		for (int y = 0; y < 3; y++) {
			this->board[x][y] = '-';
		}
	}
}


void ToeTacTic_Board::display_board() {
	cout << endl;
	for (int x = 0; x < 3; x++) {
		for (int y = 0; y < 3; y++) {
			cout << this->board[x][y] << " ";
		}
		cout << endl;
	}
	cout << endl;
}


void ToeTacTic_RandomPlayer::getmove(int& x, int& y) {
	x = rand() % 3;
	y = rand() % 3;
}

int ToeTacTic_AiPlayer::count_moves(int x, int y, int dirx, int diry, int symb, int count) const {
	if (x > 2 || y > 2 || x < 0 || y < 0)
		return count - 1;
	if (tempboard[x][y] != symb) {
		return count - 1;
	}
	if (count == 2) {
		return count;
	}
	return count_moves(x + dirx, y + diry, dirx, diry, symb, count + 1);
}

bool ToeTacTic_AiPlayer::countmo(int x, int y, int dirx, int diry, int symb) const {
	return count_moves(x, y, dirx, diry, symb) + count_moves(x, y, -dirx, -diry, symb) + 1 >= 3;
}

int ToeTacTic_AiPlayer::eval(bool isPlayerOne) const {
	for (int x = 0; x < 3; x++) {
		for (int y = 0; y < 3; y++) {
			if (tempboard[x][y] == -1) continue;
			for (int i = -1; i < 2; i++) {
				for (int j = -1; j < 2; j++) {
					if ((i == 0 && j == 0)) continue;
					auto ev = countmo(x, y, i, j, tempboard[x][y]);
					if (ev) {
						return (tempboard[x][y] != isPlayerOne) ? 1 : -1;
					}
				}
			}
		}
	}
	return 0;
}

bool ToeTacTic_Board::is_win() {
	bool win = false;
	//diagonals
	win = win || (this->board[0][0] != '-' && this->board[0][0] == this->board[1][1] && this->board[0][0] == this->board[2][2]);
	win = win || (this->board[0][2] != '-' && this->board[0][2] == this->board[1][1] && this->board[0][2] == this->board[2][0]);

	win = win || (this->board[0][0] != '-' && this->board[0][0] == this->board[0][1] && this->board[0][0] == this->board[0][2]);
	win = win || (this->board[1][0] != '-' && this->board[1][0] == this->board[1][1] && this->board[1][0] == this->board[1][2]);
	win = win || (this->board[2][0] != '-' && this->board[2][0] == this->board[2][1] && this->board[2][0] == this->board[2][2]);

	win = win || (this->board[0][0] != '-' && this->board[0][0] == this->board[1][0] && this->board[0][0] == this->board[2][0]);
	win = win || (this->board[0][1] != '-' && this->board[0][1] == this->board[1][1] && this->board[0][1] == this->board[2][1]);
	win = win || (this->board[0][2] != '-' && this->board[0][2] == this->board[1][2] && this->board[0][2] == this->board[2][2]);

	return win;
}

bool ToeTacTic_Board::update_board(int x, int y, char symbol) {
	if (this->board[x][y] != '-') {
		return false;
	}

	this->n_moves++;
	this->board[x][y] = symbol;
	return true;
}
