#include <iostream>
#include "ToeTacTic.h"
#include "FiveTicTacToe.h"
#include "BigTicTacToe.h"
#include "SusGame.h"

using namespace std;

void reverse() {
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
    
    ToeTacTic_AiPlayer* player;
    switch (choice1) {
    case 1:
        players[0] = new ToeTacTic_Player(playerXName, 'X');
        break;
    case 2:
        player = new ToeTacTic_AiPlayer(playerXName, 'X', true);
        setBoard(B, player);
        players[0] = player;
        break;
    default:
        cout << "Invalid choice for Player 1. Exiting the game.\n";
        return;
    }

    switch (choice2) {
    case 1:
        players[1] = new ToeTacTic_Player(player2Name, 'O');
        break;
    case 2:
        player = new ToeTacTic_AiPlayer(player2Name, 'O', false);
        setBoard(B, player);
        players[1] = player;
        break;
    default:
        cout << "Invalid choice for Player 2. Exiting the game.\n";
        return;
    }

    // Create the game manager and run the game
    GameManager<char> x_o_game(B, players);
    x_o_game.run();

    // Clean up
    delete B;
    for (int i = 0; i < 2; ++i) {
        delete players[i];
    }
}

void fiveboard() {
    srand(time(0));
    int choice1, choice2;
    Player<char>* players[2];
    Five_Board* B = new Five_Board();
    string playerXName, player2Name;

    cout << "Welcome to 5x5 Tic Tac Toe\n";

    // Set up player 1
    //cout << "Enter Player X name: ";
    //cin >> player2Name;
    cout << "Choose Player X type:\n";
    cout << "1. Human\n";
    cout << "2. Random Computer\n";
    cin >> choice1;


    // Set up player 2
    //cout << "Enter Player 2 name: ";
    //cin >> playerXName;
    cout << "Choose Player 2 type:\n";
    cout << "1. Human\n";
    cout << "2. Random Computer\n";
    cin >> choice2;

    switch (choice1) {
    case 1:
        players[0] = new Five_Player("Player 1", 'X');
        break;
    case 2:
        players[0] = new Five_RandomPlayer("Player 1", 'X');
        break;
    default:
        cout << "Invalid choice for Player 1. Exiting the game.\n";
        return;
    }

    switch (choice2) {
    case 1:
        players[1] = new Five_Player("Player 2", 'O');
        break;
    case 2:
        players[1] = new Five_RandomPlayer("Player 2", 'O');
        break;
    default:
        cout << "Invalid choice for Player 2. Exiting the game.\n";
        return;
    }

    // Create the game manager and run the game
    GameManager<char> x_o_game(B, players);
    x_o_game.run();

    // Clean up
    delete B;
    for (int i = 0; i < 2; ++i) {
        delete players[i];
    }

    return;
}

void bigboard() {
    srand(time(0));
    int choice1, choice2;
    Player<char>* players[2];
    BigBoard* B = new BigBoard();
    string playerXName, player2Name;

    cout << "Welcome to Inverse Big Tic Tac Toe\n";

    // Set up player 1
    cout << "Enter Player X name: ";
    cin >> playerXName;
    cout << "Choose Player X type:\n";
    cout << "1. Human\n";
    cout << "2. Random Computer\n";
    cin >> choice1;


    // Set up player 2
    cout << "Enter Player 2 name: ";
    cin >> player2Name;
    cout << "Choose Player 2 type:\n";
    cout << "1. Human\n";
    cout << "2. Random Computer\n";
    cin >> choice2;

    switch (choice1) {
    case 1:
        players[0] = new Big_Player(playerXName, 'X');
        break;
    case 2:
        players[0] = new Big_RandomPlayer(playerXName, 'X');
        break;
    default:
        cout << "Invalid choice for Player 1. Exiting the game.\n";
        return;
    }

    switch (choice2) {
    case 1:
        players[1] = new Big_Player(player2Name, 'O');
        break;
    case 2:
        players[1] = new Big_RandomPlayer(player2Name, 'O');
        break;
    default:
        cout << "Invalid choice for Player 2. Exiting the game.\n";
        return;
    }

    // Create the game manager and run the game
    GameManager<char> x_o_game(B, players);
    x_o_game.run();

    // Clean up
    delete B;
    for (int i = 0; i < 2; ++i) {
        delete players[i];
    }
}

void sus() {
    srand(time(0));
    int choice1, choice2;
    Sus_Player* players[2];
    Sus_Board* B = new Sus_Board();
    string playerXName, player2Name;

    cout << "Welcome to Inverse Tic Tac Toe (Toe Tac Tic)\n";

    // Set up player 1
    cout << "Enter Player X name: ";
    cin >> playerXName;
    cout << "Choose Player X type:\n";
    cout << "1. Human\n";
    cout << "2. Random Computer\n";
    cin >> choice1;


    // Set up player 2
    cout << "Enter Player 2 name: ";
    cin >> player2Name;
    cout << "Choose Player 2 type:\n";
    cout << "1. Human\n";
    cout << "2. Random Computer\n";
    cin >> choice2;

    //Sus_AiPlayer* player;
    switch (choice1) {
    case 1:
        players[0] = new Sus_Player(playerXName, 'S');
        break;
    case 2:
        //players[0] = new Sus_RandomPlayer(playerXName, 'X', true);
        break;
    default:
        cout << "Invalid choice for Player 1. Exiting the game.\n";
        return;
    }

    switch (choice2) {
    case 1:
        players[1] = new Sus_Player(player2Name, 'U');
        break;
    case 2:
        //players[1] = new Sus_RandomPlayer(player2Name, 'U', true);
        break;
    default:
        cout << "Invalid choice for Player 2. Exiting the game.\n";
        return;
    }


    B->setPlayers(players);

    Player<char>* p[2]{(Player<char>*)players[0],(Player<char>*)players[1] };

    // Create the game manager and run the game
    GameManager<char> x_o_game(B, p);
    x_o_game.run();

    // Clean up
    delete B;
    for (int i = 0; i < 2; ++i) {
        delete players[i];
    }
}

int main() {

    cout << "1) Inverse Tic Tac Toe\n";
    cout << "2) 5x5 Tic Tac Toe\n";
    cout << "3) Big Tic Tac Toe\n";
    cout << "4) Sus game\n";

    int op;
    cin >> op;

    switch (op) {
    case 1:
        reverse();
        break;
    case 2:
        fiveboard();
        break;
    case 3:
        bigboard();
        break;
    case 4:
        sus();
        break;
    }

    return 0;
}