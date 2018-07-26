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
                    Insertion sort function
  */
  int size;
  cout << "Enter the size of array: ";
  cin >> size;
  int arr[size];
  srand(time(NULL));
  int num;
  for(int i = 0;i<size; i++){
    num = rand() % size;
	  arr[i] = num;
  }
  insertion_sort(arr,size);
  for(int i = 0;i<size; i++){
    cout <<arr[i] << ",";
  }
}

int insertion_sort(int arr[],int size){
  /*
  Objective       : Sort element in the array
  Input Parameters: array in which elements are stored
                    size   : Size of the array
  Output Value    : None
  Description     : Function of program
  Approach        : Each element from beginning placed to its correct position
                    in the first half sorted array using a for and a while loop.
  */

  for(int k=0;k<size;k++){
      int index = k;
      while(arr[index-1] > arr[index] && index > 0){
        int temp = arr[index];
        arr[index] = arr[index-1];
        arr[index-1] = temp;
        index--;
    }
  }
  return 0;
}
