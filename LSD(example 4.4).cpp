/* Print the Least significant digit of a number
   written by: Smrity chaudhary
   Date : 22-12-17
*/
#include<iostream>
using namespace std;
//Prototype declaration
int first_digit(int);

int main(){
  int number;
  cout << "Enter a number: ";
  cin >> number;
  int LSD = first_digit(number);
  cout << "\nLeast Significant digit is: " << LSD;
  return 0;
}
// This function extract the least significant digit of an integer
int first_digit(int num){
  return (num % 10);
}
