/*
Rotation of elements in the array
Written by : Smrity Chaudhary
    Dated  : 06/07/2018
*/
#include<iostream>
using namespace std;

int rotate(int arr[],int size,int elements);
int main(){
  /*
  Objective       : Main function of program
  Input Parameter : None
  Output Value    : Output messages
  Approach        : Call 'rotate' function and take input
  */
  int size;
  int elements;
  cout << "\nEnter size of array: ";
  cin >> size;
  int arr[size];
  cout << "\nEnter elements in the array..";
  for(int i = 0 ;i < size;i++){
    cin >> arr[i];
  }
  cout << "By how many elements you want to rotate: ";
  cin >> elements;
  if (size>elements){
  	rotate(arr,size,elements);
  }
  else{
  	cout << "\nNot possible";
  }
  cout << "\narray: ";
  for(int i = 0 ;i < size;i++){
    cout << arr[i] << ",";
  }
  return 0;
}
int rotate(int arr[],int size,int elements){
  /*
  Objective       : To rotate elements of array
  Input Parameter : Array and count of element that need to be rotated
  Output Value    : Output messages
  Approach        : using another temporary array
  */
  int temp_arr[elements];
  for(int i = 0;i<elements;i++){
    temp_arr[i] = arr[i];
  }
  for(int i = 0;i<size;i++){
    if(i<size-elements){
      arr[i] = arr[i+elements];
    }
    else{
      arr[i] = temp_arr[i-(size-elements)];
    
	}
  }
  return 0;
}
