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
	for (int x = 0; x < 3; x++) {
		for (int y = 0; y < 3; y++) {
			cout << this->board[x][y] << " ";
		}
		cout << endl;
	}
	cout << endl;
}


void ToeTacTic_RandomPlayer::getmove(int& x,int& y) {
	x = rand() % 3;
	y = rand() % 3;
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
