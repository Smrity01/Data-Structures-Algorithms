/*
Order of matrix multiplication using Dynamic Programming
written By : Smrity Chaudhary
    Dated  : 03/10/2018
*/
#include<iostream>
#include<vector>
using namespace std;

int **order;
void optimalparenthesis(int i,int j);
int matrixmultiplication(vector<int>);
int main(){
  /*
  Objective       : To take input from user and call matrix multiplication function
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
  if(dimensions.size()==1){
    cout << "\nAtleast enter dimensions for 1 matrix..";
  }
  else{
        matrixmultiplication(dimensions);
  optimalparenthesis(0,dimensions.size()-2);
  }
}

int matrixmultiplication(vector<int> dim){
  /*
  Objective       :  To find the minimum cost of matrix multiplication and order
                     of parenthesis
  Input Parameter : Dimensions of matrices in vector
  Output Value    : Cost of matrix multiplication
  Description     : Calculate the minimum cost of matrix chain multiplication
  Approach        : Cost will be calculated diagonally (upper diagonal) using a
                    while loop and internally a for loop (K) to track the right
                    position of parenthesis.

  */
  int dim_size = dim.size()-1;
  int cost[dim_size][dim_size];
  order = new int *[dim_size];
  for(int i=0;i<dim_size;i++)
    order[i] = new int[dim_size];
  /*
  Order Matrix represents the order of parenthesis in which
  each subproblem is solved.It is also evaluated in Diagonal
  Manner.
  */

  for (int i=0;i<dim_size;i++){
    for (int j=0;j<dim_size;j++){
      if (i==j){
        cost[i][j]=0;
      }
    else{
    cost[i][j] = 999;
      }

      // Initialization Of Order Matrix
      order[i][j] = 0;
    }
    }

    int a = 0;
    int b = 1;
    int i = a;
    int j = b;
  while(b<dim_size){

      for (int k=i;k<j;k++){
        int temp = cost[i][k] + cost[k+1][j] + (dim[i]*dim[k+1]*dim[j+1]);
        if(temp < cost[i][j]){
          cost[i][j] = temp;

          // Updating Order of parenthesis, according to Minimum cost
          order[i][j] = k;
        }
      }
      i = i+1;
      j = j+1;
      if(j == dim_size){
        b = b+1;
        i = a;
        j = b;
      }
    }
/*
    cout << "Order are: \n";
    for (int i=0;i<dim_size;i++){
            for (int j=0;j<dim_size;j++){
                cout << order[i][j] << " ";
    }
    cout << "\n";
    }

   cout << "cost are: \n";
   for (int i=0;i<dim_size;i++){
    for (int j=0;j<dim_size;j++){
    cout << cost[i][j] << " ";
    }
    cout<<"\n";
  }
*/
    // Minimum Cost is given cost[0][size-1] Value
    cout << "\n The Minimum Cost required to multiply "<<dim_size
         <<" matrices is : "<<cost[0][dim_size-1] << "\n";

    // Represents the order of the parenthesis :

    cout << " The Order of parenthesis is : ";
    for(int i=dim_size-1;i>=2;i--)
        cout << order[0][i] <<"  \n";

    /*
    Example :

    If the output of Order Of parenthesis for 5 Matrices is :
    4 3 1 : it is interpreted as :

    let say, Matrices be : A1 A2 A3 A4 A5

    Order of A1 : 1 X 2
    Order of A2 : 2 X 2
    Order of A3 : 2 X 1
    Order of A4 : 1 X 1
    Order of A5 : 1 X 3

    Order of parenthesis :
        First  - 4: (A1 A2 A3 A4) A5
        Second - 3: ((A1 A2 A3) A4) A5
        Third  - 1: ((A1 (A2 A3)) A4) A5
    */

}
void optimalparenthesis(int i,int j){
    if(i==j){
        cout <<  " A" << i+1;
    }
    else{
        cout << "(";
        optimalparenthesis(i,order[i][j]);
        optimalparenthesis((order[i][j])+1,j);
        cout << ")";
    }
}
