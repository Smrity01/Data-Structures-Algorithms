/*
Order of matrix multiplication using Dynamic Programming
written By : Smrity Chaudhary
    Dated  : 03/10/2018
*/
#include<iostream>
#include<vector>
using namespace std;

int matrixmultiplication(vector<int>);
int main(){
  /*
  Objective       : To take input from user and call matrixmultiplication function
  Input Parameter : None
  Output value    : None
  Description     : Main function of the Programming
  Approach        : take dimensions of matrices in a vector data structure
  */
  char choice = 'y';
  vector<int> dimensions;
  while(choice == 'y'){
    int dim;
    cout << "Enter dimensions of the matrix: ";
    cin >> dim;
    dimensions.push_back(dim);
    cout << "Do you want to Enter more(y/n): ";
    cin >> choice;
  }
  matrixmultiplication(dimensions);
}
int matrixmultiplication(vector<int> dim){
  /*
  Objective       :  To find the minimum cost of matrix multiplication and order
                     of paranthesis
  Input Parameter : Dimensions of matrices in vector
  Output Value    : Cost of matrix multiplication
  Description     : Calculate the minimum cost of matrix chain multiplication
  Approach        : Cost will be calculated diagonally (upper diagonal) using
                    two for loop(d and i) and internally a for loop (K) to track
                    the correct position of paranthesis.
  */
  int size = dim.size()-1;
  int cost[size][size];

  for (int i=0;i<size;i++){
    for (int j=0;j<size;j++){
      if (i==j){
        cost[i][j]=0;
      }
    else{
    cost[i][j] = 999;
      }
    }
  }
  for (int d=0;d<size;d++){
    for (int i=0;i<size;i++){
      int j = i + d;
        for (int k=i;k<j;k++){
          int temp = cost[i][k] + cost[k+1][j] + (dim[i]*dim[k+1]*dim[j+1]);
          if(temp < cost[i][j]){
            cost[i][j] = temp;
          }
        }
      }
    }
  cout << "cost are: \n";
  for (int i=0;i<size;i++){
  for (int j=0;j<size;j++){
    cout << cost[i][j] << " ";
  }
  cout<<"\n";
 }
}
