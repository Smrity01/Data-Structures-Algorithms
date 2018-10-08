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
  Approach        : Cost will be calculated diagonally (upper diagonal) using a
                    while loop and internally a for loop (K) to track the right
                    position of paranthesis.

  */
  int size = dim.size()-1;
  int cost[size][size];

  int order[size][size];

  /*
  Order Matrix represents the order of paranthesis in which
  each subproblem is solved.It is also evaluated in Diagonal
  Manner.
  */

  for (int i=0;i<size;i++){
    for (int j=0;j<size;j++){
      if (i==j){
        cost[i][j]=0;
      }
    else{
    cost[i][j] = 999;
      }

      // Initialisation Of Order Matrix
      order[i][j] = 0;
    }
    }

    int a = 0;
    int b = 1;
    int i = a;
    int j = b;
  while(b<size){

      for (int k=i;k<j;k++){
        int temp = cost[i][k] + cost[k+1][j] + (dim[i]*dim[k+1]*dim[j+1]);
        if(temp < cost[i][j]){
          cost[i][j] = temp;

          // Updataing Order of paranthesis, according to Minimum cost
          order[i][j] = k+1;
        }
      }
      i = i+1;
      j = j+1;
      if(j == size){
        b = b+1;
        i = a;
        j = b;
      }
    }

    /*
      cout << "Order are: \n";
      for (int i=0;i<size;i++){
    for (int j=0;j<size;j++){
      cout << order[i][j] << " ";
      }
      cout << "\n";
      }

    cout << "cost are: \n";
   for (int i=0;i<size;i++){
    for (int j=0;j<size;j++){
    cout << cost[i][j] << " ";
    }
    cout<<"\n";
  }
    */

    // Minimum Cost is given cost[0][size-1] Value
    cout << "\n The Minimum Cost required to multiply "<<size
         <<" matrices is : "<<cost[0][size-1] << "\n";

    // Represents the order of the paranthesis :

    cout << " The Order of paranthesis is : ";
    for(int i=size-1;i>=2;i--)
        cout << order[0][i] <<"  ";

    /*
    Example :

    If the output of Order Of paranthesis for 5 Matrices is :
    4 3 1 : it is interpreted as :

    let say, Matrices be : A1 A2 A3 A4 A5

    Order of A1 : 1 X 2
    Order of A2 : 2 X 2
    Order of A3 : 2 X 1
    Order of A4 : 1 X 1
    Order of A5 : 1 X 3

    Order of paranthesis :
        First  - 4: (A1 A2 A3 A4) A5
        Second - 3: ((A1 A2 A3) A4) A5
        Third  - 1: ((A1 (A2 A3)) A4) A5
    */

}
