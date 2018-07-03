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
  rotate(arr,size,elements);
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
  Approach        :
  */
  int temp;
  int index;
  for(int i=0;i<elements;i++){
    index = i;
    while(index < size-elements)
    temp = arr[index];
    arr[index] = arr[index+elements];
    arr[index+elements] = temp;
    index = index+elements;
  }
  return 0;
}
