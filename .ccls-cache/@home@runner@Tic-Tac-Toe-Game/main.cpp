#include <iostream>
using namespace std;

// Function to print the Tic Tac Toe board
void printBoard(char board[][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

// Function to check if the game is over
bool isGameOver(char board[][3]) {
    // Check rows for a win
    for (int i = 0; i < 3; i++) {
        if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return true;
        }
    }
    // Check columns for a win
    for (int j = 0; j < 3; j++) {
        if (board[0][j] != ' ' && board[0][j] == board[1][j] && board[1][j] == board[2][j]) {
            return true;
        }
    }
    // Check diagonals for a win
    if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return true;
    }
    if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return true;
    }
    // Check for a tie
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

int main() {
    char board[3][3] = { {' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '} };
    char player = 'X';

    while (!isGameOver(board)) {
        // Print the board and get the player's move
        printBoard(board);
        int row, col;
        cout << "Player " << player << ", enter row (0-2): ";
        cin >> row;
        cout << "Player " << player << ", enter col (0-2): ";
        cin >> col;

        // Check if the move is valid
        if (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != ' ') {
            cout << "Invalid move, try again." << endl;
            continue;
        }

        // Update the board and switch players
        board[row][col] = player;
        player = (player == 'X') ? 'O' : 'X';
    }

    // Print the final board and the winner
    printBoard(board);
    if (isGameOver(board)) {
        cout << "Game over, ";
        if (player == 'X') {
            cout << "O wins!" << endl;
        } else {
            cout << "X wins!" << endl;
        }
    } else {
        cout << "It's a tie!" << endl;
    }

    return 0;
}
