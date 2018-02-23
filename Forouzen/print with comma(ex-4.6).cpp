/*Read long integer and print with comma
   written by: Smrity chaudhary
   Date : 22-12-17
*/
#include<iostream>
#include<iomanip>
using namespace std;
//Prototype declaration
void print_comma(long);

int main(){
  long number;
  cout << "Enter a number: ";
  cin >> number;
  print_comma(number);
  return 0;
}
// This function divides the number into two parts thousands and hundreds an print them with comma.......
void print_comma(long num){
  float first = num / 1000;
  float last = num % 1000;
  cout << "\n The number is: " << setw(3) << first << "," << setfill('0') << setw(3) << last;
  return ;
}
