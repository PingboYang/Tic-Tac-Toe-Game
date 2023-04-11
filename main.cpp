#include <iostream>
using namespace std;



void printBoard(char board[][3]);
bool isGameOver(char board[][3]);
bool isTie(char board[][3]);
int main() {
    char board[3][3] = { {' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '} };
    char player1 = 'X';
    char player2 = 'O';
  printBoard(board);
  
  do{
    int row, col;
    cout<<"Player1"<<"enter row(1-3)";
    cin>>row;
    cout<<"Player1"<<"enter col(1-3)";
    cin>>col;
    //check if if the input is valid
    if (row < 1 || row > 3 || col < 1 || col > 3 || board[row-1][col-1] != ' ') {
            cout << "Invalid move, try again." << endl;
            cout<<"Player1"<<"enter row(1-3)";
            cin>>row;
            cout<<"Player1"<<"enter col(1-3)";
            cin>>col;
        }
    board[row-1][col-1]=player1;
    printBoard(board);
    if(isGameOver(board)){
    cout<<"\nGame over, player1 wins!";
    break;
  }
    if(isTie(board)){
      cout<<"It's a tie, no winer!";
      break;
    }
    cout<<"Player2"<<" enter row(1-3)";
    cin>>row;
    cout<<"Player2"<<" enter col(1-3)";
    cin>>col;
     //check if if the input is valid
    if (row < 1 || row > 3 || col < 1 || col > 3 || board[row-1][col-1] != ' ') {
            cout << "Invalid move, try again." << endl;
            cout<<"Player2"<<" enter row(1-3)";
            cin>>row;
            cout<<"Player2"<<" enter col(1-3)";
            cin>>col;
        }
    board[row-1][col-1]=player2;
    printBoard(board);
    if(isGameOver(board)){
    cout<<"\nGame over, player2 wins!";
    break;
  }
    if(isTie(board)){
      cout<<"It's a tie, no winer!";
      break;
    }
    cout<<"\n\n--------------------------------------"<<endl;
  }
  while(!isGameOver(board));
  
  

    
    }
void printBoard(char board[][3]) {
    for (int i = 0; i < 3; i++) {
      
        for (int j = 0; j < 3; j++) {
            cout <<"|___"<< board[i][j];
        }
        cout << endl;
    }
}
bool isGameOver(char board[][3]){
  //check rows for a win
  for(int i=0; i<3; i++){
    if(board[i][0]!=' '&&board[i][0]==board[i][1] && board[i][1]==board[i][2]){
      return true;
    }
  }

  for(int j=0; j<3; j++){
    if(board[0][j]!=' '&&board[0][j]==board[1][j] && board[1][j]==board[2][j]){
      return true;
    }
  }
  if(board[0][0]!=' '&&board[0][0] == board[1][1] && board[1][1] == board[2][2]){
    return true;
  }
  if(board[0][2]!=' '&&board[0][2] == board[1][1] && board[1][1] == board[2][0]){
    return true;
  }
  return false;
}


bool isTie(char board[][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                return false; // Found an empty cell, game is not a tie
            }
        }
    }
    return true; // All cells are filled, game is a tie
}

    