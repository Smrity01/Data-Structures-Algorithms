/*Add last two digits of a number
   written by: Smrity chaudhary
   Date : 22-12-17
*/
#include<iostream>
using namespace std;
//Prototype declaration
int first_digit(int);
int second_digit(int);
int add_two_digit(int);

int main(){
  int number;
  cout << "Enter a number: ";
  cin >> number;
  int sum = add_two_digit(number);
  cout << "\nSum of Last two digits is: " << sum;
  return 0;
}
// This function Add last two digits of an integer
int add_two_digit(int num){
  int sum = first_digit(num) + second_digit(num);
  return sum;
}
// This function extract the least significant digit of an integer
int first_digit(int num){
  return (num % 10);
}
// This function extract the second least significant digit of an integer
int second_digit(int num){
  return ((num / 10) % 10);
}
