/*
Finding	the	length	of	connected	cells	of	1s	(regions)	in	an	matrix
of	0s	and 1s
Written By  : Smrity Chaudhary
Dated       : 04/02/2019
*/
#include<bits/stdc++.h>
using namespace std;

bool isValidCell(int* matrix, int maxsize, int row, int col);
int checkNeighbour(int* matrix, int maxsize, int row, int col, int* visited);
int largestRegion(int* matrix, int maxsize, int* visited);
void findRegion();
int main() {
    findRegion();
}
void findRegion() {
    /*
    OBJECTIVE :
    Take input from user and initialize a storage matrix to store visited cells
    */
    int maxsize;
    cout << "Enter the maximum size of matrix: ";
    cin >> maxsize;
    if (maxsize > 0) {
        int matrix[maxsize][maxsize];
        int visitedcell[maxsize][maxsize]; // Store visited cells
        cout << "\n Now, Enter the matrix....(1/0)\n";
        for(int row = 0; row < maxsize; row++) {
            cout << "\n----" <<row + 1 << " Row:----\n";
            for (int col = 0; col < maxsize; col++) {
                cin >> matrix[row][col];
                visitedcell[row][col] = 0;
            }
        }
        cout << "Largest region : ";
        cout << largestRegion(*matrix,maxsize,*visitedcell);
    }
    else {
        cout << "Matrix is empty...";
    }
}
int largestRegion(int* matrix, int maxsize, int* visited) {
    /*
    APPROACH :
    - Visit each cell in the matrix to find all possible existing regions.
    - A cell will not be visited twice thats why visited cell matrix is
        maintained, just to avoid the overhead.
    - Compare length of previous region with current region and maximum among
        them will be considered.
    */
    int lengthofregion = 0;
    for(int i = 0; i < maxsize; i++) {
        for (int j = 0; j < maxsize; j++) {
            if (*(matrix + i * maxsize + j) == 1 && *(visited + i * maxsize + j) !=1) {
                int curr_region = checkNeighbour(matrix, maxsize, i, j, visited);
                if (lengthofregion < curr_region) {
                    lengthofregion = curr_region;
                }
            }
        }
    }
    return lengthofregion;
}
int checkNeighbour(int* matrix, int maxsize, int row, int col, int* visited) {
    /*
    APPROACH :
    - Check if the current cell is valid.
    - Find non visited cell in its neighbourhood(i.e All 8 direction) and
        length of its region
    - Keep on adding the length of its neighbours region
    */
    if (isValidCell(matrix, maxsize, row, col) && *(visited + row * maxsize + col) != 1) {
        int lengthofregion = 1;
        *(visited + row * maxsize + col) = 1;
        lengthofregion += checkNeighbour(matrix, maxsize, row + 1, col, visited);
        lengthofregion += checkNeighbour(matrix, maxsize, row + 1, col + 1, visited);
        lengthofregion += checkNeighbour(matrix, maxsize, row, col + 1, visited);
        lengthofregion += checkNeighbour(matrix, maxsize, row + 1, col - 1, visited);
        lengthofregion += checkNeighbour(matrix, maxsize, row - 1, col + 1, visited);
        lengthofregion += checkNeighbour(matrix, maxsize, row - 1, col, visited);
        lengthofregion += checkNeighbour(matrix, maxsize, row, col - 1, visited);
        lengthofregion += checkNeighbour(matrix, maxsize, row - 1, col - 1, visited);
        return lengthofregion;
    }

    return 0;
}
bool isValidCell(int* matrix, int maxsize, int row, int col) {
    /*
    APPROACH :
    - Simply check whether row and column's values is correct
         (i.e 0 <= row/col >= maxsize)
    - Check whether this cell is valid (i.e. = 1) or not
    */
    if (row >= 0 && row < maxsize && col >= 0 && col < maxsize && *(matrix + row * maxsize + col) == 1) {
        return true;
    }
    return false;
}
