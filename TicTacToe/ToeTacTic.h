#pragma once
#include "BoardGame_Classes.h"



class ToeTacTic_Player : public Player<char> {
public:
	ToeTacTic_Player(string name, char symbol) : Player<char>(name, symbol) {};
	ToeTacTic_Player(char symbol) : Player<char>(symbol) {};
	//void setBoard(ToeTacTic_Board* board) { Player<char>::setBoard/*(board);*/ };
	void getmove(int& x, int& y) override;

};

class ToeTacTic_RandomPlayer : public Player<char> {
public:
	ToeTacTic_RandomPlayer(string name,char symbol) : Player<char>(name,symbol) {};
	//void setBoard(ToeTacTic_Board* board) { Player<char>::setBoard/*(board);*/ };
	void getmove(int& x, int& y) override;

};

class ToeTacTic_Board : public Board<char> {
public:
	ToeTacTic_Board();
	bool is_win() override;
	bool is_draw() override { return this->n_moves == 9; };
	bool game_is_over() override { return is_win() || is_draw(); }
	bool update_board(int x, int y, char symbol) override;
	void display_board() override;
};

