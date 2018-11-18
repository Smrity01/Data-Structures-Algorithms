/*
Complexity Order of matrix multiplication using Dynamic Programming
written By : Smrity Chaudhary
    Dated  : 28/10/2018
*/
#include<iostream>
#include<vector>
#include<cstdlib>
#include<ctime>
#include<fstream>
using namespace std;

void fill_dimensions(int);
void matrix_multiplication(vector<int>);
void write_in_file(int,int);
int **order;
int main(){
  /*
  Objective       : To take input from user and call matrix multiplication function
  Input Parameter : None
  Output value    : None
  Description     : Main function of the Programming
  Approach        : take dimensions of matrices in a vector data structure
  */
  srand(time(NULL));
  int no_matrices;
  int counter = 5;
  while(counter != 0){
        int n = (rand()%100)+1;
        //cout << "\n"<<n << "\n";
        fill_dimensions(n+1);
        counter--;
  }

}
void fill_dimensions(int n){
    vector<int> dimensions;
    int value;
    while(n!=0){
            value = (rand()%10)+1;
            //cout << value <<"\n";
            dimensions.push_back(value);
            n--;
    }
    cout << endl <<dimensions.size();
    matrix_multiplication(dimensions);
}
void matrix_multiplication(vector<int> dim){
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
  int loop_count = 0;
  int dim_size = dim.size()-1;
  int cost[dim_size][dim_size];
  order = new int *[dim_size];
  for(int i=0;i<dim_size;i++)
    order[i] = new int[dim_size];
  /*
  Order Matrix represents the order of paranthesis in which
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

      // Initialisation Of Order Matrix
      order[i][j] = 0;
    }
    }

    int a = 0;
    int b = 1;
    int i = a;
    int j = b;
  while(b<dim_size){

      for (int k=i;k<j;k++){
        loop_count++;
        int temp = cost[i][k] + cost[k+1][j] + (dim[i]*dim[k+1]*dim[j+1]);
        if(temp < cost[i][j]){
          cost[i][j] = temp;

          // Updataing Order of paranthesis, according to Minimum cost
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
    cout << "\nloop count: " << loop_count;
    write_in_file(dim.size(),loop_count);
}
void write_in_file(int num_matrices, int loop_count){
    ofstream data_file;
    data_file.open("matrix_data.csv",ios::app);
    data_file<< num_matrices << "," << loop_count << endl;
}
