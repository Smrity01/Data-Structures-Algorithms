/*
Insertion sort algorithm
Written by: Smrity Chaudhary
     Dated: 26-07-2018
*/
#include<iostream>
#include<cstdlib>
#include<time.h>
using namespace std;

int insertion_sort(int arr[],int size);
int main(){
  /*
  Objective       : Take User input And create an array with random numbers
  Input Parameters: None
  Output Value    : None
  Description     : Main Function of the program
  Approach        : Random number are generated and inserted into array and call
                    linear search function
  */
  int size;
  cout << "Enter the size of array: ";
  cin >> size;
  int arr[size];
  srand(time(NULL));
  int num;
  for(int i = 0;i<size; i++){
    num = rand() % size;
    cout << "\n"<<num;
	arr[i] = num;
  }
}

int insertion_sort(int arr[],int size){
  /*
  Objective       : Search element in the array
  Input Parameters: array in which elements are stored
                    element: that element need to be search
                    size   : Size of the array
  Output Value    : Message whether element found or not
  Description     : Function of program
  Approach        : Sequentially search the element in the array using for loop
  */

  return 0;
}
