#include "AiPlayer.h"




AiPlayer::AiPlayer(string name, char symbol, bool isPlayerOne) : Player(name, symbol), isPlayerOne(isPlayerOne) {
	tempboard = new int* [3];
	for (int i = 0; i < 3; i++) {
		tempboard[i] = new int[3] {-1,-1,-1};
	}
}

void AiPlayer::getmove(int& x, int& y) {
	//constructs a temp board to do search on
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			//-1 empty
			//0 for player one
			//1 for player 2
			auto symb = tolower(board[x][y]);
			if (symb == symbols[0]) {
				tempboard[x][y] = 0;
			}
			else if (symbol == symbols[!isPlayerOne]) {
				tempboard[x][y] = 1;
			}
			else {
				tempboard[x][y] = -1;
			}
		}
	}

	search(x, y, isPlayerOne);
}


int AiPlayer::search(int& x, int& y,bool isPlayerOne,int depth) {
	int e = eval(isPlayerOne);
	if (depth == 0 || eval != 0) {
		return e;
	}

	int currentmax = INT_MIN;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			char temp = board[i][j];
			if (temp != symbols[0] && temp != symbols[1]) continue;
			board[i][j] = symbol;
			//gets the opposite of the evalution 
			int eval = -search(x, y,!isPlayerOne,depth - 1);
			board[i][j] = temp;
			if (currentmax < eval) {
				x = i;
				y = j;
				currentmax = eval;
			}
		}
	}

	return eval(isPlayerOne);
}