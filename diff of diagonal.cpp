/*
difference of diagonal elements
  written by: smrity chaudhary
  date: 4/01/2018
*/
#include<iostream>
#include<cstdlib>
using namespace std;

int main(){
    int length;
    cout << "Enter the size of matrix: ";
    cin >> length;
    int matrix[length][length];
    cout << "Enter the array elements: ";
    for(int i = 0; i < length; i++){
            for(int j = 0;j < length;j++){
                    cin >> matrix[i][j];}

    }
    int primary_diag = 0;
    int secondary_diag = 0;
    for(int i = 0; i < length; i++){
            for(int j = 0;j < length;j++){
                    if (i==j && (i + j) == length-1){
                        primary_diag = primary_diag + matrix[i][j];
                        secondary_diag = secondary_diag + matrix[i][j];
                    }
                    else if(i == j){
                         primary_diag = primary_diag + matrix[i][j];
                    }

                     else if((i + j) == length - 1){
                     secondary_diag = secondary_diag + matrix[i][j];
                     }
            }

    }
    int diff  = abs(primary_diag - secondary_diag);
    cout <<"Difference between the diagonals of matrix: "<< diff;
}

