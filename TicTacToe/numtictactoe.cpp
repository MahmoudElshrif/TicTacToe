#pragma once
#include "BoardGame_Classes.h"
#include <unordered_set>
#include <vector>
#include <numeric>

template <typename T>
class Numerical_Board : public Board<T> {
public:
    bool isEven;
    Numerical_Board();
    bool update_board(int x, int y, T symbol);
    void display_board();
    bool is_win();
    bool is_draw();
    bool game_is_over();

private:
    vector<int>even = { 2,4,6,8 };
    vector<int>odd = { 1,3,5,7,9 };
    std::unordered_set<int> used_numbers; // Track used numbers
    bool check_sum(int a, int b, int c);  // Helper to check if a triplet sums to 15
};

template <typename T>
class Numerical_Player : public Player<T> {
public:
    Numerical_Player(std::string name, T symbol);
    void getmove(int& x, int& y);
    bool isEven;
};

template <typename T>
class Numerical_Random_Player : public Numerical_Player<T> {
public:
    Numerical_Random_Player(T symbol);
    void getmove(int& x, int& y);
};

//--------------------------------------- IMPLEMENTATION

#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>

using namespace std;

// Constructor for Numerical_Board
template <typename T>
Numerical_Board<T>::Numerical_Board() {
    this->rows = this->columns = 3;
    this->board = new T * [this->rows];
    for (int i = 0; i < this->rows; i++) {
        this->board[i] = new T[this->columns]{ 0 }; // Initialize to 0
    }
    this->n_moves = 0;
}

// Update the board with the player's number
template <typename T>
bool Numerical_Board<T>::update_board(int x, int y, T number) {
    if (x < 0 || x >= 3 || y < 0 || y >= 3 || this->board[x][y] != 0 || used_numbers.count(number)) {
        return false;
    }
    this->board[x][y] = number;
    used_numbers.insert(number);
    this->n_moves++;
    return true;
}

// Display the board
template <typename T>
void Numerical_Board<T>::display_board() {
    for (int i = 0; i < this->rows; i++) {
        cout << "\n| ";
        for (int j = 0; j < this->columns; j++) {
            cout << setw(2) << (this->board[i][j] ? to_string(this->board[i][j]) : " ") << " |";
        }
        cout << "\n-------------";
    }
    cout << endl;
}

// Check if a triplet sums to 15
template <typename T>
bool Numerical_Board<T>::check_sum(int a, int b, int c) {

    return (a + b + c == 15);
}

// Check for a winning condition
template <typename T>
bool Numerical_Board<T>::is_win() {
    for (int i = 0; i < this->rows; i++) {
        // Check rows and columns
        if (check_sum(this->board[i][0], this->board[i][1], this->board[i][2]) ||
            check_sum(this->board[0][i], this->board[1][i], this->board[2][i])) {
            return true;
        }
    }
    // Check diagonals
    return (check_sum(this->board[0][0], this->board[1][1], this->board[2][2]) ||
        check_sum(this->board[0][2], this->board[1][1], this->board[2][0]));
}

// Check for a draw
template <typename T>
bool Numerical_Board<T>::is_draw() {
    return (this->n_moves == 9 && !is_win());
}

// Check if the game is over
template <typename T>
bool Numerical_Board<T>::game_is_over() {
    return is_win() || is_draw();
}

// Constructor for Numerical_Player
template <typename T>
Numerical_Player<T>::Numerical_Player(std::string name, T symbol) : Player<T>(name, symbol) {
}

// Get move from the player
template <typename T>
void Numerical_Player<T>::getmove(int& x, int& y) {
    cout << "\nEnter your move (row column number): ";
    cin >> x >> y;
    cin >> this->symbol;

    while ((this->isEven && this->symbol % 2 == 1) ||
        (!this->isEven && this->symbol % 2 == 0) || this->symbol <= 0 || this->symbol > 9) {
        cout << "Invalid move!\nEnter your move (row column number): ";
        cin >> x >> y;
        cin >> this->symbol;
    }
}
// Constructor for Numerical_Random_Player
template <typename T>
Numerical_Random_Player<T>::Numerical_Random_Player(T symbol) : Numerical_Player<T>("computer", symbol) {
    //this->dimension = 3;
    this->name = "Random PLayer Computer";
    srand(static_cast<unsigned int>(time(0)));
}// Seed RNG
// Get random move
template <typename T>
void Numerical_Random_Player<T>::getmove(int& x, int& y) {
    x = rand() % 3;
    y = rand() % 3;
    this->symbol = rand() % 9 + 1;  // Random number 1-9
    //  } //while (this->boardPtr->update_board(x, y, this->symbol) == true);
}

//#endif // UNTITLED2_NUMERICAL_TIC_TAC_TOE_H