#include "AiPlayer.h"




AiPlayer::AiPlayer(string name, char symbol, bool isPlayerOne) : Player(name, symbol), isPlayerOne(isPlayerOne) {

}

void AiPlayer::setBoard(char** b, int sizex, int sizey) {
	board = b;
	this->sizex = sizex;
	this->sizey = sizey;


	tempboard = new int* [sizex];
	for (int i = 0; i < sizex; i++) {
		tempboard[i] = new int[sizey];
		for (int j = 0; j < sizey; j++) {
			tempboard[i][j] = -1;
		}
	}
}

void AiPlayer::getmove(int& x, int& y) {
	//constructs a temp board to do search on
	for (int i = 0; i < this->sizex; i++) {
		for (int j = 0; j < this->sizey; j++) {
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

	//cout << isPlayerOne << endl;
	search(x, y, isPlayerOne);
}


int AiPlayer::search(int& x, int& y, bool isPlayerOne, int depth) {
	//cout << ++counter << " " << depth << endl;
	//counter[depth]++;
	for (int i = 0; i < 9; i++) {
		//cout << counter[i] << " ";
	}
	int e = -eval(isPlayerOne);
	//cout << isPlayerOne << endl;
	if (depth == 0) {
		return e;
	}
	int currentmax = -10;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			int temp = tempboard[i][j];
			if (temp != -1) continue;

			//gets the opposite of the evalution
			tempboard[i][j] = isPlayerOne;
			int tempx = x, tempy = y;
			int evaluation = -search(x, y, !isPlayerOne, depth - 1);
			tempboard[i][j] = -1;

			x = tempx, y = tempy;

			if (currentmax <= evaluation) {
				x = i;
				y = j;
				//cout <<depth<< x << y << evaluation << endl;
				currentmax = evaluation;
			}
		}
	}


	//cout << depth << " " << currentmax << endl;
	return currentmax;
}