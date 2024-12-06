#pragma once
#include "BoardGame_Classes.h"


class Big_Board : public Board<char>
{
	SubBoard** boards;
	const string symbols[3][3] = {
		{"\\ /",
		 " . ",
		 "/ \\"},//x
		{" - ",
		 "| |",
		 " - "},//o
		{"   ",
		 " - ",
		 "   "}//-
	};



public:
	Big_Board();
	bool update_board(int x,int y,char symb) override;
	void display_board() override;
	bool is_win() override;
	bool is_draw() override {};
	bool game_is_over() override { return is_win() || is_draw(); }

};


class SubBoard {
	char** Board;
	bool isOver = false;
	char current = '-';
public:

	int makeMove(int x,int y,char symb);
	char getValue() { return current; }

};
