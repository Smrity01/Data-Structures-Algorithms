#include<iostream>
using namespace std;

/////////////////REVERSE FUNCTION///////////////////////
int reverse(int my_array[],int size){
  /*
  Objective		  :To reverse the given array
  input parameter :
        user_array: user entered array
		size 	  : Size of the array
  Return value	  :none
  */
  int temp;
  int j = size-1;
  for (int i=0 ; i<(size/2); i++){
    temp = my_array[i];
    my_array[i] = my_array[j];
    my_array[j] = temp;
    j = j-1;
  }
  return 0;
}
/////////////////MAIN FUNCTION///////////////////////
int main(){
  /*
	Objective		  :To take input from user and call reverse function
	input parameter   :none
	output value	  :Print the reversed array
  */
  int size;
  cout << "Enter the size of your array: ";
  cin >> size;
  int user_array[size];

  cout << "\n Enter the elements in the array: ";
  for (int i=0 ; i<size; i++){
    cin >> user_array[i];
  }
  reverse(user_array,size);
  cout << "\n Reversed array: ";
  for (int i=0 ; i<size; i++){
    cout << user_array[i] << " ";
   }
}
