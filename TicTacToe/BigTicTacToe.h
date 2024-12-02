#pragma once
#pragma once
#include "BoardGame_Classes.h"



class Big_Player : public Player<char> {
public:
	Big_Player(string name, char symbol) : Player<char>(name, symbol) {};
	Big_Player(char symbol) : Player<char>(symbol) {};
	//void setBoard(ToeTacTic_Board* board) { Player<char>::setBoard/*(board);*/ };
	void getmove(int& x, int& y) override;

};

class Big_RandomPlayer : public Player<char> {
public:
	Big_RandomPlayer(string name, char symbol) : Player<char>(name, symbol) {};
	//void setBoard(ToeTacTic_Board* board) { Player<char>::setBoard/*(board);*/ };
	void getmove(int& x, int& y) override;

};

class Big_Board : public Board<char> {
private:
	int winner = -1;
public:
	Big_Board();
	bool is_win() override;
	bool is_draw() override { return winner == 0; };
	bool game_is_over() override { return winner != -1; };
	bool update_board(int x, int y, char symbol) override;
	void display_board() override;
	void count(int x, int y, int dirx, int diry,char symbol, int& counter,int count = 0);
};

