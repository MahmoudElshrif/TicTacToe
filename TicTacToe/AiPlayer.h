#pragma once
#include "BoardGame_Classes.h"

class AiPlayer : public Player<char>
{

	char** board;
	int** tempboard;
	bool isPlayerOne;

public:
	char symbols[2] = { 'x','o' };
	AiPlayer(string name, char symbol, bool isPlayerOne);
	void setBoard(char** b, int sizex, int sizey) { board = b; }
	int virtual eval(bool isPlayerOne) = 0;
	int virtual search(int& x,int& y,bool isPlayerOne,int depth = 3);
	void getmove(int& x,int& y) override;
};

