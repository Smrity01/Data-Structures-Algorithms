/*
Placing N queens on N*N chess-board without violating any rule.
Written By : Smrity Chaudhary
Dated : 03/02/2019
*/
#include<bits/stdc++.h>
using namespace std;

bool isValid(int *board,int n,int row,int col);
void printBoard(int* board,int row);
void nQueen(int* board,int numberofqueen,int col);
void placeNqueen();
int main() {
    placeNqueen();
}
void placeNqueen() {
    int numberofqueen;
    cout << "enter number of nqueens: ";
    cin >> numberofqueen;
    int board[numberofqueen][numberofqueen];
    for (int row = 0 ; row < numberofqueen; row++ ) {
        for (int col = 0 ; col < numberofqueen; col++) {
            board[row][col] = 0;
        }
    }
    //printBoard(*board,numberofqueen);
    nQueen(*board,numberofqueen,0);
}

void nQueen(int* board,int numberofqueen,int col) {
    if (col == numberofqueen) {
        printBoard(board,numberofqueen);
        return;
    }
    for (int itr = 0;itr < numberofqueen;itr++) {
        if (isValid(board,numberofqueen,itr,col)) {
            *(board+itr*numberofqueen+col) = 1;
            nQueen(board,numberofqueen,col+1);
            *(board+itr*numberofqueen+col) = 0;
        }
    }
    return;
}
bool isValid(int* board,int n,int row,int col) {
    for (int itr = 0;itr < col;itr++) {
        if(*(board+row*n+itr))
            return false;
    }
    int i,j;
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (*(board+i*n+j))
            return false;
    }

    for (i = row,j = col; j >= 0 && i < n; i++, j--) {
        if (*(board+i*n+j))
            return false;
    }

    return true;
}
void printBoard(int* board,int row) {
    if (row > 0) {
        cout << "\nN Queen On Chess Board...\n";
        for (int i = 0;i < row; i++){
            for (int j = 0;j < row; j++) {
                cout <<  *(board + i*row + j) << " ";
            }
            cout << "\n";
        }
    }
    return;
}
