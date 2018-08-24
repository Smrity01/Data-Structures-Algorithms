/*
 Print Spiral matrix
 Written By: Smrity Chaudhary
 Dated     : 24/08/2018
*/
#include<iostream>
using namespace std;

void spiralmatrix(int a[4][5],int row,int col);
int main(){
  /*
  Objective        : Declare an initialize the array and spiralmatrix() function
  Input Parameters : None
  Output values    : None
  */
  int A[4][5]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
  spiralmatrix(A,4,5);
}
void spiralmatrix(int a[4][5],int row,int col){
  /*
  Objective        : To print spiral matrix
  Input Parameters : Given matrix
                     Number of rows and columns
  Output values    : Matrix Element in spiral form
  Approach         : First print first row, last column, last row,
                    and first column of the matrix. Repeat the process on
                    remaining matrix.
  */
  int elements = row*col;
  int i = 0,j = 0;
  while (elements>0){
    //print first row of the matrix
    for (int index = j;index < col;index++){
      cout << a[i][index] << ",";
      elements--;
    }
    col--;
    i++;
    //print last column of the matrix
    for (int index = i;index < row;index++){
      cout << a[index][col] << ",";
      elements--;
    }
    row--;
    //print last row of the matrix
    for (int index = col-1;index>=j;index--){
      cout << a[row][index] << ",";
      elements--;
    }
    //print first column of the matrix
    for (int index = row-1;index>=i;index--){
      cout << a[index][j] << ",";
      elements--;
    }
    j++;
  }

  return;
}
