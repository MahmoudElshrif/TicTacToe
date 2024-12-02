#include <iostream>
#include "ToeTacTic.h"


using namespace std;

int main() {
    srand(time(0));
    int choice1,choice2;
    Player<char>* players[2];
    ToeTacTic_Board* B = new ToeTacTic_Board();
    string playerXName, player2Name;

    cout << "Welcome to Inverse Tic Tac Toe (Toe Tac Tic)\n";

    // Set up player 1
    cout << "Enter Player X name: ";
    cin >> player2Name;
    cout << "Choose Player X type:\n";
    cout << "1. Human\n";
    cout << "2. Random Computer\n";
    cin >> choice1;


    // Set up player 2
    cout << "Enter Player 2 name: ";
    cin >> playerXName;
    cout << "Choose Player 2 type:\n";
    cout << "1. Human\n";
    cout << "2. Random Computer\n";
    cin >> choice2;
    
    switch (choice1) {
    case 1:
        players[0] = new ToeTacTic_Player(playerXName, 'X');
        break;
    case 2:
        players[0] = new ToeTacTic_RandomPlayer(playerXName,'X');
        break;
    default:
        cout << "Invalid choice for Player 1. Exiting the game.\n";
        return 1;
    }

    switch (choice2) {
    case 1:
        players[1] = new ToeTacTic_Player(player2Name, 'O');
        break;
    case 2:
        players[1] = new ToeTacTic_RandomPlayer(player2Name,'O');
        break;
    default:
        cout << "Invalid choice for Player 2. Exiting the game.\n";
        return 1;
    }

    // Create the game manager and run the game
    GameManager<char> x_o_game(B, players);
    x_o_game.run();

    // Clean up
    delete B;
    for (int i = 0; i < 2; ++i) {
        delete players[i];
    }

    return 0;
}



