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
  int size = dim.size()-1;
  int cost[size][size] = { {0,0} };

  cout << "cost are: ";
  for (int i=0;i<size;i++){
    for (int j=0;j<size;j++){
      cout << cost[i][j] << " ";
    }
    }
  for (int i=0;i<size;i++){
    for (int j=0;j<size;j++){
      if(i<j){
        for (int k=i;k<j;k++){
          int temp = cost[i][k] + cost[k+1][j] + (dim[i]*dim[k+1]*dim[j+1]);
          if(temp < cost[i][j]){
            cost[i][j] = temp;
          }
        }
	  }
      }
    }
}
  

