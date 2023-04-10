#include <iostream>
using namespace std;



void printBoard(char board[][3]);
int main() {
    char board[3][3] = { {' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '} };
    char player1 = 'X';
    char player2 = 'O';
  printBoard(board);
  int row, col;
  cout<<"Player1"<<"enter row(1-3)";
  cin>>row;
  cout<<"Player1"<<"enter col(1-3)";
  cin>>col;
  board[row-1][col-1]=player1;
  printBoard(board);
  cout<<"Player2"<<" enter row(1-3)";
  cin>>row;
  cout<<"Player2"<<" enter col(1-3)";
  cin>>col;
  board[row-1][col-1]=player2;
  printBoard(board);

    
    }
void printBoard(char board[][3]) {
    for (int i = 0; i < 3; i++) {
      
        for (int j = 0; j < 3; j++) {
            cout <<"|___"<< board[i][j];
        }
        cout << endl;
    }
}

    