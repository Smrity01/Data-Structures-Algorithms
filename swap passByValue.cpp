/*Swap two numbers using pass by value
   written by: Smrity chaudhary
   Date : 22-12-17
*/
#include<iostream>
using namespace std;
//Prototype declaration
void swap_num(int,int);

int main(){
  int number1;
  int number2;
  cout << "Enter first number: ";
  cin >> number1;
  cout << "Enter second number: ";
  cin >> number2;
  swap_num(number1,number2);
  cout << "\n\n...........Does not reflect the changes in MAIN because parameters are passed by value...............  ";
  cout << "\nyour first number is: " << number1;
  cout << "\nyour second number is: " << number2;
  return 0;
}
// This function Swap the values of two variables.......
void swap_num(int num1,int num2){
  int temp;
  temp = num1;
  num1 = num2;
  num2 = temp;
  cout << "\n...........Reflect the changes in SWAP_NUM......... \n ";
  cout << "\nyour first number is: " << num1;
  cout << "\nyour second number is: " << num2;
  return ;
}
