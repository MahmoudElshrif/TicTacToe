#include "BigTicTacToe.h"


void Big_Player::getmove(int& x, int& y) {
	cout << "Row: ";
	cin >> x;
	cout << "Column: ";
	cin >> y;

	while (x < 0 || x > 5 || y < 0 || y > 5) {
		cout << "invalid move\n";
		cout << "Row: ";
		cin >> x;
		cout << "Column: ";
		cin >> y;
	}
}


Big_Board::Big_Board() {
	this->board = new char* [5];
	for (int x = 0; x < 5; x++) {
		this->board[x] = new char[5];
		for (int y = 0; y < 5; y++) {
			this->board[x][y] = '-';
		}
	}
}


void Big_Board::display_board() {
	if (game_is_over())
		return;
	for (int x = 0; x < 5; x++) {
		for (int y = 0; y < 5; y++) {
			cout << this->board[x][y] << " ";
		}
		cout << endl;
	}
	cout << endl;
}


void Big_RandomPlayer::getmove(int& x, int& y) {
	x = rand() % 5;
	y = rand() % 5;
}


bool Big_Board::update_board(int x, int y, char symbol) {
	if (this->board[x][y] != '-' && !game_is_over()) {
		return false;
	}

	this->n_moves++;
	this->board[x][y] = symbol;
	return true;
}



void Big_Board::count(int x, int y, int dirx, int diry, char symb, int& counter,int count) {
	if (x > 4 || y > 4 || x < 0 || y < 0)
		return;
	if (board[x][y] != symb) {
		return;
	}
	if (count == 2) {
		counter++;
		return;
	}
	this->count(x + dirx, y + diry, dirx, diry, symb, counter, count + 1);
}

bool Big_Board::is_win() {
	if (this->n_moves == 25) {
		int count[2]{ 0,0 };
		for (int x = 0; x < 5; x++) {
			for (int y = 0; y < 5; y++) {
				char symb = board[x][y];
				if (symb == '-')
					continue;
				int& counter = symb == 'X' ? count[0] : count[1];
				this->count(x, y, 1,-1, symb, counter);
				this->count(x, y, 1, 0, symb, counter);
				this->count(x, y, 1, 1, symb, counter);
				this->count(x, y, 0, 1, symb, counter);
			}
		}
		cout << "Player 1: " << count[0] << endl;
		cout << "Player 2: " << count[1] << endl;

		if (count[0] == count[1]) {
			winner = 0;
		}
		else if (count[0] > count[1]) {
			winner = 1;
		}
		else {
			winner = 2;
		}
		
	}
	if ((winner == 1 && n_moves % 2 == 0) || (winner == 2 && n_moves % 2 == 1)) {
		return true;
	}
	return false;
}