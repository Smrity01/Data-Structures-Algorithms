#include<iostream>
using namespace std;
int sum_array(int user_array[],int size){
	/*
	Objective		  :To find the sum of an array 
	input parameter:
			user_array: user entered array
			size 	  : Size of the array
	Return value	  :The sum of elements of an array
	*/
    int sum = 0;
	for (int i = 0;i < size; i++){
		sum = sum + user_array[i];
	}
	return sum;
}
int main(){
	/*
	Objective		  :To take input from user 
	input parameter   :none 
	output value	  :Print the sum of elements of an array
	*/
    int size;
	cout << "Enter the size of the array: ";
	cin >> size;
	int user_array[size];
	for (int i = 0; i < size; i++){
		cout << "Enter the element in the array: ";
		cin >> user_array[i];
	}
	int sum ;
	sum = sum_array (user_array,size);
	cout << "\n Sum of elements of the array is : " << sum;
	
}