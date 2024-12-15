#include "AiPlayer.h"


AiPlayer::AiPlayer(string name, char symbol, bool isPlayerOne) : Player(name, symbol), isPlayerOne(isPlayerOne) {
	tempboard = new int* [3];
	for (int i = 0; i < 3; i++) {
		tempboard[i] = new int[3] {-1, -1, -1};
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



int AiPlayer::search(int& x, int& y, bool isPlayerOne, int depth) {
	for (int i = 0; i < 9; i++) {
		//cout << counter[i] << " ";
	}
	int e = eval(isPlayerOne);
	if (depth == 0 || e != 0) {
		return e;
	}
	int currentmax = (depth == 4) ? 0 : -10;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			int temp = tempboard[i][j];
			if (temp != -1) continue;

			//gets the opposite of the evalution
			tempboard[i][j] = isPlayerOne;
			int evaluation = -search(x, y, !isPlayerOne, depth - 1);
			tempboard[i][j] = -1;

			if (depth == 4) {

				if (currentmax < evaluation) {
					x = i;
					y = j;
					//cout <<depth<< x << y << evaluation << endl;
					currentmax = evaluation;
				}
				else {
					currentmax += evaluation;
				}
			}
		}
	}


	return currentmax;
}