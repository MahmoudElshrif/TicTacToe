#pragma once
#include "BoardGame_Classes.h"

class AiPlayer : public Player<char>
{

	char** board;
	bool isPlayerOne;

public:
	AiPlayer(string name, char symbol, bool isPlayerOne) : Player(name, symbol), isPlayerOne(isPlayerOne) {}
	void setBoard(char** b, int sizex, int sizey) { for (int x = 0; x < sizex; x++) for (int y = 0; y < sizey; y++) board[x][y] = b[x][y]; }
	int virtual eval() = 0;
	int virtual search(int depth) = 0;
};

