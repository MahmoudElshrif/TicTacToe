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
			char symb = tolower(board[i][j]);
			if (symb == symbols[0]) {
				tempboard[i][j] = 0;
			}
			else if (symb == symbols[1]) {
				tempboard[i][j] = 1;
			}
			else {
				tempboard[i][j] = -1;
			}
		}
	}

	search(x, y, isPlayerOne);
}


int AiPlayer::search(int& x, int& y,bool isPlayerOne,int depth) {
	int e = eval(isPlayerOne);
	if (depth == 0 || e != 0) {
		return e;
	}

	int currentmax = INT_MIN;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			int temp = tempboard[i][j];
			if (temp != -1) continue;
			tempboard[i][j] = isPlayerOne;
			//gets the opposite of the evalution
			int evaluation = -search(i, j,!isPlayerOne,depth - 1);
			tempboard[i][j] = temp;
			if (currentmax < evaluation) {
				x = i;
				y = j;

				currentmax = evaluation;
			}
		}
	}
	
	return e;
}