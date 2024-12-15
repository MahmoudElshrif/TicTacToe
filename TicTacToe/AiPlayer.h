#pragma once
#include "BoardGame_Classes.h"

class AiPlayer : public Player<char>
{
protected:
	char** board;
	int** tempboard;
	bool isPlayerOne;
	int sizex, sizey;
public:
	char symbols[2] = { 'o','x' };
	AiPlayer(string name, char symbol, bool isPlayerOne);
	void setBoard(char** b, int sizex, int sizey);
	int virtual eval(bool isPlayerOne) = 0;
	int virtual search(int& x, int& y, bool isPlayerOne, int depth = 4);
	void getmove(int& x, int& y) override;
};

