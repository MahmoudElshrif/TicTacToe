#pragma once
#pragma once
#include "BoardGame_Classes.h"



class Five_Player : public Player<char> {
public:
	Five_Player(string name, char symbol) : Player<char>(name, symbol) {};
	Five_Player(char symbol) : Player<char>(symbol) {};
	//void setBoard(ToeTacTic_Board* board) { Player<char>::setBoard/*(board);*/ };
	void getmove(int& x, int& y) override;

};

class Five_RandomPlayer : public Player<char> {
public:
	Five_RandomPlayer(string name, char symbol) : Player<char>(name, symbol) {};
	//void setBoard(ToeTacTic_Board* board) { Player<char>::setBoard/*(board);*/ };
	void getmove(int& x, int& y) override;

};

class Five_Board : public Board<char> {
private:
	int winner = -1;
public:
	Five_Board();
	bool is_win() override;
	bool is_draw() override { return winner == 0; };
	bool game_is_over() override;
	bool update_board(int x, int y, char symbol) override;
	void display_board() override;
	void count(int x, int y, int dirx, int diry,char symbol, int& counter,int count = 0);
};

