/*
Rat maze problem with two possible move for rat forward and down.
Written : Smrity Chaudhary
Dated : 03/02/2019
*/
#include<bits/stdc++.h>
using namespace std;

void printSolution(int* solution, int mazesize);
bool isValidMove(int* maze, int mazesize, int row, int col);
bool ratMaze(int *maze, int mazesize, int row, int col, int* solution);
void solveRatmaze();
int main() {
    solveRatmaze();
}
void solveRatmaze() {
    /*
    Objective : Take input from user and call Rat-maze function
    */
    int mazesize;
    cout << "Enter SIZE of maze: ";
    cin >> mazesize;
    int maze[mazesize][mazesize];
    cout << "\nEnter The MAZE...!!\n";
    int solution[mazesize][mazesize];
    for (int row = 0; row < mazesize; row++) {
        for (int col = 0; col < mazesize; col++) {
            cin >> maze[row][col];
            solution[row][col] = 0;
        }
        cout << "\n";
    }
    //Print the solution if exists
    if (ratMaze(*maze,mazesize,0,0,*solution) == true){
        printSolution(*solution,mazesize);
    }
    else {
        cout << "\nSorry no possible way for rat to come out from maze....!!";
    }
}
bool ratMaze(int* maze, int mazesize, int row, int col, int* solution) {
    // When the rat reaches its destination
    if (row == mazesize - 1 && col == mazesize - 1) {
        *(solution + row * mazesize + col) = 1;
        return true;
    }
    // check whether its a valid move or not
    if (isValidMove(maze,mazesize,row,col)) {
        *(solution + row * mazesize + col) = 1;
        // Take a step downward (BACKTRACK)
        if (ratMaze(maze,mazesize,row + 1,col,solution)) {
            return true;
        }
        // Take a step forward (BACKTRACK)
        if (ratMaze(maze,mazesize,row,col + 1,solution)) {
            return true;
        }
        // When no further path exist from this point
        *(solution + row * mazesize + col) = 0;
        return false;
    }
    return false;
}
bool isValidMove(int* maze, int mazesize, int row, int col) {
    // when IF row & column not exceed their limits & current position is open(i.e = 1)
    if (row >= 0 && row <= mazesize-1 && col >= 0 && col <= mazesize - 1 && *(maze + row*mazesize + col) == 1) {
        return true;
    }
    return false;
}
void printSolution(int* solution, int mazesize){
    cout << "\nThe path to from source to destination is represented by 'R'\n";
    for (int row = 0; row < mazesize; row++) {
        for (int col = 0; col < mazesize; col++) {
            if(*(solution + row * mazesize + col)) {
                cout << "R";
            }
            else {
                cout << "_";
            }
        }
        cout << "\n";
    }
}
