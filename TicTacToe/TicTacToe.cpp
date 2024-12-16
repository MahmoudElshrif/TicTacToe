#include <iostream>
#include "ToeTacTic.h"
#include "FiveTicTacToe.h"
#include "BigTicTacToe.h"
#include "SusGame.h"
#include "Four-in-a-row.h"
#include "Numerical Tic-Tac-Toe.h"
#include "3x3X_O.h"
#include "pyramic.h"
#include "wordic.h"

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
    cout << "2. AI\n";
    cin >> choice1;


    // Set up player 2
    cout << "Enter Player 2 name: ";
    cin >> playerXName;
    cout << "Choose Player 2 type:\n";
    cout << "1. Human\n";
    cout << "2. AI\n";
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
    BigBoard<char>* B = new BigBoard<char>();
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
        players[0] = new Big_Player<char>(playerXName, 'X');
        break;
    case 2:
        players[0] = new Big_RandomPlayer<char>(playerXName, 'X');
        break;
    default:
        cout << "Invalid choice for Player 1. Exiting the game.\n";
        return;
    }

    switch (choice2) {
    case 1:
        players[1] = new Big_Player<char>(player2Name, 'O');
        break;
    case 2:
        players[1] = new Big_RandomPlayer<char>(player2Name, 'O');
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
    Sus_Player<char>* players[2];
    Sus_Board<char>* B = new Sus_Board<char>();
    string playerXName, player2Name;

    cout << "Welcome to Inverse Tic Tac Toe (Toe Tac Tic)\n";

    // Set up player 1
    cout << "Enter Player X name: ";
    //cin >> playerXName;
    cout << "Choose Player X type:\n";
    cout << "1. Human\n";
    cout << "2. Random Computer\n";
    cin >> choice1;


    // Set up player 2
    cout << "Enter Player 2 name: ";
    //cin >> player2Name;
    cout << "Choose Player 2 type:\n";
    cout << "1. Human\n";
    cout << "2. Random Computer\n";
    cin >> choice2;

    //Sus_AiPlayer* player;
    switch (choice1) {
    case 1:
        players[0] = new Sus_Player<char>(playerXName, 'S');
        break;
    case 2:
        players[0] = new Sus_RandomPlayer<char>(playerXName, 'S');
        break;
    default:
        cout << "Invalid choice for Player 1. Exiting the game.\n";
        return;
    }

    switch (choice2) {
    case 1:
        players[1] = new Sus_Player<char>(player2Name, 'U');
        break;
    case 2:
        players[1] = new Sus_RandomPlayer<char>(player2Name, 'U');
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

void four() {
    string choice;
    Player<char>* players[2];
    Board<char>* B = new Four_in_a_row_Board<char>();
    string player1Name, player2Name;
    cout << "Welcome to FCAI Four-In-A-Row Game. :)\n";
    // Set up player 1
    cout << "Choose Player1 (X) type:\n";
    cout << "1. Human\n";
    cout << "2. Random Computer\n";
    cin >> choice;

    if (choice == "1") {
        cout << "Enter name of this player1: ";
        cin.ignore();
        getline(cin, player1Name);
        players[0] = new Four_in_a_row_Player<char>(player1Name, 'X');
    }
    else if (choice == "2") {
        cout << "Enter name of this player1: ";
        players[0] = new Four_in_a_row_Random_Player<char>('X');
    }
    else {
        cout << "Invalid choice for Player 1. Exiting the game.\n";
        return;
    }

    // Set up player 2
    cout << "Choose Player2 (O) type:\n";
    cout << "1. Human\n";
    cout << "2. Random Computer\n";
    cin >> choice;

    if (choice == "1") {
        cout << "Enter name of this player2: ";
        cin.ignore();
        getline(cin, player2Name);
        players[1] = new Four_in_a_row_Player<char>(player2Name, 'O');
    }
    else if (choice == "2") {
        cout << "Enter name of this player2: ";
        players[1] = new Four_in_a_row_Random_Player<char>('O');
    }
    else {
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

void numerical() {
    string choice;
    Numerical_Player<int>* players[2];
    Board<int>* B = new Numerical_Board<int>();
    string player1Name, player2Name;
    cout << "Welcome to FCAI Numerical Tic-Tac-Toe!\n";
    cout << "Choose The First Player Chooses From odd numbers only (1, 3, 5, 7, 9) type:\n1. Human\n2. Random Computer\n";
    cin >> choice;
    // Player 1 setup
    if (choice == "1") {
        cout << "Enter The First PLayer name: ";
        cin.ignore();
        getline(cin, player1Name);
        players[0] = new Numerical_Player<int>(player1Name, false);
    }
    else if (choice == "2") {
        cout << "Enter The Random First Player name: ";
        players[0] = new Numerical_Random_Player<int>(0);
    }
    else {
        cout << "Invalid Choice For First Player. Exiting The Game.\n";
        return;
    }
    // Player 2 setup;
    cout << "Choose The Second Player Chooses From Even Numbers only (2, 4, 6, 8) type:\n1. Human\n2. Random Computer\n";
    cin >> choice;
    if (choice == "1") {
        cout << "Enter The Second PLayer name: ";
        cin.ignore();
        getline(cin, player2Name);
        players[1] = new Numerical_Player<int>(player2Name, true);
    }
    else if (choice == "2") {
        cout << "Enter The Random Second Player name: ";
        players[1] = new Numerical_Random_Player<int>(0);
    }
    else {
        cout << "Invalid Choice For Second Player. Exiting The Game.\n";
        return;
    }

    players[0]->isEven = false;
    players[1]->isEven = true;

    // Create the game manager
    Player<int>* p[2] = { static_cast<Player<int>*>(players[0]),static_cast<Player<int>*>(players[1]) };

    GameManager<int> game(static_cast<Board<int>*>(B), p);
    game.run();
    // Cleanup
    delete B;
    delete players[0];
    delete players[1];
}

void wordic() {
    int choice;
    Player<char>* players[2];
    Wordic_Board<char>* B = new Wordic_Board<char>();
    string playerXName, player2Name;

    cout << "Welcome to FCAI X-O Game. :)\n";

    // Set up player 1
    cout << "Enter Player X name: ";
    cin >> playerXName;
    cout << "Choose Player X type:\n";
    cout << "1. Human\n";
    cout << "2. Random Computer\n";
    cin >> choice;

    switch (choice) {
    case 1:
        players[0] = new Wordic_Player<char>(playerXName, 'X');
        break;
    case 2:
        players[0] = new X_O_Random_Player<char>('X');
        break;
    default:
        cout << "Invalid choice for Player 1. Exiting the game.\n";
        return;
    }

    // Set up player 2
    cout << "Enter Player 2 name: ";
    cin >> player2Name;
    cout << "Choose Player 2 type:\n";
    cout << "1. Human\n";
    cout << "2. Random Computer\n";
    cin >> choice;

    switch (choice) {
    case 1:
        players[1] = new Wordic_Player<char>(player2Name, 'O');
        break;
    case 2:
        players[1] = new X_O_Random_Player<char>('O');
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

void pyramic() {
    int choice;
    Player<char>* players[2];
    PyramicBoard<char>* B = new PyramicBoard<char>();
    string playerXName, player2Name;

    cout << "Welcome to FCAI X-O Game. :)\n";

    // Set up player 1
    cout << "Enter Player X name: ";
    cin >> playerXName;
    cout << "Choose Player X type:\n";
    cout << "1. Human\n";
    cout << "2. Random Computer\n";
    cin >> choice;

    switch (choice) {
    case 1:
        players[0] = new X_O_Player<char>(playerXName, 'X');
        break;
    case 2:
        players[0] = new X_O_Random_Player<char>('X');
        break;
    default:
        cout << "Invalid choice for Player 1. Exiting the game.\n";
        return;
    }

    // Set up player 2
    cout << "Enter Player 2 name: ";
    cin >> player2Name;
    cout << "Choose Player 2 type:\n";
    cout << "1. Human\n";
    cout << "2. Random Computer\n";
    cin >> choice;

    switch (choice) {
    case 1:
        players[1] = new X_O_Player<char>(player2Name, 'O');
        break;
    case 2:
        players[1] = new X_O_Random_Player<char>('O');
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

int main() {

    cout << "1) Pyramic Tic-Tac-Toe\n";
    cout << "2) Four-in-a-row\n";
    cout << "3) 5 x 5 Tic Tac Toe\n";
    cout << "4) Word Tic-tac-toe\n";
    cout << "5) Numerical Tic-Tac-Toe\n";
    cout << "6) Misere Tic Tac Toe\n";
    cout << "7) Ultmate Tic Tac Toe\n";
    cout << "8) Sus game\n";

    int op;
    cin >> op;

    switch (op) {
    case 1:
        pyramic();
        break;
    case 2:
        four();
        break;
    case 3:
        fiveboard();
        break;
    case 4:
        wordic();
        break;
    case 5:
        numerical();
        break;
    case 6:
        reverse();
        break;
    case 7:
        bigboard();
        break;
    case 8:
        sus();
        break;
    default:
        break;

    }

    return 0;
}