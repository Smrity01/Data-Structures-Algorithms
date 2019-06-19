/*
You are given an n x n 2D matrix representing an image.
Rotate the image by 90 degrees (clockwise).
You need to do this in place.
Note that if you end up using an additional array, you will only receive partial score.
*/
#include<iostream>
#include<vector>
using namespace std;
void rotate(vector<vector<int> > &A);
int main(){
    vector< vector<int> > A;
    for ( int i = 0; i < 3; i++ ) {
        A.push_back (vector<int>() );
        for ( int j = 0; j < 3; j++ ){
            A[i].push_back ( i + j );
    }
  }
  rotate(A);
}
void rotate(vector<vector<int> > &A) {
    int n = A.size() - 1 ;
    int temp;
    for (int i = 0; i < A.size() / 2; i++){
        for (int j = i; j < n - i; j++){
            temp = A[i][j];
            A[i][j] = A[n - j][i];
            A[n - j][i] = A[n - i][n - j];
            A[n - i][n - j] = A[j][n - i];
            A[j][n - i] = temp;
        }
    }
}
