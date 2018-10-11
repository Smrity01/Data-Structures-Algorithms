/*
 Print Spiral matrix
 Written By: Smrity Chaudhary
 Dated     : 24/08/2018
*/
#include<iostream>
using namespace std;

void spiralmatrix(int a[1][1],int row,int col);
int main(){
  /*
  Objective        : Declare an initialize the array and spiralmatrix() function
  Input Parameters : None
  Output values    : None
  */
  int A[3][1]={1,2,3};
  spiralmatrix(A,3,1);
}
void spiralmatrix(int a[1][1],int row,int col){
  /*
  Objective        : To print spiral matrix
  Input Parameters : Given matrix
                     Number of rows and columns
  Output values    : Matrix Element in spiral form
  Approach         : First print first row, last column, last row,
                    and first column of the matrix. Repeat the process on
                    remaining matrix.
  */
  int i = 0,j = 0;
  while (i<row && j<col){
    //print first row of the matrix
    for (int index = j;index < col;index++){
      cout << a[i][index] << ",";
    }
    i++;
    //print last column of the matrix
    for (int index = i;index < row;index++){
      cout << a[index][col-1] << ",";
    }
    col--;
    //print last row of the matrix
    if(i<row){
        for (int index = col-1;index>=j;index--){
                cout << a[row-1][index] << ",";
        }
        row--;
    }
    //print first column of the matrix
    if(j<col){
        for (int index = row-1;index>=i;index--){
                cout << a[index][j] << ",";
        }
        j++;
    }
  }

  return;
}
